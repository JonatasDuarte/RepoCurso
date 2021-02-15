/* processdemo.c */
/* Process demonstration program. Note there are no shared variables */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/types.h>
#include <unistd.h>

const clock_t MAXDELAY = 2000000;
int x = 50;   /* a global variable */

void delay(clock_t ticks) { /* a "busy" delay */
  clock_t start = clock();
  do
     ; while (clock() < start + ticks);
}

void adjustX(char * legend, int i) {
    while (1)  /* loop forever */
    {   printf("%s: %i\n", legend, x);
         x += i;
         delay(rand()%MAXDELAY);
    }
}

void main(){
    int c;
    srand(time(NULL));
    printf("creating  new process:\n");
    c = fork();
    printf("process %i created\n", c);
    if (c==0) 
        adjustX("child", 1);    /* child process */
    else
        adjustX("parent", -1);  /* parent process */
}