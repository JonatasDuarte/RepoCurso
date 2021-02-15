#include <unistd.h>
#include <stdio.h>

int main (void) {
        pid_t p; /* fork returns type pid_t */
        p = fork();
        printf("fork returned %d\n", p);
	while (1); // Infinite loop to keep the process alive
}
