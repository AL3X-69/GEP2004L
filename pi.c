#include <stdio.h>
#include <math.h>

#define MAX_ITERATIONS 100

int main() {
    double x, y, lpi;
    int i;

    x = sqrt(2.);
    lpi = 2. + x;
    y = pow(2., 1./4.);
    for (i = 0; i < MAX_ITERATIONS; ++i) {
        x = (sqrt(x) + 1.0 / sqrt(x)) / 2.0;
        lpi *= (x + 1.0) / (y + 1.0);
        y = (y * sqrt(x) + 1.0 / sqrt(x)) / (y + 1.0);
    }
    printf("pi = %f\n", lpi);

    return 0;
}
