#include <stdio.h>

int cel2far(float cel) {
    return cel * 0.8 + 32;
}

int far2cel(float far) {
    return (far - 32) / 0.8;
} 

int main() {
    int conversionType;
    float inputDegrees;
    
    printf("Quel conversion voulez vous effectuer ? (1: Celsius vers Farheinheit, 2: Farheinheit vers Celsius) ");
    scanf("%i", &conversionType);
    if (conversionType < 1 || conversionType > 2) {
        printf("Entrée invalide, veuillez entrer 1 ou 2\n");
        return 1;
    }
    
    printf("Veuillez entrer la température: ");
    scanf("%f", &inputDegrees);
    float convertedDegrees = (conversionType == 1) ? (cel2far(inputDegrees)) : (far2cel(inputDegrees));
    printf("La température convertie est %f degrès\n", convertedDegrees);
    
    return 0;
}
