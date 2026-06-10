#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[]) {

    printf("PID: %d\n", (int)getpid());
    for(int i = 0; i < argc; i++) {
        printf("Argument %d: %s\n", i, argv[i]);
    }
    return 0;
}