#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef unsigned short int UINT16;
typedef unsigned       int UINT32;
typedef unsigned long  int UINT64;

void print_help(){
    printf("Correct usage: <program> <target> [args...]\n");
}

int main(int argc, char *argv[])
{

    if(argc < 2){
        print_help();
        return 1;
    }


    

    pid_t parent = getpid();

    printf("Fork PID: %d\n", (int)parent);

    pid_t pid = fork();


    if(pid == -1){
        printf("CRITICAL ERROR: forking failed.\n");
        return 1;
    }
    else if(pid > 0){
        int status;
        waitpid(pid, &status, 0);
    }
    else {
        execv(argv[1], (char * const *)&argv[1]);
        printf("CRITICAL ERROR: execv failed.\n");
    }


    

    return 0;
}
