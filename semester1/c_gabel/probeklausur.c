#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int fischput(){

    int f;

    printf("Bitte geben sie eine weitere positive natürliche Zahl an: ");
    scanf(" %d", &f);

    if(f < 0){
        printf("Ungültige Eingabe. ");
        return fischput();  
    }
    else{
        return f;
    }
}

int maxput(){

    int k;

    printf("Bitte geben sie eine positive natürliche Zahl an: ");
    scanf(" %d", &k);

    if(k < 0){
        printf("Ungültige Eingabe. ");
        return maxput();
    }
    else{
        return k;
    }
}

int fangput(){

    int p;

    printf("Bitte geben sie an, wie viel Prozent der Fische pro Jahr gefangen werden sollen: (0 bis 100): ");
    scanf(" %d", &p);

    if(p < 0 || p > 100){
        printf("Ungültige Eingabe. ");
        return fangput();
    }
    else{
        return p;
    }
}





int aufgabe1(){

    int start_fische = fischput();
    int max_fische = maxput();
    

    int bestand[26];
    bestand[0] = start_fische;

    printf("Jahr 0: %d\n",start_fische);
    for(int i = 1; i < 26; i++){
        bestand[i] = (int)(bestand[i - 1] + 0.16*(max_fische - bestand[i - 1]));
        printf("Jahr %d: %d\n",i ,bestand[i]);
    }
    
    float fische_fangen = fangput();

    printf("\nWenn man inbetracht zieht, das %f Prozent der Fische pro Jahr gefischt werden:\n",fische_fangen);
    for(int i = 1; i < 26; i++){
        bestand[i] = (int)(bestand[i - 1]*((100 - fische_fangen) / 100) + 0.16*(max_fische - bestand[i - 1]));
        printf("Jahr %d: %d (Es wurden %d Fische in diesem Jahr gefangen.)\n",i ,bestand[i], 
        
        (int)(bestand[i - 1] + 0.16*(max_fische - bestand[i - 1])) - bestand[i]

        );
    }

    return 0;
}

int main(){
    
    return 0;
}
