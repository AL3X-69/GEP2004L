#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define TAILLE 20
#define TOWN_MAX_LENGTH 20

void aski(char *q, int *v) {
    printf("%s", q);
    scanf("%i", v);
    while (getchar() != '\n') {}
}

void asks(char *q, int n, char v[n]) {
    char buf[n];
    printf("%s", q);
    fgets(buf, n, stdin);
    buf[strcspn(buf, "\r\n")] = 0;
    strcpy(v, buf);
}

double avg(int n, int t[n]) {
    double sum = 0.;
    for (int i = 0; i < n; i++) sum += t[i];
    return sum / n;
}

double stddv(int n, int t[n]) {
    double a = avg(n, t), sum = 0.;
    for (int i = 0; i < n; i++) sum += pow(t[i], 2);
    sum -= pow(a, 2.);
    sum /= n;
    return sqrt(sum);
}

void printhgline(int n, int t[n], int lb, int rb) {
    printf("%i-%i: ", lb, rb);
    for (int i = 0; i < n; i++) {
        if (lb <= t[i] && t[i] <= rb) printf("#");
    }
    printf("\n");
}

int main() {
    int i, c = 0, age[TAILLE], distance[TAILLE], income[TAILLE];
    char r, town[TOWN_MAX_LENGTH][TAILLE];
    for (i = 0; i < TAILLE; i++) {
        c++;
        printf("Persone #%i\n", i + 1);
        aski("1) Quel âge avez-vous ? ", &age[i]);
        aski("2) A quel distance en km de votre lieu de travail habitez-vous ? ", &distance[i]);
        asks("3) Dans quel commune habitez-vous ? ", TOWN_MAX_LENGTH, town[i]);
        aski("4) Quel est votre revenu annuel (en euros) ? ", &income[i]);
        printf("--> Voulez-vous interviewer une autre personne (O/N) ? ");
        scanf(" %c", &r);
        if (toupper(r) != 'O') break;
    }
    printf("Age   Distance (km)   Commune                Salaire (Euros)\n");
    printf("------------------------------------------------------------\n");
    for (i = 0; i < c; i++) {
        printf("%-3i   %13i   %-20s   %-14i\n", age[i], distance[i], town[i], income[i]);
    }
    printf("------------------------------------------------------------\n");
    printf("Age: moyenne: %f, écart-type: %f\n", avg(c, age), stddv(c, age));
    printf("Histogramme:\n");
    printhgline(c, age, 18, 25);
    printhgline(c, age, 26, 40);
    printhgline(c, age, 41, 50);
    printhgline(c, age, 50, 65);
    return 0;
}

