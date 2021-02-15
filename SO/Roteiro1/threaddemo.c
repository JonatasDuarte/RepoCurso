/* threaddemo.c */
/* Thread demonstration program. Note that this program uses a shared variable
   in an unsafe manner (eg mutual exclusion is not attempted!) */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

const clock_t MAXDELAY = 2000000;

void delay(clock_t ticks) { /* a "busy" delay */
  clock_t start = clock();
  do
    ; while (clock() < start + ticks);
}

void * adjustX(void *n)
{  int i = (int)n;
   int x = 50;   /* a global (shared) variable */
   while (1)   /* loop forever */
    {   printf("adjustment = %2i; x = %i\n", i, x);
        x += i;
        delay(rand()%MAXDELAY);
   }
   return(n);
}

void main()
{  int a;
   srand(time(NULL));
   pthread_t  up_thread, dn_thread;

   pthread_attr_t *attr;  /* thread attribute variable */
   attr=0;  

   printf("creating threads:\n");
   pthread_create(&up_thread,attr, adjustX, (void *)1);
   pthread_create(&dn_thread,attr, adjustX, (void *)-1);

  
   while (1) /* loop forever */
   { ;}
}
