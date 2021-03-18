#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Definindo "semaforos" (mutex)
pthread_mutex_t table;

// Filosófos
#define NUMBER_OF_PHILO 5
pthread_mutex_t FORKS[NUMBER_OF_PHILO];

// Definindo estados do programa
#define THINKING 0
#define HUNGRY 1
#define EATING 2

typedef int STATE;

STATE PHILOSOPHERS_STATE[NUMBER_OF_PHILO];

const clock_t MAXDELAY = 2000000;

void delay(clock_t ticks)
{ /* a "busy" delay */
  clock_t start = clock();
  do
    ;
  while (clock() < start + ticks);
}

// Pegando os índices dos filosófos da esquerda e direita
int getLeftIndex(int i)
{
  return (i + NUMBER_OF_PHILO - 1) % NUMBER_OF_PHILO;
}

int getRightIndex(int i)
{
  return (i + 1) % NUMBER_OF_PHILO;
}

// Ver se o filosófo pode comer
void canTakeForks(int i)
{
  if ((PHILOSOPHERS_STATE[i] == HUNGRY) &&
      (PHILOSOPHERS_STATE[getLeftIndex(i)] != EATING) &&
      (PHILOSOPHERS_STATE[getRightIndex(i)] != EATING))
  {
    printf("%d° PEGOU OS GARFOS \n", i);
    printf("%d° COMENDO\n\n", i);
    PHILOSOPHERS_STATE[i] = EATING;
    pthread_mutex_unlock(&FORKS[i]);
  }
}

// Pegando os garfos
void take_forks(int i)
{
  pthread_mutex_lock(&table);
  printf("%d° TENTOU PEGAR OS GARFOS \n", i);
  PHILOSOPHERS_STATE[i] = HUNGRY;

  canTakeForks(i);

  pthread_mutex_unlock(&table);
  pthread_mutex_lock(&FORKS[i]); // Espera os garfos
}

// Liberando os garfos
void put_fork(int i)
{
  pthread_mutex_lock(&table);
  if (PHILOSOPHERS_STATE[i] == EATING)
    printf("%d° TERMINOU DE COMER \n", i);
  PHILOSOPHERS_STATE[i] = THINKING;
  printf("%d° PENSANDO \n", i);

  canTakeForks(getLeftIndex(i));
  canTakeForks(getRightIndex(i));

  pthread_mutex_unlock(&table);
}

void eat(int i)
{
  delay(MAXDELAY);
}

void think(int i)
{
  delay(MAXDELAY * 2);
}

void *philosopher(int i)
{
  while (1)
  {
    think(i);
    take_forks(i);
    eat(i);
    put_fork(i);
  }
  pthread_exit(0);
}

int main(int argc, char **argv)
{
  pthread_t philo[NUMBER_OF_PHILO];

  // Semáforos (mutex)
  pthread_mutex_init(&table, NULL);
  for (int k = 0; k < NUMBER_OF_PHILO; k++)
    pthread_mutex_init(&FORKS[k], NULL);

  // Threads
  for (int k = 0; k < NUMBER_OF_PHILO; k++)
    pthread_create(&philo[k], NULL, philosopher, k);

  for (int k = 0; k < NUMBER_OF_PHILO; k++)
    pthread_join(philo[k], NULL);

  for (int k = 0; k < NUMBER_OF_PHILO; k++)
    pthread_mutex_destroy(&FORKS[k]);

  pthread_mutex_destroy(&table);
}