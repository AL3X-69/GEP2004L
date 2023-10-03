#include <stdio.h>
#include <math.h>

int getPGCD(int a, int b) {
    while (b != 0) {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

void simplify(int* a, int* b) {
    int pgcd = getPGCD(*a, *b);
    *a = *a / pgcd;
    *b = *b / pgcd;
    if (*b < 0) {
        *a = -*a;
        *b = -*b;
    }
} 

int main() {
    int a, b = 1, c, d = 1, pgcd, ppcm;
    char op;
    printf("Saisissez une fraction: ");
    scanf("%i/%i", &a, &b);
    
    simplify(&a, &b);
    
    printf("--> %i/%i\n", a, b);
    
    while (1) {
        printf("Opération: ");
        scanf(" %c", &op);
        if (op == '#') {
            printf("%i + %i/%i\n", a / b, a - a / b * b, b);
            continue;
        }
        printf("Saisissez une fraction: ");
        d = 1;
        scanf("%i/%i", &c, &d);
        simplify(&c, &d);
        switch (op) {
            case '+':
                pgcd = getPGCD(b, d);
                ppcm = b * d / pgcd;
                a = a * ppcm / b + c * ppcm / d;
                b = ppcm;
                break;
            case '-':
                pgcd = getPGCD(b, d);
                ppcm = b * d / pgcd;
                a = a * ppcm / b - c * ppcm / d;
                b = ppcm;
                break;
            case '/':
                a = a * d;
                b = b * c;

                break;
            case '*':
                a = a * c;
                b = b * d;
                break;
            case '^':
                a = pow(a, c);
                b = pow(b, c);
                break;
            default:
                printf("Opération invalide");
                return 1;
        }
        simplify(&a, &b);
        if (b == 1) printf("--> %i\n", a);
        else printf("--> %i/%i\n", a, b);
    }
    return 0;
}
