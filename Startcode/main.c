#include <stdlib.h>
#include <stdio.h>
#include "input.h"
#include "game.h"
#include "graphicalGame.h"

#define MAX_NUMBER_OF_WORDS 100
#define SALAD_SIZE 20

int main(int argc, char *argv[])
{
    int exitCode = EXIT_SUCCESS;

    // Check if the correct number of arguments is provided
    if(argc != 2)
    {
        fprintf(stderr, "Usage: %s <path to file with search words>\n", argv[0]);
        exitCode = EXIT_FAILURE;
    }
    else
    {
        char words[MAX_NUMBER_OF_WORDS][MAX_WORD_LEN]; // Array to hold the words to be used in the game
        unsigned int wordCount = 0;

        FILE *file = fopen(argv[1], "r");

        if(file != NULL)
        {
            unsigned int placedWords = 0;
            char wordSalad[MAX_SEARCH_FIELD_LEN][MAX_SEARCH_FIELD_LEN] = {0}; // 2D array to store the word salad

            // Read words from file and store in 'words' array
            wordCount = readWords(file, words, MAX_NUMBER_OF_WORDS);
            fclose(file);

            // Create the word salad by placing words into grid
            placedWords = createWordSalad(wordSalad, SALAD_SIZE, words, wordCount);

            // TODO:
            // Check if all words were successfully placed
            // Start the game if successful
            // error message if some words couldn't be placed
            if (placedWords == wordCount)
            {
                //Spielstart muss hier noch eingefügt werden
            }
            else
            {
                fprintf("Error: Es konnten nur %u von %u Wörtern platziert werden", placedWords, wordCount);
                exitCode = EXIT_FAILURE;
            }

        }
        else
        {
            // Print error message if file couldn't be opened
            fprintf(stderr, "Could not open file %s for reading ...\n", argv[1]);
            exitCode = EXIT_FAILURE;
        }
    }

    return exitCode;
}