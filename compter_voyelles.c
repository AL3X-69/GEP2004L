#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define TAILLE 80

int isVowel(char c) {
    int vowels[] = {65, 69, 73, 79, 85, 89};
    for (int i = 0; i < 7; i++) {
        if (vowels[i] == c) return 1;
    }
    return 0;
}

int main() {
    char txt[TAILLE];
    int i, r = 0;

    printf("Saisissez un texte: ");
    fgets(txt, TAILLE, stdin);
    txt[strcspn(txt, "\r\n")] = 0;

    for (i = 0; i < TAILLE; i++) {
        if (txt[i] == 0) break;
        if (isVowel(toupper(txt[i]))) r++;
    }

    printf("--> Nombre de voyelles: %i\n", r);
    return 0;
}
