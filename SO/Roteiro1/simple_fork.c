#include <unistd.h>
#include <stdio.h>

int main (void) {
        pid_t p; /* fork returns type pid_t */
        p = fork();
        printf("fork returned %d\n", p);
}
