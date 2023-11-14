#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Un argument est requis\n");
        return 1;
    }
    int i, val = atoi(argv[1]);
    printf("%i --> ", val);
    for (i = 0; i < 8; i++) {
        printf("%c", (val & 0x80) != 0 ? '1' : '0');
        val *= 2;
    }
    printf("\n");
    return 0;
}