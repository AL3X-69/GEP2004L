#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    int key;
    if (argc < 4) {
        printf("Usage: ./chiffrer1 {-c|-d} [KEY] [MESSAGE | ENCODED_CHAR...]\n");
        return 1;
    }
    key = atoi(argv[2]);
    if (strcmp(argv[1], "-c") == 0) {
        char *txt = argv[3];
        for (size_t i = 0; i < strlen(txt); i++) printf("%i ", ((int)*(txt + i)) + key);
    } else if (strcmp(argv[1], "-d") == 0) {
        for (int i = 3; i < argc; i++) printf("%c", (char) (atoi(argv[i]) - key));
    } else {
        printf("Option invalide\n");
        return 1;
    }
    printf("\n");
    return 0;
}
