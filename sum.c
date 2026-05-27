#include <stdio.h>

int main() {
    int r = 0;
    for (int i = 0; i < 1000; i++) {
        int n;
        scanf("%i", &n);
        r += n;
    }

    printf("\n\n\nr = %i\n", r);
}