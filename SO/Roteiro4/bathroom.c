#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Definindo tipos e estado
#define BOXES 3  // Quantidade de boxes no banheiro
#define PEOPLE 6 // Pessoas

#define EMPTY 0
#define WOMAN 1
#define MAN 2

typedef int STATE;

STATE bathroom_state = EMPTY;

int OCCUPIED_BOXES = 0;

// Definindo mutex e semaforos
pthread_mutex_t bathroom;
pthread_t people_threads[PEOPLE];

// pthread_cond_t
pthread_cond_t woman_leaves, man_leaves, empty_bathroom;

// Delay
const clock_t MAXDELAY = 2000000;

void delay(clock_t ticks)
{ // Delay com espera ocupada
  clock_t start = clock();
  do
    ;
  while (clock() < start + ticks);
}

// Homem entrando
void man_try_to_enter(int n)
{
  pthread_mutex_lock(&bathroom);
  switch (bathroom_state)
  {
  case MAN:
    // Ver se possui box livre
    if (OCCUPIED_BOXES < BOXES)
    {
      OCCUPIED_BOXES++;
    }
    // Esperando box ficar livre
    else
    {
      printf("%d° homem esperando na porta...\n", n + 1);
      pthread_cond_wait(&man_leaves, &bathroom);
    }
    break;
  case WOMAN:
    printf("%d° homem esperando na porta...\n\n", n + 1);
    pthread_cond_wait(&empty_bathroom, &bathroom);
    break;
  default:
    bathroom_state = MAN;
    OCCUPIED_BOXES++;
    break;
  }
  printf("%d° homem ocupando box\n", n + 1);
  pthread_mutex_unlock(&bathroom);
}

void man_exit(int n)
{
  pthread_mutex_lock(&bathroom);
  OCCUPIED_BOXES--;

  if (OCCUPIED_BOXES == 0)
    // Se não tiver ninguém no banheiro
    pthread_cond_broadcast(&empty_bathroom);
  else
    pthread_cond_signal(&man_leaves);

  pthread_mutex_unlock(&bathroom);
}

// Homem agindo
void *man(int n)
{
  printf("%d° homem querendo entrar\n", n + 1);
  man_try_to_enter(n);
  delay(MAXDELAY);
  printf("%d° homem saindo\n", n + 1);
  man_exit(n);
}

// Mulher entrando
void woman_try_to_enter(int n)
{
  pthread_mutex_lock(&bathroom);
  switch (bathroom_state)
  {
  case WOMAN:
    if (OCCUPIED_BOXES < BOXES)
      OCCUPIED_BOXES++;
    else
    {
      printf("%d° mulher esperando na porta...\n", n + 1);
      pthread_cond_wait(&woman_leaves, &bathroom);
    }
    break;
  case MAN:
    printf("%d mulher esperando na porta...\n\n", n + 1);
    pthread_cond_wait(&empty_bathroom, &bathroom);
    break;
  default:
    bathroom_state = WOMAN;
    OCCUPIED_BOXES++;
    break;
  }
  printf("%d° mulher ocupando box\n", n + 1);
  pthread_mutex_unlock(&bathroom);
}

// Mulher saindo
void woman_exit(int n)
{
  pthread_mutex_lock(&bathroom);
  OCCUPIED_BOXES--;
  if (OCCUPIED_BOXES == 0)
    pthread_cond_broadcast(&empty_bathroom);
  else
    pthread_cond_signal(&woman_leaves);
  pthread_mutex_unlock(&bathroom);
}

// Mulher agindo
void *woman(int n)
{
  printf("%d° mulher querendo entrar\n", n + 1);
  woman_try_to_enter(n);
  delay(MAXDELAY);
  printf("%d° mulher saindo\n", n + 1);

  woman_exit(n);
}

int main(int argc, char **argv)
{
  pthread_mutex_init(&bathroom, NULL);

  pthread_cond_init(&woman_leaves, NULL);
  pthread_cond_init(&man_leaves, NULL);

  for (int t = 0; t < PEOPLE; t++)
  {
    if (t % 2 == 0)
      pthread_create(&people_threads[t], NULL, woman, t);
    else
      pthread_create(&people_threads[t], NULL, man, t);
  }

  for (int t = 0; t < PEOPLE; t++)
    pthread_join(people_threads[t], NULL);
}