#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <time.h>
#include <stdlib.h>

//----------Vars-----------|

int feld[10];

//-------------------------|



int feldscan(){

    int length = sizeof(feld) / sizeof(feld[0]);
    int sum = 0;
    int element;

    //array input + summen calc
    for(int i = 0; i < length; i++){

        printf("Geben Sie element %d an: ", i);
        scanf(" %d",&element);

        feld[i] = element;
        sum += element;
    }

    //array ausgabe
    for(int i = 0; i < length; i++){
        printf("Element %d: %d\n", i, feld[i]);
    }

    //summenausgabe
    printf("Summe: %d\n", sum);

    //negative zahlen
    sum = 0;
    for(int i = 0; i < length; i++){

        feld[i] *= -1;
        sum += feld[i];
    }

    //array ausgabe
    for(int i = 0; i < length; i++){
        printf("Element %d: %d\n", i, feld[i]);
    }

    //summenausgabe
    printf("Summe: %d\n", sum);
}




int familiemaier(){

    int A;
    int B;
    int C;
    int D;

    printf("|   A   |   B   |   C   |   D   |\n");
    printf("|-------+-------+-------+-------|\n");

    for(int a = 0; a <= 1; a++){

        A = a;

        for(int d = 0; d <= 1; d++){

            if(A == 1){
                D = 0;
            }
            else{
                D = d;
            }

            for(int c = 0; c <= 1; c++){

                if(A == 0 && D == 0){
                    C = 1;
                }
                else{
                    C = c;
                }

                for(int b = 0; b <= 1; b++){

                    if(A == 1 && C == 1){
                        B = 0;
                    }
                    else{

                        B = b;

                        if(b == 1){
                            C = 1;
                        }
                    }

                printf("|   %d   |   %d   |   %d   |   %d   |\n", A, B, C, D);

                }
            }
        }
    }
}


//----------------------------------------------------------------------------------Terminal libary----------------------------------------------------------------------------|

int get_screen_dimension() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;

    if (GetConsoleScreenBufferInfo(hConsole, &csbi)) {
        int columns = csbi.srWindow.Right - csbi.srWindow.Left + 1;
        int rows = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;

        printf("Rows: %d\n", rows);
        printf("Columns: %d\n", columns);
    } else {
        printf("Failed to get console size\n");
    }

    return 0;
}


void locate(int x, int y) // x = row, y = col
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD position = { x, y };

    SetConsoleCursorPosition(hConsole, position);
}

void clear()
{
    printf("\033[%dJ", 2);
}


int set_color_rgb(int bg, int r, int g, int b)
{
    int bg_delta = (bg?10:0);
    printf("\033[%d;2;%d;%d;%dm", 38+bg_delta, r, g, b);
}

void set_color(int bg, char* str)
{
    int v=30; //black in case of no match
    int bg_delta = (bg?10:0);
    if (strcmp(str, "xtermwhite")==0)
    {
        set_color_rgb(bg, 240, 240, 240);
    }
    else
    {
      if (strcmp(str, "black")==0) v=30;
      else if (strcmp(str, "red")==0) v=31;
      else if (strcmp(str, "green")==0) v=32;
      else if (strcmp(str, "yellow")==0) v=33;
      else if (strcmp(str, "blue")==0) v=34;
      else if (strcmp(str, "magenta")==0) v=35;
      else if (strcmp(str, "cyan")==0) v=36;
      else if (strcmp(str, "faintgray")==0) v=37;
      else if (strcmp(str, "default")==0) v=39;
      printf("\033[%dm", v+bg_delta);
    }
}

void set_fg_color(char* str)
{
    set_color( 0, str );
}

void set_bg_color(char* str)
{
    set_color( 1, str );
}



void set_fg_color_rgb(int r, int g, int b)
{
    set_color_rgb( 0, r, g, b );
}

void set_bg_color_rgb(int r, int g, int b)
{
    set_color_rgb( 1, r, g, b );
}

