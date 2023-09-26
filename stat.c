#include <stdio.h>
#include <math.h>

int main() {
    printf("Saisissez un entier: ");
    int n;
    scanf("%i", &n);
    int l[n]; // On déclare une liste de n éléments
    printf("Saisissez %i valeurs: ", n);
    for (int i = 0; i < n; ++i) { // On fait une boucle qui se répète de i = 0 a i = n
        scanf("%i", &l[i]); // On insère ce qu'a entré l'utilisateur à l'emplacement i de la liste
    }
    float avg = 0;
    for (int i = 0; i < n; ++i) {
        avg += l[i]; // On ajoute les éléments de la liste un à un
    }
    avg = avg / n; // On calcule la moyenne en divisant par le nombre d'éléments

    float deviation = 0;
    for (int i = 0; i < n; ++i) {
        deviation = deviation + pow(l[i] - avg, 2.); // On ajoute les éléments un a un au calcul de l'écart type
    }
    deviation = sqrt(deviation / n);

    printf("moyenne = %f\n", avg);
    printf("écart-type = %f\n", deviation);

    return 0;
}
