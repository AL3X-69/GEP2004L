#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define SIZE 80

void compter(int num[26], char txt[]) {
    size_t j;
    int rank;
    for (j = 0; j < strlen(txt); ++j) {
        rank = toupper(txt[j]) - 'A';
        if (rank >= 0 && rank <= 25) num[rank] += 1;
    }
}

int main() {
    char txt[SIZE+1];
    int num[26];
    int i;

    for (i = 0; i < 26; ++i) num[i] = 0;

    printf("Saisissez un texte:\n");
    fgets(txt, SIZE, stdin);
    txt[strcspn(txt, "\r\n")] = 0;

    compter(num, txt);

    for (i = 0; i < 26; ++i) printf("%c: %i\n", (char) i + 'A', num[i]);
    return 0;
}
