#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int tabelle(){

    int x = 1;
    int y = 1;

    printf("|   Nicht x  |   Nicht y    |   x AND y |   x OR y  |   x XOR y |   ~x  |\n");
    printf("|------------+--------------+-----------+-----------+-----------+-------|\n");

    printf("|     %d      |      %d       |     %d     |     %d     |     %d     |   %d  |\n",!x, !y, x&&y, x || y, x ^ y, ~x);
    x = 0;
    printf("|     %d      |      %d       |     %d     |     %d     |     %d     |   %d  |\n",!x, !y, x&&y, x || y, x ^ y, ~x);
    x = 1;
    y = 0;
    printf("|     %d      |      %d       |     %d     |     %d     |     %d     |   %d  |\n",!x, !y, x&&y, x || y, x ^ y, ~x);
    x = 0;
    printf("|     %d      |      %d       |     %d     |     %d     |     %d     |   %d  |\n",!x, !y, x&&y, x || y, x ^ y, ~x);

    return 0;
}

int timeformat(){

    int inputsek;

    int years = 0;
    int weeks = 0;
    int days = 0;
    int hours = 0;
    int minutes = 0;
    int secs = 0;

    printf("Geben sie eine Anzahl von Sekunden an:\n");
    int fehlersenke = scanf("%d",&inputsek);


    if(inputsek < 0){
        printf("Die Sekundenanzahl kann nicht negativ sein, versuchen sie es erneut\n");
        return timeformat();
    }

    secs = inputsek;
    while(secs >= 60){
        secs -= 60;
        minutes += 1;
    }

    while(minutes >= 60){
        minutes -= 60;
        hours += 1;
    }

    while(hours >= 24){
        hours -= 24;
        days += 1;
    }

    while(days >= 7){
        days -= 7;
        weeks += 1;
    }

    while(weeks >= 365){
        weeks -= 365;
        years += 1;
    }

    printf("Time: %d Year(s), %d Week(s), %d Day(s), %d Hour(s), %d Minute(s) and %d Second(s).\n",years, weeks, days, hours, minutes, secs);
    return 0;
}


void pwdgen(){

    char passwort[9];

    srand(time(NULL));




    for(int i = 0; i < 8; i++){
        passwort[i] = (char)((rand() % 94) + 33);
    }
    passwort[8] = '\0';

    printf("Passwort: %s\n",passwort);
}




int main()
{

    pwdgen();

    return 0;
}
