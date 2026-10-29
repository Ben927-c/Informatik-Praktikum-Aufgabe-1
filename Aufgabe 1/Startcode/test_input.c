#include <stdio.h>
#include <stdlib.h>
#include "input.h"

int main(void) {
    char words[10][MAX_WORD_LEN];
    int count = 0;

    printf("=== STARTE UNIT-TESTS FÜR input.c ===\n\n");

    // -------------------------------------------------------------
    // TEST 1: Normaler Durchlauf
    // -------------------------------------------------------------
    FILE *f1 = fopen("test1.txt", "w");
    if (f1 != NULL) {
        fputs("Hallo Welt Das Ist Ein Test", f1);
        fclose(f1);
    }

    f1 = fopen("test1.txt", "r");
    count = readWords(f1, words, 10);
    if (f1 != NULL) fclose(f1);

    printf("[Test 1] Normaler Durchlauf:\n");
    printf("  Eingelesen: %d Wörter (Erwartet: 6)\n", count);
    for (int i = 0; i < count; i++) {
        printf("  - Wort %d: %s\n", i + 1, words[i]);
    }
    printf("\n");

    // -------------------------------------------------------------
    // TEST 2: Leere Datei
    // -------------------------------------------------------------
    FILE *f2 = fopen("test_empty.txt", "w");
    if (f2 != NULL) fclose(f2); // Erstellt leere Datei

    f2 = fopen("test_empty.txt", "r");
    count = readWords(f2, words, 10);
    if (f2 != NULL) fclose(f2);

    printf("[Test 2] Leere Datei:\n");
    printf("  Eingelesen: %d Wörter (Erwartet: 0) -> %s\n\n", 
           count, (count == 0) ? "PASSED" : "FAILED");

    // -------------------------------------------------------------
    // TEST 3: Zu viele Wörter (Mehr Wörter als Array-Kapazität)
    // -------------------------------------------------------------
    FILE *f3 = fopen("test_many.txt", "w");
    if (f3 != NULL) {
        fputs("eins zwei drei vier fünf sechs", f3);
        fclose(f3);
    }

    f3 = fopen("test_many.txt", "r");
    // Wir übergeben maxWordCount = 3, obwohl 6 Wörter in der Datei stehen
    count = readWords(f3, words, 3); 
    if (f3 != NULL) fclose(f3);

    printf("[Test 3] Zu viele Wörter (Array-Limit = 3):\n");
    printf("  Eingelesen: %d Wörter (Erwartet: 3) -> %s\n\n", 
           count, (count == 3) ? "PASSED" : "FAILED");

    printf("=== TESTS BEENDET ===\n");
    return 0;
}