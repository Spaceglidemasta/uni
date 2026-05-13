#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

int pseudo(){
    int a;

    printf("Geben Sie ein Wert für \"a\" an: ");
    scanf("%d", &a);

    if(a > 0){

        for(int i = 0; i < a; i++){

            for(int j = 0; j <= i; j++){
                printf("*");
            }
            printf("\n");
        }
    }
}



int randtext(){
    srand(time(NULL));

    int max = 256;
    int min = 0;


    for(int i = 0; 1 ; i++){
        char ranchar = (char)((rand() % 94) + 33);

        printf("%c",ranchar);

        
        int delay = ((rand() % 100) + 10);
        Sleep(delay);
    }

}



int main()
{
    pseudo();

    return 0;
}
