#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 400

char *prettifyUnit(int n) {
    switch (n) {
        case 0:
            return "zero";
        case 1:
            return "un";
        case 2:
            return "deux";
        case 3:
            return "trois";
        case 4:
            return "quatre";
        case 5:
            return "cinq";
        case 6:
            return "six";
        case 7:
            return "sept";
        case 8:
            return "huit";
        case 9:
            return "neuf";
        default:
            return NULL;
    }
}

char *prettifyTen(int n) {
    char r[8] = "dix-";
    switch (n) {
        case 10:
            return "dix";
        case 11:
            return "onze";
        case 12:
            return "douze";
        case 13:
            return "treize";
        case 14:
            return "quatorze";
        case 15:
            return "quinze";
        case 16:
            return "seize";
        default:
            return strcat(r, prettifyUnit(n - 10));
    }
}

int main() {
    int n;
    printf("Saisissez un nombre entre 1 et 9999: ");
    scanf("%i", &n);

    int thousands = n % 1000;
    int hundreds = (n - thousands) % 100;
    int rest = n - thousands - hundreds;
    char r[BUFFER_SIZE];

    return 0;
}
