#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define TOLL 1E-6

double f(double x) {
    return x + exp(x);
}

int main() {
    double  x, y, x0, x1, y0, y1;
    printf("Saisissez x0 et x1: ");
    scanf("%lf %lf", &x0, &x1);
    y0 = f(x0);
    y1 = f(x1);
    do {
        x = x1 - y1 * (x1 - x0) / (y1 - y0);
        y = f(x);
        x0 = x1;
        x1 = x;
        y0 = y1;
        y1 = y;
    } while (fabs(y1) > TOLL);

    printf("%f\n", x);

    return 0;
}
