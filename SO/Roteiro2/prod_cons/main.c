#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#define MAX 1000000000
pthread_mutex_t the_mutex;
pthread_cond_t condc, condp;
int buffer = 0;

const clock_t MAXDELAY = 2000000;

void delay(clock_t ticks) { /* a "busy" delay */
  clock_t start = clock();
  do
    ; while (clock() < start + ticks);
}

void *producer(void *ptr) {
    int i;

    /* usado para sinalizacao */
    /* buffer usado entre produtor e consumidor */
    /* dados do produtor */
    for (i = 1; i <= MAX; i++) {
		/* Produção */ 
        pthread_mutex_lock(&the_mutex); /* obtem acesso exclusivo ao buffer */
        while (buffer == 5)
            pthread_cond_wait(&condp, &the_mutex);
			
        printf("Colocando o item %d no buffer (+)\n", i);
		/* Incrementando nosso buffer */
        buffer++; /*coloca item no buffer */
		pthread_mutex_unlock(&the_mutex);/* libera acesso ao buffer */
		
		/* Vamos acordar o connsumidor após produzir todos os itens no buffer */
		if(buffer == 5){
			pthread_cond_signal(&condc); /* acorda consumidor */
        }
		
		delay(MAXDELAY);
    }

    pthread_exit(0);
}

void *consumer(void *ptr) {
    int i;

    /* quantos numeros produzir */
    /* dados do consumidor */
    for (i = 1; i <= MAX; i++) {
        pthread_mutex_lock(&the_mutex); /* obtem acesso exclusivo ao buffer */
        while (buffer < 5) 
		/* Chamar o produtor quando consumir um item */
			pthread_cond_wait(&condc, &the_mutex);
			
        printf("Retirando item %d no buffer (-)\n", i);
		/* Decrementando item no buffer */
		buffer--; /* retira o item do buffer */
		
        /* acorda o produtor */
        pthread_cond_signal(&condp);
        pthread_mutex_unlock(&the_mutex);/* libera acesso ao buffer */
		
		delay(MAXDELAY);
    }
    pthread_exit(0);

}

int main(int argc, char **argv)
{
    pthread_t pro, con;
    pthread_mutex_init(&the_mutex, 0);
    pthread_cond_init(&condc, 0);
    pthread_cond_init(&condp, 0);
    
    /* Trocando as posições para ver se alterava o resultado */
	pthread_create(&pro, 0, producer, 0);
	pthread_create(&con, 0, consumer, 0);
	
	
    pthread_join(pro, 0);
    pthread_join(con, 0);
    pthread_cond_destroy(&condc);
    pthread_cond_destroy(&condp);
    pthread_mutex_destroy(&the_mutex);
}