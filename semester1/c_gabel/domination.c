#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "advanced_console_output.h"

int t;
int height;
int width;
int direction;
int redX; //1
int redY;
int blueX; //2
int blueY;
int blueCount;
int redCount;
int fieldCount;
int pos;

int feld[1000][500];

char await;

void takeover(int x, int y, int team){

    if(team == 1){
        locate(x, y);
        pos = feld[x][y];

        if(pos != 1){
            redCount++;
            feld[x][y] = 1;

            if(pos == 2) blueCount--;

            set_bg_color("red");
            printf(" ");
            set_text_normal();
        }

        redX = x;
        redY = y;

    }
    else if(team == 2){
        locate(x, y);
        pos = feld[x][y];

        if(pos != 2){
            blueCount++;
            feld[x][y] = 2;

            if(pos == 1) redCount--;

            set_bg_color("blue");
            printf(" ");
            set_text_normal();
        }

        blueX = x;
        blueY = y;
    }
}


void printField(){

    for(int i = 1; i <= height - 1; i++){

        locate(1, i);
        for(int j = 1; j <= width; j++){
            if(feld[j][i] == 1){
                set_bg_color("red");
                printf(" ");
            }
            else if(feld[j][i] == 2){
                set_bg_color("blue");
                printf(" ");
            }
            else{
                set_text_normal();
                printf("⋅");
            }

        }

    }

    set_text_normal();
    locate(1, height);
    for(int i = 1; i <= width; i++){
        printf(" ");
    }

}


void start(){

    clear();

    //setup emptpy field
    for(int i = 1; i <= height - 1; i++){

        locate(1, i);
        for(int j = 1; j <= width; j++){
            feld[j][i] = 0;
        }

    }

    redX = rand() % width + 1;
    redY = rand() % height + 1;

    blueX = rand() % width + 1;
    blueY = rand() % height + 1;

}

int checkForEnd(){

    if(blueCount > redCount*2){
        locate(1, height);

        set_bg_color("blue");
        set_text_blinking();
        printf("\nBlue Won!");
        set_text_normal();

        return 1;
    }
    else if(redCount > blueCount*2){
        locate(1, height);

        set_bg_color("red");
        set_text_blinking();
        printf("\nRed Won!");
        set_text_normal();

        return 1;
    }
    else{
        return 0;
    }

}

void randomWalk(int x, int y, int team){

    direction = rand() % 4;

    switch (direction)
    {
    case 0:
        if(x != 1) takeover(x - 1, y, team);
        break;
    case 1:
        if(x != width) takeover(x + 1, y, team);
        break;
    case 2:
        if(y != 1) takeover(x, y - 1, team);
        break;
    case 3:
        if(y != (height - 1)) takeover(x, y + 1, team);
        break;
    
    default:
        break;
    }

}


int checkForSmallTerm(){
    if(get_screen_height() < 5 || get_screen_width() < 10){

        set_fg_color("red");
        printf("Das Fenster ist zu klein!\n");
        set_text_normal();

        return 1;
    }
    return 0;
}


int main(){

    if(checkForSmallTerm()) return 0;

    srand(time(NULL));

    height = get_screen_height();
    width = get_screen_width();
    fieldCount = width * (height - 1);

    //Start
    
    start();

    while (!checkForEnd())
    {
        t++;

        randomWalk(redX, redY, 1);
        randomWalk(blueX, blueY, 2);

        locate(blueX, blueY);
        set_fg_color("blue"); printf("X");
        locate(redX, redY);
        set_fg_color("red"); printf("X");

        printField();
        locate(1,height);

        set_text_normal();
        printf("%dx%d | Timestamp: %d, Red: %d, Blue: %d",width, height, t, redCount, blueCount);

    }
    scanf("%c",&await);

}