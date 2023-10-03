#include <stdio.h>
#define N 19

int main() {
    int i, j;
    int t[N];
    
    for (i = 0; i < N; ++i) {
        t[i] = i + 2;
    } 
    
    for (i = 0; i < N; ++i) {
        if (t[i] == 0) continue;
        for (j = i + 1; j < N; j++) {
            if (t[j] % t[i] == 0) {
                t[j] = 0;
            }
        }
        printf("%i\n", t[i]);
    }
    return 0;
}
