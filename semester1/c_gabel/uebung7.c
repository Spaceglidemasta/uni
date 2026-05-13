#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "my_math_functions.h"



int randomcalc(int times){

    srand(time(NULL));

    int max = 9;
    int min = 0;

    for(int i = 0; i < times; i++){

        int randomop = rand() % 4;

        int a = rand() % 9;
        int b = rand() % 9;

        switch (randomop)
        {
        case 0:
            printf("%d + %d = %d",a ,b , a + b);
            break;

        case 1:
            printf("%d - %d = %d",a ,b , a - b);
            break;

        case 2:
            printf("%d * %d = %d",a ,b , a * b);
            break;

        case 3:
            
            if(b == 0){
                printf("%d / %d = Math Error, division by 0 not possible.", a, b);
            }
            else{
                printf("%d / %d = %d",a ,b , a / b);
            }

            break;
        
        default:
            printf("wtf");
            break;

        }

        printf("\n");
    }

    return 0;
}

void printnum(char c){

    switch (c){
    case '0':
        printf("Null ");
        break;
    case '1':
        printf("Eins ");
        break;
    case '2':
        printf("Zwei ");
        break;
    case '3':
        printf("Drei ");
        break;
    case '4':
        printf("Vier ");
        break;
    case '5':
        printf("Fünf ");
        break;
    case '6':
        printf("Sechs ");
        break;
    case '7':
        printf("Sieben ");
        break;
    case '8':
        printf("Acht ");
        break;
    case '9':
        printf("Neun ");
        break;
    
    default:
        break;
    }

    
}


int rekstrnum(){

    printf("\n");

    long int inum;
    char *numstr;
    
    printf("Geben Sie einen Zahl an, die vorgelesen werden soll (-1 zum beenden): ");
    scanf(" %ld", &inum);

    // Exit condition
    if(inum == -1){
        return 0;
    }

    //Get length of input, +1 for nullterm
    //allocate memory for the numstr
    //input to string
    int numstrlen = snprintf(NULL, 0, "%d", inum) + 1;
    numstr = (char *)malloc(numstrlen * sizeof(char));
    sprintf(numstr, "%d", inum);

    for(int i = 0; i < strlen(numstr); i++){
        printnum(numstr[i]);
    }

    free(numstr);
    return rekstrnum();
}




int sekrek(int con){

    printf("\n");
    
    char in;

    if(con == 1){
        printf("Geben Sie einen Zahl an, die vorgelesen werden soll (-1 zum beenden): ");
        scanf(" %c", &in);
    }

    printf("%c\n", in);

    return sekrek(0);



}





int main()
{
    
    randomcalc(30);
    sekrek(1);

    printf("\n\n");
    return 0;
}
