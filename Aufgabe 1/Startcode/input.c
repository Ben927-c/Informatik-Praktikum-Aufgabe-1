#include "input.h"
#include <string.h>
#include <ctype.h>

// TODO:
// eine Funktion implementieren, die ein einzelnes Wort aus einer Textdatei (words.txt) einliest und als C-String zurückgibt.

// Read words from file and store in 'words' array
int readWords(FILE *file, char words[][MAX_WORD_LEN], unsigned int maxWordCount)
{
    //Überprüfung der Bedingungen
    if (file == 0 || words == 0 || maxWordCount == 0){
        return 0;
    }

    unsigned int counter = 0;
    char line[1024]; //Gilt für eine Zeile

    //Einzelne Zeile, Wort für Wort einlesen
    while(counter < maxWordCount && fgets(line, sizeof(line), file) != NULL){ 
        //Trennzeichen berücksichtigen
        char *token = strtok(line, ",; \r\n\t");

        while(token != NULL && counter < maxWordCount){
            
            //Hier müssen noch Buchstaben von klein nach groß umgeschireben werden
            for(int i = 0; token[i] != '\0'; i++)
            {
                if(token[i] >= 97 && token [i] <= 122){
                    token[i] -= 32;
                }
            }
            //einzelnes Wort kopieren
            strncpy(words[counter], token, MAX_WORD_LEN - 1);
            //Sicherheitshalber um nachfolgende Vorgänge nicht zu behindern
            words[counter][MAX_WORD_LEN - 1] = '\0';

            counter++;
            //nächstes Wort aus der Zeile nehmen
            token = strtok(NULL, ",; \r\n\t");
        }
    }

    return counter;
}