#include <stdio.h>

int main() {
    unsigned char x = 5;

    if ((x & 3) == 1) printf("--> resultat correct\n"); // Fixed by adding parentheses
    else printf("--> resultat faux!\n");

    return 0;
}
