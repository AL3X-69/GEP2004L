#include <stdio.h>
#include <math.h>

int max(int a, int b, int c) {
    int m = a;
    if (m < b) {
        m = b;
    }
    if (m < c) {
        m = c;
    }
    return m;
}

int main() {
    int choice;
    float surface;
    printf("Calcul de surface:\n1) Carré\n2) triangle\n3) trapèze\n4) parallélogramme\n5) Triangle (formule de Héron)\n");
    scanf("%i", &choice);
    switch (choice) {
        int a, b, c;
        case 1:
            printf("Veuillez entrer le coté: ");
            scanf("%i", &a);
            surface = pow(a, 2.);
            break;
        case 2:
            printf("Veuillez entrer la base et la hauteur (format 'b h'): ");
            scanf("%i %i", &a, &b);
            surface = a * b / 2.;
            break;
        case 3:
            printf("Veuillez entrer la petite base, la grande base et la hauteur (format 'b B h'): ");
            scanf("%i %i %i", &a, &b, &c);
            surface = (b + a) * c / 2.;
            break;
        case 4:
            printf("Veuillez entrer la base et la hauteur (format 'b h'): ");
            scanf("%i %i", &a, &b);
            surface = a * b;
            break;
        case 5:
            printf("Veuillez entrer les cotés a, b et c (format 'a b c'): ");
            scanf("%i %i %i", &a, &b, &c);
            if (max(a, b, c) >= a + b + c - max(a, b, c)) {
                printf("Les cotés entrés ne forment pas un triangle\n");
                return 1;
            }
            float s = (a + b + c) / 2.;
            surface = sqrt(s * (s - a) * (s - b) * (s - c));
            break;
        default:
            printf("Choix invalide\n");
            return 1; 
    }
    printf("--> surface = %f\n", surface);
}
