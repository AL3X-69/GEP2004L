#include <stdio.h>
#define N 50

int main() {
    int i, j, n;
    int t[N];
    for (i = 1; i < N; i++) t[i]=1;
    
    for (i = 1; i < N; i++) {
        for (j = 1; j <= i; j++) {
            n = i + j + 2 * i * j;
            if (n >= N) break;
            t[n] = 0;
        }
    }
    
    for (i = 0; i < N; i++) {
        printf("%i\n", t[i]);
    }
    printf("\n\n");    
    for (i = 1; i < N; i++) {
        if (t[i] != 0) printf("%i\n", 2 * i + 1);
    }
    
    return 0;
}
