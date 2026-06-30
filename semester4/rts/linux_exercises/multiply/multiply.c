#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    
    if(argc != 4){
        printf("Invalid Number of Arguments passed: %d, should be 4", argc);
        return 1;
    }

    int a = atoi(argv[2]);
    int b = atoi(argv[3]);

    printf("%s %d * %d = %d", argv[1], a, b, a * b);

    return 0;
}