void set_text_bold()
{
    printf("\033[1m");
}

void unset_text_bold()
{
    printf("\033[22m");
}

void set_text_italic()
{
    printf("\033[3m");
}

void unset_text_italic()
{
    printf("\033[23m");
}

void set_text_underlined()
{
    printf("\033[4m");
}

void unset_text_underlined()
{
    printf("\033[24m");
}

void set_text_blinking()
{
    printf("\033[5m");
}

void unset_text_blinking()
{
    printf("\033[25m");
}

void set_text_crossedout()
{
    printf("\033[9m");
}

void unset_text_crossedout()
{
    printf("\033[29m");
}

void set_text_normal()
{
    printf("\033[0m");
}



//---------------------------------------------------------------------------------------------------------------------------------------------------------------------|


int randomcolors(){

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;

    srand(time(NULL));

    int width = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    int height = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;

    while(1){

        int x = rand() % width;
        int y = rand() % height;
        locate(x, y);
        
        int r = rand() % 256;
        int g = rand() % 256;
        int b = rand() % 256;
        set_bg_color_rgb(r,g,b);

        printf(" ");
    }

}


int baum(){

    srand(time(NULL));

    int stamm;
    int baum;

    int gelb = 0;
    int rot = 0;
    int magenta = 0;
    int blau = 0;

    printf("Bitte die gewünschte Baumgesamthöhe eingeben: ");
    scanf(" %d", &baum);

    printf("Bitte die Höhe des Stamms eingeben: ");
    scanf(" %d", &stamm);

    printf("\n\n");

    int krone = baum - stamm;
    int breite = 2*krone + 1;



    if(baum < stamm + 3){
        printf("Dieser Baum ist leider zu klein!\n");
        return 0;
    }

    //baumkrone

    set_fg_color_rgb(150,255,150);
    int lastone = 0;

    for(int i = 0; i <= krone; i++){

        int margin = (breite - 1 - 2*i) / 2;

        for(int k = 0; k <= margin; k++){
            printf(" ");
        }
        
        for(int k = 1; k <= (breite - 2*margin); k++){

            int charnum = rand() % 10;

            if(charnum == 0 && lastone == 0 && (breite - 2*margin) != 1){
                int randcolor = rand() % 4;

                switch (randcolor)
                {
                case 0:
                    set_fg_color("red");
                    rot++;
                    break;

                case 1:
                    set_fg_color("blue");
                    blau++;
                    break;

                case 2:
                    set_fg_color("yellow");
                    gelb++;
                    break;

                case 3:
                    set_fg_color("magenta");
                    magenta++;
                    break;

                default:
                    printf("wtf happened\n");
                    break;
                }

                set_text_blinking();

                printf("o");
                
                set_text_normal();
                set_fg_color_rgb(150,255,150);
                lastone = 1;
            }
            else{

                if((breite - 2*margin) == 1){
                    set_fg_color("yellow");
                    set_text_bold();

                    printf("*");

                    set_text_normal();
                    set_fg_color_rgb(150,255,150);
                }
                else{
                    printf("*");
                }
                lastone = 0;
            }

        }
        
        for(int k = 0; k <= margin; k++){
            printf(" ");
        }

        printf("\n");
    }

    //stamm
    set_fg_color_rgb(120,45,0);
    int logmargin = (breite - 3) / 2;


    for(int i = 0; i < stamm; i++){

        for(int k = 0; k <= logmargin; k++){
            printf(" ");
        }
            
        for(int k = 1; k <= (breite - 2*logmargin); k++){
            printf("|");
        }
            
        for(int k = 0; k <= logmargin; k++){
            printf(" ");
        }

        printf("\n");
    }

    set_fg_color_rgb(255, 255, 255);
    printf("\n");

    printf("Magenta: %d\n",magenta);
    printf("Gelb: %d\n",gelb);
    printf("Rot: %d\n",rot);
    printf("Blau: %d\n",blau);
}



int main()
{
    baum();
    return 0;
}
