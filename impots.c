#include <stdio.h>

int min(int a, int b) {
    return (a <= b) ? (a) : (b);
}

int main() {
    int amount;
    
    printf("Saisissez le montant imposable: ");
    scanf("%i", &amount);
    if (amount < 0) {
        printf("Le montant imposable doit être positif\n");
        return 1;
    }
    
    float result = 0;
    
    printf("Tranche: 1\nTaux d'imposition: 0%%\nMontant concerné! %i€\n", min(amount, 9690));
    
    if (amount > 9690) {
        int slice = min(amount, 26764) - 9690;
        printf("Tranche: 2\nTaux d'imposition: 14%%\nMontant concerné! %i€\n", slice);
        result += slice * 0.14;
    }
    if (amount > 26764) {
        int slice = min(amount, 71754) - 26764;
        printf("Tranche: 3\nTaux d'imposition: 30%%\nMontant concerné! %i€\n", slice);
        result += slice * 0.3;
    }
    if (amount > 71754) {
        int slice = min(amount, 151956) - 71754;
        printf("Tranche: 4\nTaux d'imposition: 41%%\nMontant concerné! %i€\n", slice);
        result += slice * 0.41;
    }
    if (amount > 151956) {
        int slice = amount - 151956;
        printf("Tranche: 5\nTaux d'imposition: 45%%\nMontant concerné! %i€\n", slice);
        result += slice * 0.45;
    }
    printf("Le montant dû total est de %f€\n", result);
    
    /*if (amount < 9690) printf("Tranche: 1\nTaux d'imposition: 0%%\nMontant dû: 0€\n");
    else if (amount < 26764) printf("Tranche: 2\nTaux d'imposition: 14%%\nMontant dû: %f\n", amount * 0.14);
    else if (amount < 71754) printf("Tranche: 3\nTaux d'imposition: 30%%\nMontant dû: %f\n", amount * 0.30);
    else if (amount < 151956) printf("Tranche: 4\nTaux d'imposition: 41%%\nMontant dû: %f\n", amount * 0.41);
    else printf("Tranche: 5\nTaux d'imposition: 45%%\nMontant dû: %f\n", amount * 0.45);*/
    
    
    return 0;
}
