#include <stdio.h>
#include <math.h>

int main() {
    int n;
    printf("Saisissez un entier: ");
    scanf("%i", &n);
    float an = 1;
    float sum = 1;
    for (int i = 2; i <= n; i++) {
    	an *= pow(n-1, 2) / pow(n, 2);
        sum += an;
    }
    printf("Somme = %f\n", sqrt(6*sum));
}
