#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define TAILLE_MAX 800
#define COTE 50

size_t getLastSpaceIndex(char s[]) {
    for (size_t i = strlen(s) + 1; i > 0; i--) {
        i--;
        if (s[i] == ' ') return i;
    }
    return 0;
}

void printFullLine() {
    for (int i = 0; i < COTE; i++) printf("#");
    printf("\n");
}

void printHallowLine() {
    for (int i = 0; i < COTE; i++) {
        if (i == 0 || i == COTE - 1) printf("#");
        else printf(" ");
    }
    printf("\n");
}

void printTextLine(char s[]) {
    printf("%s\n\n", s);
    if (strlen(s) > COTE - 10) return;
    int pl = (COTE / 2) - strlen(s) / 2;
    int pr = pl;
    if (strlen(s) % 2 != 0) pr++;
    for (int i = 0; i < COTE; i++) {
        if (i == 0 || i == COTE - 1) printf("#");
        else if (i > pl && i < COTE - pr) printf("%c", s[i - pl - 1]);
        else printf(" ");
    }
    printf("\n");
}


int main()
{
    char txt[TAILLE_MAX + 1];

    printf("Saisissez un texte: ");
    fgets(txt, TAILLE_MAX, stdin);
    txt[strcspn(txt, "\r\n")] = 0;

    printFullLine();
    printHallowLine();

    // Print lines with text
    size_t c = 0;
    size_t len = strlen(txt);
    while (c < len) {
        if (len - c > 40) {
            char t[TAILLE_MAX + 1];
            strncpy(t, txt + c, len - c);
            printf("\n\n|%s|\n\n", t);
            size_t spaceIndex = getLastSpaceIndex(t);
            if (spaceIndex == 0) spaceIndex = 39;
            char s[spaceIndex + 1];
            strncpy(s, t, spaceIndex + 1);
            printf("\n\n|%s|\n\n", s);
            printTextLine(s);
            c += spaceIndex;
        } else {
            char t[TAILLE_MAX + 1];
            strncpy(t, txt + c, len - c);
            printTextLine(t);
            break;
        }
    }

    printHallowLine();
    printFullLine();

    return 0;
}
