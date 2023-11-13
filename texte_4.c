#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define TAILLE_MAX 800
#define COTE 50

size_t getLastCharIndex(char s[], char c) {
    size_t len = strlen(s);
    for (size_t i = 0; i < len; i++) {
        if (s[len - i - 1] == c) return len - i - 1;
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
    //printf("ptl: %s\n", s);
    size_t len = strlen(s);
    if (len > COTE - 10) return;
    int pl = (COTE / 2) - len / 2;
    int pr = pl;
    //if (len % 2 != 0) pr--;
    for (int i = 0; i < COTE; i++) {
        if (i == 0 || i == COTE - 1) printf("#");
        else if (i >= pl && i <= COTE - pr && ((unsigned long) i - pl) < len) {
            printf("%c", s[i - pl]);
        }
        else printf(" ");
    }
    printf("\n");
}

size_t trim(char *src) {
    size_t len = strlen(src);
    int tl = 0, tr = 0;
    size_t i;
    for (i = 0; i < len; i++) {
        if (src[i] == ' ') tl++;
        else break;
    }
    for (i = 0; i < len; i++) {
        if (src[len - i - 1] == ' ') tr++;
        else break;
    }
    strncpy(src, src + tl, len - tr - tl);

    *(src + len - tr - tl) = 0;

    return tl + tr;
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
            strncpy(t, txt + c, COTE - 10);
            t[COTE - 10] = 0;
            printf("t1 = %s\n", t);
            //size_t trimOffset = trim(t);
            //printf("t2 = %s\n", t);
            size_t offset = getLastCharIndex(t, ' ');
            //printf("si = %zu\n", offset);
            size_t cutIndex = offset;
            unsigned short cuttedWord = 0;
            if (offset < COTE / 2) {
                cutIndex = COTE - 11;
                offset = cutIndex;
                cuttedWord = 1;
            } else {
                cutIndex -= 1;
                cuttedWord = 0;
            }
            char s[TAILLE_MAX + 1];
            strncpy(s, t, cutIndex);
            if (cuttedWord) {
                s[offset + 1] = 0;
                strcat(s, "-");
            } else s[offset] = 0;
            printf("s = %s\n", s);
            printTextLine(s);
            //printf("si = %zu\n", offset);
            c += offset;
            //printf("%zu\n", offset + trimOffset);
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
