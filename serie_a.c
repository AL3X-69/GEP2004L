#include <stdio.h>
#include <math.h>
#include <time.h>

void main_old(int n) {
    float sum = 0;
    for (int i = 0; i <= n; i++) {
        sum += pow(0.5, i);
    }
    printf("Somme = %f\n", sum);
}

int main() {
    int n;
    printf("Saisissez un entier: ");
    scanf("%i", &n);
    clock_t t = clock();
    main_old(n);
    t = clock() - t;
    printf("Took %lims\n", t);
    t = clock();
    float sum = 1;
    float an = 1;
    for (int i = 0; i <= n; i++) {
        an *= 0.5;
        sum += an;
    }
    printf("Somme = %f\n", sum);
    t = clock() - t;
    printf("Took %lims\n", t);
}
