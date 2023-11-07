#include <stdio.h>

#define TAILLE 20

// Fonction de recherche dichotomique (binaire), retourne l'index de l'entier si présent, sinon retourne -1
int search(int list[], int size, int x) {
    int left = 0, right = size;
    while (left <= right) {
        int middle = (left + right) / 2;
        if (list[middle] == x) return middle;
        else if (list[middle] < x) left = middle + 1;
        else right = middle - 1;
    }
    return -1;
}

int main() {
    int i, n, r, fibonacci[TAILLE];
    fibonacci[0] = 0;
    fibonacci[1] = 1;
    for (i = 2; i < TAILLE; i++) fibonacci[i] = fibonacci[i - 1] + fibonacci[i - 2];
    printf("Saisissez un entier: ");
    scanf("%i", &n);
    r = search(fibonacci, TAILLE, n);
    if (r == -1) printf("La valeur %i n'a pas été trouvée dans la suite\n", n);
    else printf("La valeur %i a été trouvée a l'index %i\n", n, r);
    return 0;
}