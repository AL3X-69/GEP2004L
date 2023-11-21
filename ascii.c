#include <stdio.h>

int main() {
    int i
    char c;
    for (i = 0; i < 26; i++) {
        c = 'A' + i;
        printf("'%c' code dec: %i code hex %X\n", c, (int) c, (int) c);
    }
    return 0;
}