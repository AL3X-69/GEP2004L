#include <stdio.h>
#include <inttypes.h>

#define OCTAL_MASK 255

void printb(int n) {
    for (int i = 7; i >= 0; i--) printf("%i", n >> i & 1);
    printf("\n");
}

uint32_t askAddress() {
    uint32_t a, b, c, d;
    scanf("%"SCNu32".%"SCNu32".%"SCNu32".%"SCNu32, &a, &b, &c, &d);
    if (a > 255 || b > 255 || c > 255 || d > 255) {
        printf("Adresse ip invalide");
        return 0;
    }
    return a << 24 | b << 16 | c << 8 | d;
}

void printAddress(uint32_t address) {
    for (int i = 3; i > 0; i--) printf("%"PRIu32".", (address >> i * 8) & OCTAL_MASK);
    printf("%"PRIu32"\n", address & OCTAL_MASK);
}

void printAddressAsHexa(uint32_t address) {
    for (int i = 3; i > 0; i--) printf("%02x.", (address >> i * 8) & OCTAL_MASK);
    printf("%02x\n", address & OCTAL_MASK);
}

uint32_t applyMask(uint32_t address, uint32_t mask) {
    return address & mask;
}

int main() {
    uint32_t ip1, sm1, ip2, sm2, sn1, sn2;
    printf("Saisissez l'adresse IP 1: ");
    ip1 = askAddress();
    printf("Saisissez le masque 1: ");
    sm1 = askAddress();
    sn1 = applyMask(ip1, sm1);
    printf("Saisissez l'adresse IP 2: ");
    ip2 = askAddress();
    printf("Saisissez le masque 2: ");
    sm2 = askAddress();
    sn2 = applyMask(ip2, sm2);
    printf("IP 1: ");
    printAddressAsHexa(ip1);
    printf("Masque 1: ");
    printAddressAsHexa(sm1);
    printf("Adresse de sous-réseau 1: ");
    printAddress(sn1);
    printf("IP 2: ");
    printAddressAsHexa(ip2);
    printf("Masque 2: ");
    printAddressAsHexa(sm2);
    printf("Adresse de sous-réseau 2: ");
    printAddress(sn2);
    if (sn1 == sn2) printf("Les machines appartiennent au même sous réseau\n");
    else printf("Les machines n'appartiennent pas au même sous réseau\n");
    return 0;
}
