#include <stdio.h>

int main() {
    int n;
    printf("Saisissez un entier: ");
    scanf("%i", &n);
    if (n > 10) {
        printf("L'entier doit être inférieur ou égal a 10\n");
        return 1;
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= 10; ++j) {
            printf("%3i ", i * j);
        }
        printf("\n");
    }
    return 0;
}
