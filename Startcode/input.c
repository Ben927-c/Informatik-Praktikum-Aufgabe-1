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
    //Stellt sicher, dass eine leere Datei, zu viele Wörter oder ein zu langes Wort zum Abbruch führen
    while(counter < maxWordCount && fscanf(file, "%99s", words[counter]) == 1){ 
        counter++;
    }

    return counter;
}