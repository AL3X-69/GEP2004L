#include <stdio.h> 

int main() {
    int a, b;
    printf("Entrez les deux entiers sous la forme \"a b\": ");
    scanf("%i %i", &a, &b);
    int ra = a, rb = b;
    if (a > b) {
        ra = b;
        rb = a;
    }
    printf("--> %i %i\n", ra, rb); 
}
