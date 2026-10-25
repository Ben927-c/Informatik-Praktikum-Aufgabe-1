#include "game.h"
#include <time.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RAND_TRIES_PER_WORD 10
#define EMPTY_CHAR 0

//TODO: Spiellogik implementieren:
/* * Wörter aus der Wortliste zufällig horizontal oder vertikal platzieren
   * restliche Felder mit zufälligen Buchstaben füllen */

// Creates the word salad by placing words randomly and filling empty spaces
int createWordSalad(char salad[MAX_SEARCH_FIELD_LEN][MAX_SEARCH_FIELD_LEN], unsigned int searchFieldLen, const char words[][MAX_WORD_LEN], unsigned int wordCount)
{
srand(time(NULL)); //Zufallszahl erstellen
int counterWords = 0;
if (wordCount > 0) {

    int row;
    int col;
   

    // Jedes Wort der Reihe nach bearbeiten
    for (unsigned int wordIndex = 0; wordIndex < wordCount; wordIndex++) {

        int wordLen = strlen(words[wordIndex]);

        // Prüfen, ob das Wort ins Spielfeld passt
        if (searchFieldLen > 0 && wordLen > 0 && wordLen <= searchFieldLen) {

            for (int versuche = 0; versuche < MAX_RAND_TRIES_PER_WORD; versuche++) {

                int direction = rand() % 2;
                int canPlace = 1;

                // Horizontale Platzierung
                if (direction == 0) {

                    row = rand() % searchFieldLen;
                    col = rand() % (searchFieldLen - wordLen + 1);

                    // Prüfen, ob alle benötigten Felder frei sind
                    for (int i = 0; i < wordLen; i++) {
                        if (salad[row][col + i] != EMPTY_CHAR) {
                            canPlace = 0;
                            break;
                        }
                    }

                    // Wort eintragen, wenn alle Felder frei sind
                    if (canPlace == 1) {
                        for (int i = 0; i < wordLen; i++) {
                            salad[row][col + i] = words[wordIndex][i];
                        }
                        counterWords++;
                        break;//Wort erfolgreich eingetragen
                    }
                }

                // Vertikale Platzierung
                else {

                    col = rand() % searchFieldLen;
                    row = rand() % (searchFieldLen - wordLen + 1);

                    // Prüfen, ob alle benötigten Felder frei sind
                    for (int i = 0; i < wordLen; i++) {
                        if (salad[row + i][col] != EMPTY_CHAR) {
                            canPlace = 0;
                            break;
                        }
                    }

                    // Wort eintragen, wenn alle Felder frei sind
                    if (canPlace == 1) {
                        for (int i = 0; i < wordLen; i++) {
                            salad[row + i][col] = words[wordIndex][i];
                        }
                        counterWords++;
                        break;//Wort erfolgreich eingetragen
                    }
                }
            }
        }
    }
}


// Alle übrigen Felder mit zufälligen Buchstaben füllen
for (unsigned int row = 0; row < searchFieldLen; row++) {
    for (unsigned int col = 0; col < searchFieldLen; col++) {
         //Nur leere Felder verändern
        if (salad[row][col] == EMPTY_CHAR) {
            salad[row][col] = 'A' + rand() % 26;
        }
    }
}
return counterWords;
}