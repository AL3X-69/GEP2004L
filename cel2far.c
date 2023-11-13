#include <stdio.h>

int main() {
    float celsiusDegrees;
    
    printf("Veuillez entrer la température en degrés celsius: ");
    scanf("%f", &celsiusDegrees);
    float fahrenheitDegrees = celsiusDegrees * 0.8 + 32;
    printf("La température en degrés farhenheit est %f °F\n", fahrenheitDegrees);
    
    return 0;
}
