#include <stdlib.h>
#include <stdio.h>

#define TAILLE 8

int main()
{
    char texte[]="Vous avez saisi le mot : ";
    char mot[TAILLE];
    // Saisie d'un mot
    printf("Saisissez un mot : ");
    scanf("%s", mot);
    while(getchar() != '\n') ;
    // Affichage du mot
    printf("%s%s\n", texte, mot);
    return EXIT_SUCCESS;
}
