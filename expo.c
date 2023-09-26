#include <stdio.h>
#include <math.h>

#define MAX_N 10

int main() {
    double x;
    printf("Saisissez la valeur de x: ");
    scanf("%lf", &x);
    float sum = 1;
    float an = 1;
    for (int i = 1; i <= MAX_N; i++) {
        an *= x / i;
        sum += an;
    }
    printf("exp(%f) = %f\n", x, sum);
}
