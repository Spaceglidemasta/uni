#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>


void printIntArray(int* array, int n){

    for (int i = 0; i < n; i++)
    {
        if(i > 9){
            printf("array[%d] = %d\n", i, array[i]);
        }
        else{
            printf("array[%d]  = %d\n", i, array[i]);
        }
    }
}


void bubblesort(){

    const int n;
    int input;
    int sotiert = 0;
    int first;
    int second;


    printf("Geben Sie die Größe des Arrays an: ");
    scanf("%d",&n);

    int* array = (int*)malloc(sizeof(int)*n);

    for(int i = 0; i < n; i++){
        printf("array[%d] = ", i);
        scanf("%d",&input);
        array[i] = input;
    }

    while(!sotiert){
        sotiert = 1;

        for(int i = 1; i < n; i++){
            first = array[i - 1];
            second = array[i];

            if(first > second){
                array[i - 1] = second;
                array[i] = first;
                sotiert = 0;
            }
        }
    }


    //output
    printf("Array content:\n");
    for (int i = 0; i < n; i++)
    {
        if(i > 9){
            printf("array[%d] = %d\n", i, array[i]);
        }
        else{
            printf("array[%d]  = %d\n", i, array[i]);
        }
    }
    
    free(array);
}

void geradeListelemente(int* array, int size){
    int counter = 0;
    
    for(int i = 0; i < size; i++){
        if(array[i] % 2 == 0){
            counter++;
        }
    }
    printf("Das array hat %d gerade Elemente.\n", counter);
}

void erstesElementMehrmals(int* array, int size){
    int element = array[0];

    for(int i = 1; i < size; i++){
        if(array[i] == element){
            printf("Das element %d ist mehrmals im array enthalten.\n", element);
            return;
        }
    }
    printf("Das element %d kommt nicht mehrmals im array vor.\n", element);
}

void größtesElement(int* array, int size){
    int größtesElement = array[0];

    for(int i = 1; i < size; i++){
        if(array[i] > größtesElement){
            größtesElement = array[i];
        }
    }
    printf("Das größte Element im array ist: %d\n", größtesElement);
}

void obAufsteigendSotiert(int* array, int size){
    int ist_sotiert = 1;

    for(int i = 1; i < size; i++){
        if(array[i] <= array[i - 1]){
            ist_sotiert = 0;
            break;
        }
    }

    if(ist_sotiert){
        printf("Das array ist sotiert.\n");
    }
    else{
        printf("Das array ist nicht sotiert.\n");
    }
}


int listOperationMenu(int* array, int n){

    int wahl;

    printf("\nMenu:\n");
    printf("-------------------------------------------------------|\n");
    printf("(1)----->  Die Anzahl gerade Listenelemente berechnen.\n");
    printf("(2)----->  Kommt das erste Listenelement ein weiteres mal vor?\n");
    printf("(3)----->  Das größte Element in der Liste bestimmen.\n");
    printf("(4)----->  Ist die Liste aufsteigend sotiert?\n");
    printf("(5)----->  Menu schliessen.\n");

    printf("Welche funktion wollen Sie ausführen?\n");
    scanf("%d",&wahl);

    switch (wahl)
    {
    case 1:
        geradeListelemente(array, n);
        return listOperationMenu(array, n);
    case 2:
        erstesElementMehrmals(array, n);
        return listOperationMenu(array, n);
    case 3:
        größtesElement(array, n);
        return listOperationMenu(array, n);
    case 4:
        obAufsteigendSotiert(array, n);
        return listOperationMenu(array, n);
    case 5:
        return 0;
    
    default:
        printf("Diese Operation ist nicht hinterlegt!");
        return listOperationMenu(array, n);
    }

}



int startMenu(){

    int input;
    int* array = (int*)malloc(sizeof(int));
    int weiter = 1;
    int n = 1;

    //first iteration
    printf("Bitte geben Sie ihr Array von postivien Zahlen an:\n(-1 to cancel)\narray[0] = ");
    scanf("%d",&input);
    array[0] = input;

    while(weiter){
        printf("array[%d] = ", n);
        scanf("%d", &input);
        if(input < 0){
            weiter = 0;
            printf("Ihr array ist nun fertig.\n");
        }
        else{
            n++;
            array = (int*)realloc(array, sizeof(int) * n);
            array[n - 1] = input;
        }
    }
    
    printf("----------------------------------------\n");
    listOperationMenu(array, n);

    free(array);
}


int main(){

    startMenu();

    return 0;
}



