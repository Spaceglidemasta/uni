#include <stdio.h>
#include <stdlib.h>
#include <math.h>

char nums[10][10] = {"Null","Eins","Zwei","Drei","Vier","Fünf","Sechs","Sieben","Acht","Neun"};
char hnums[10][10] = {"Null","Ein","Zwei","Drei","Vier","Fünf","Sechs","Sieben","Acht","Neun"};
char zehner[8][10] = {
    "zwanzig", "dreißig", "vierzig", "fünfzig",
    "sechzig", "siebzig", "achtzig", "neunzig"
};


int digitFinder(int num){

    int scalar = 1;
    int counter = 0;

    while(scalar == scalar%num){
        scalar *= 10;
        counter++;
    }
    return counter;
}


void inWorten(int zahl){
    /*
    W = [-999,999]
    */

    
    //Test if negative and abs() if it is; for future calc
    if(zahl < 0){
        printf("Minus ");
        zahl = abs(zahl);
    }
    //1 digit
    if(zahl < 10){
        printf("%s",nums[zahl]);
    }
    //2 digit
    else if(zahl < 100){
        //special cases
        switch (zahl){
            case 10: printf("Zehn"); break;
            case 11: printf("Elf"); break;
            case 12: printf("Zwölf"); break;
            case 13: printf("Dreizehn"); break;
            case 14: printf("Vierzehn"); break;
            case 15: printf("Fünfzehn"); break;
            case 16: printf("Sechzehn"); break;
            case 17: printf("Siebzehn"); break;
            case 18: printf("Achtzehn"); break;
            case 19: printf("Neunzehn"); break;
        default:
            if(zahl % 10 != 0){
                printf("%sund",hnums[zahl%10]); //So that 903 is not NeunhunderdreiundNULL
            }
            printf("%s",zehner[(zahl - zahl % 10) / 10 - 2]);
        }
    }
    //3 digit
    else{
        int hunderter = ((int)floor(zahl/100))*100;//973 -> 900
        printf("%shundert",hnums[hunderter/100]);
        if(zahl - hunderter != 0){  //if true, zahl == 900 / 800 / ..., and does not need recursion
            inWorten(zahl - hunderter); //recurse with the last 2 digits
        }
    }
    

    

    /*
    int rest = zahl;
    int digits = digitFinder(zahl);
    int dec;

    for(int i = digits - 1; i >= 0; i--){

        dec = pow(10,i);

        rest = ((int)floor(zahl / dec))% 10;

        printf("%s ",nums[rest]);
        //printf("%s",nums[rest]);

    }
    */


    /*

    int digits = digitFinder(zahl);

    char zarray[100][10];
    for(int i = digits - 1; i >= 0; i--){

        zarray[i] = nums[zahl % 10];
        zahl = (zahl - zahl % 10) / 10;
   }
    for(int i = 0; i < digits; i++){
        printf("%d\n", zarray[i]);
    }

    */

}



int main(){

    for(int i = -999; i < 1000; i += 1){
        printf("%d: ",i);
        inWorten(i);
        printf("\n");
    }
    return 0;
}
