#include <stdio.h>

/*
 *  2
 * 1 3
 *  5
 * 4 6
 *  7
*/
int digits[10] = {
    0b1111011,
    0b0010010,
    0b0111101,
    0b0110111,
    0b1010110,
    0b1100111,
    0b1101111,
    0b0110010,
    0b1111111,
    0b1110111
};

void printn(int l, int n) {
    int digit = digits[n];
    switch (l) {
        case 0:
            if ((digit >> 5 & 1) == 1) printf(" #### ");
            else printf("      ");
            break;
        case 1:
        case 2:
        case 3:
        case 4:
            if ((digit >> 6 & 1) == 1) printf("#");
            else printf(" ");
            printf("    ");
            if ((digit >> 4 & 1) == 1) printf("#");
            else printf(" ");
            break;
        case 5:
            if ((digit >> 2 & 1) == 1) printf(" #### ");
            else printf("      ");
            break;
        case 6:
        case 7:
        case 8:
        case 9:
            if ((digit >> 3 & 1) == 1) printf("#");
            else printf(" ");
            printf("    ");
            if ((digit >> 1 & 1) == 1) printf("#");
            else printf(" ");
            break;
        case 10:
            if ((digit & 1) == 1) printf(" #### ");
            else printf("      ");
            break;
    }
    printf(" ");
}

int countdigits(int n) {
    int r = 0;
    do {
        n /= 10;
        r++;
    } while (n != 0);
    return r;
}

// position from 0 as the most significative digit
int getdigit(int n, int p) {
    int d = countdigits(n) - 1;
    for (int i = 0; i < d - p; i++) n /= 10;
    return n % 10;
}

int main() {
    int n, i, j, d;
    printf("Saisissez un entier: ");
    scanf("%i", &n);
    d = countdigits(n);
    for (i = 0; i <= 10; i++) {
        for (j = 0; j < d; j++) {
            printn(i, getdigit(n, j));
        }
        printf("\n");
    }
}
