#include <stdlib.h>
#include <stdio.h>

#define TAILLE 8

int main()
{
    int n, i, j;
    printf("Saisissez un entier: ");
    scanf("%i", &n);
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("#");
        }
        printf("\n");
    }
}
