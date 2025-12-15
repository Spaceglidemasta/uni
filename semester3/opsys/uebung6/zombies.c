#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void) {
    int pid = fork();

    if (pid > 0) {
        printf("Parent PID: %d\n", getpid());
        sleep(20);
    } 
    else {
        printf("Child PID: %d\n", getpid());
        printf("Child exits.\n");
        exit(0);
    }
    return 0;
}
