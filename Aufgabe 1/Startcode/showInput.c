#include <stdio.h>
#include <stdlib.h>
#include "input.h"

#define MAX_WORDS 100

int main()
{
    const char *filePath = "words.txt";

    FILE *file = fopen(filePath, "r");

    if(file != NULL)
    {
        char words[MAX_WORDS][MAX_WORD_LEN];

        int wordCount = readWords(file, words, MAX_WORDS);
        
        for(int i = 0; i < wordCount; i++)
        {
            printf("%d. Entry: %s\n", i+1, words[i]);
        }

        return EXIT_SUCCESS;
    }
    else
    {
        fprintf(stderr, "Could not find %s ...\n", filePath);

        return EXIT_FAILURE;
    }

}