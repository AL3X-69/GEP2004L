#include <stdlib.h>
#include <stdio.h> // Dépendance requise manquante

int main() {
    int i, n;
    float sum = 0;

    // Saisie
    printf("Saisissez n : ");
    scanf("%i", &n); // Pointeur manquant

    // Calcul de la série
    for (i = 1; i <= n; ++i) {
        sum += (float) 2/(i*i + 2*i); // Ajout d'un cast pour que le résultat de l'opération soit bien un float
    } // Parenthèse fermante manquante

    // Affichage
    printf("valeur = %f\n", sum); // Format incorrect : %i au lieu %f

    return EXIT_SUCCESS;
}
