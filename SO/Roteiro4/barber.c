#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define QTDE_CADEIRAS 1
#define QTDE_CLIENTES 3

const clock_t MAXDELAY = 2000000;

int clientes_esperando = 0; // Variável compartilhada

pthread_t barbeiro, clientes[QTDE_CLIENTES];

// Semaforo
pthread_cond_t condBarbeiro;
// Mutex
pthread_mutex_t the_mutex;

void delay(clock_t ticks)
{ // Delay com espera ocupada
    clock_t start = clock();
    do
        ;
    while (clock() < start + ticks);
}

void corta_cabelo(int n)
{
    printf("%d° cliente está cortando o cabelo\n", n + 1);
    delay(MAXDELAY);
    printf("%d° cliente terminou de cortar o cabelo\n", n + 1);
}

void *cliente_t(int num_cliente)
{
    pthread_mutex_lock(&the_mutex); // Entra na região crítica
    if (clientes_esperando < QTDE_CADEIRAS)
    {
        clientes_esperando++;
        printf("%d° cliente está esperando...\n", num_cliente + 1);

        pthread_cond_wait(&condBarbeiro, &the_mutex);
        printf("%d° cliente foi chamado pra cortar o cabelo\n", num_cliente + 1);
        corta_cabelo(num_cliente);
    }
    else
    {
        // Sai da região crítica
        printf("%d° cliente saiu sem cortar o cabelo\n", num_cliente + 1);
    }
    pthread_mutex_unlock(&the_mutex); // Sai da região crítica
    pthread_exit(0);
}

void *barbeiro_t(void *n)
{
    while (1)
    {
        pthread_mutex_lock(&the_mutex); // Barbeiro entra na região crítica
        if (clientes_esperando > 0)
        {
            clientes_esperando--;
            pthread_cond_signal(&condBarbeiro); // Barbeiro chama algum cliente
        }
        pthread_mutex_unlock(&the_mutex); // Barbeiro sai da região crítica
    }
    pthread_exit(0);
}

int main(int argc, char **argv)
{
    int e, st;
    pthread_attr_t attr;      //data structure for managing thread attributes
    pthread_attr_init(&attr); //initialise thread attribute data ...
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);

    // Iniciando Mutex
    pthread_mutex_init(&the_mutex, NULL);

    // Iniciando semáforos
    pthread_cond_init(&condBarbeiro, 0);

    if (e = pthread_create(&barbeiro, &attr, barbeiro_t, NULL) != 0)
    {
        printf("Thread create error %d\n", e);
        exit(-1);
    }

    for (int t = 0; t < QTDE_CLIENTES; t++)
    { // create several worker thread instances

        if (e = pthread_create(&clientes[t], &attr, cliente_t, t) != 0)
        {
            printf("Thread create error %d\n", e);
            exit(-1);
        }
    }

    pthread_attr_destroy(&attr); // Destrói o objeto de atributos

    pthread_join(barbeiro, (void **)&st);
    // Faz join em todas as threads
    for (int t = 0; t < QTDE_CLIENTES; t++)
    { //wait for each worker thread to join
        if (e = pthread_join(clientes[t], (void **)&st) != 0)
        {
            exit(-1);
        }
    }
}