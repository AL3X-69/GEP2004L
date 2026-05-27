#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Un argument est requis\n");
        return 1;
    }
    int i, val = atoi(argv[1]);
    printf("%i --> %X\n", val, val);
    return 0;
}