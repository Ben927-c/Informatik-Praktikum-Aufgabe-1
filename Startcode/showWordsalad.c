#include "game.h"
#include "input.h"
#include <stdio.h>
#include <stdlib.h>

void showWordSalad(const char salad[MAX_SEARCH_FIELD_LEN][MAX_SEARCH_FIELD_LEN], unsigned int searchFieldLen);

int main()
{
    const int searchFieldLen = 30;

    if(searchFieldLen < MAX_SEARCH_FIELD_LEN)
    {
        const char words[][MAX_WORD_LEN] = {"Test", "NochEinTest", "WiederEinTest", "EinWeiteresTestWort", "UndSoWeiter"};
        char salad[MAX_SEARCH_FIELD_LEN][MAX_SEARCH_FIELD_LEN];

        int numberOfWords = sizeof(words)/sizeof(words[0]);
        int placedWords = createWordSalad(salad, searchFieldLen, words, numberOfWords);
        
        printf("Placed %d of %d words ...\n", placedWords, numberOfWords);
        showWordSalad(salad, searchFieldLen);

        return EXIT_SUCCESS;
    }
    else
    {
        fprintf(stderr, "Error: Selected search field must not be larger than maximum search field ...\n");

        return EXIT_FAILURE;
    }
}


void showWordSalad(const char salad[MAX_SEARCH_FIELD_LEN][MAX_SEARCH_FIELD_LEN], unsigned int searchFieldLen)
{
    for(int i = 0; i < searchFieldLen; i++)
    {
        for(int j = 0; j < searchFieldLen; j++)
            printf("%c", salad[i][j]);
        printf("\n");
    }
}