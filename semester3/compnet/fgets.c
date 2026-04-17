/*


Aufgabe 2 (Dateien + Zeichenketten)
string.h ist NICHT erlaubt!

Programmaufruf:
./aufgabe2 <eingabe_datei> <ausgabe_datei>

Eingabedatei:
- enthält GENAU zwei Zeilen
- jede Zeile ist komplett rückwärts geschrieben
- zusätzlich enthält jede Zeile das Zeichen '#'
  Dieses Zeichen steht für einen falschen Buchstaben.
  Aufgabe: Ersetze '#' durch 'e'

Aufgabe:
Für jede der zwei Zeilen:
1) Zeile einlesen (fgets)
2) '\n' am Ende entfernen
3) Die Zeile umdrehen (reverse)
4) In der umgedrehten Zeile jedes '#' durch 'e' ersetzen
5) Ergebnis in die Ausgabedatei schreiben (mit '\n')

Fehlerfälle:
- argc != 3:
  stderr: "Aufruf: ./aufgabe2 <eingabe_datei> <ausgabe_datei>\n"
  return 1;

- Eingabedatei kann nicht geöffnet werden ("r"):
  stderr: "Eingabedatei konnte nicht geoeffnet werden.\n"
  return 2;

- Ausgabedatei kann nicht geöffnet werden ("w"):
  stderr: "Ausgabedatei konnte nicht geoeffnet werden.\n"
  return 3;

Am Ende zusätzlich:
stdout: "Fertig.\n"

Beispiel input.txt:
rh#S

Beispiel output.txt:
Sehr

*/

#include <stdio.h>

void chomp(char *s) {
    
    while(*s != '\0'){
        s++;
    }

    if(*s == '\n'){
        *s = '\0';
    }

}

int my_strlen(const char *s) {
    /* TODO: Länge bis '\0' (ohne string.h) */

    int count = 0;

    while(*s != '\0'){
        count++;
        s++;
    }

    return count;
}

/* Dreht die Zeichenkette in-place um */
void reverse_in_place(char *s) {
    /* TODO */
}

/* Ersetzt jedes '#' durch 'e' */
void fix_hash_to_e(char *s) {
    /* TODO */
}

int main(int argc, char **argv) {
    /* TODO: argc prüfen */

    if (argc != 3)
    {
        printf("Aufruf: ./aufgabe2 <eingabe_datei> <ausgabe_datei>\n");
        return 1;
    }
    
    char buff[254];


    
    /* TODO: Dateien öffnen */
    FILE* input = fopen(argv[1], "r");
    FILE* output = fopen(argv[2], "w");

    /* TODO: genau zwei Zeilen lesen und verarbeiten */
    fgets(buff, 254, input);
    fputs(buff, output);
    //verarbeiten ...

    fgets(buff, 254, input);
    fputs(buff, output);
    //verarbeiten ...

    /* TODO: Ergebnis in Ausgabedatei schreiben */

    

    /* TODO: Dateien schließen */
    fclose(input);
    fclose(output);
    /* TODO: printf("Fertig.\n"); */

    return 0;
}
