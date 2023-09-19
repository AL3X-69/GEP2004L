#include <stdio.h>

int main() {
    float fahrenheitDegrees;
    
    printf("Veuillez entrer la température en degrés fahrenheit: ");
    scanf("%f", &fahrenheitDegrees);
    float celsiusDegrees = (fahrenheitDegrees - 32) / 0.8;
    printf("La température en degrés celsius est %f °C\n", celsiusDegrees);
    
    return 0;
}
