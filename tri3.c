#include <stdio.h> 

int main() {
    int a, b, c;
    printf("Entrez les trois entiers sous la forme \"a b c\": ");
    scanf("%i %i %i", &a, &b, &c);
    int ra = a, rb = b, rc = c;
    if (a > b) {
        ra = b;
        rb = a;
    }
    if (rb > c) {
        int i = rb;
        rb = c;
        rc = i;
    }
    if (ra > rb) {
        int i = ra;
        ra = rb;
        rb = i;
    }
    printf("--> %i %i %i\n", ra, rb, rc); 
}
