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

if (wordCount > 0){
   int wordIndex = rand() % wordCount; //Einzelnes Wort aus dem Array herausnehmen
   int wordLen = strlen(words[wordIndex]); //Wortlänge bestimmen
   int direction = rand() % 2; //Richtung bestimmen
   int row;
   int col;
   int canPlace = 1;
   
   //Startzeile beliebig und Spalte eingeschrenkt
   if (searchFieldLen > 0 && wordLen <= searchFieldLen){
      if (direction ==  0){
            row = rand() % searchFieldLen;
            col = rand() % (searchFieldLen - wordLen + 1);
            

         for(int i = 0; i <= wordLen -1 ; i++){
            if (salad[row][col + i] != EMPTY_CHAR) {
               canPlace = 0;
               break;
            }
            
       }
      }




   //Startspalte beliebig und Spalte eingeschrenkt
      else {
         col = rand() % searchFieldLen;
         row = rand() % (searchFieldLen - wordLen + 1);

            for(salad[row + i][col] != EMPTY_CHAR){
               canPlace = 0;
               break;
         
      }
      
   }
}
}
   


   












}
