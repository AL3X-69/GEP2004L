#include <stdio.h>

void printb(int n) {
    for (int i = 7; i >= 0; i--) printf("%i", n >> i & 1);
    printf("\n");
}

int main() {
    printf("117 | 25 = ");
    printb(117 | 25);
    printf("117 & 25 = ");
    printb(117 & 25);
    printf("117 << 2 = ");
    printb(117 << 2);
    printf("(117 ^ 25) ^ 25 = ");
    printb((117 ^ 25) ^ 25);
    return 0;
}
