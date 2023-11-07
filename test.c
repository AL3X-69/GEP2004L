#include <stdio.h>
#include "outils.h"

#define LENGTH 10

int main() {
    int64_t t[LENGTH];
    initialiser(LENGTH, t, MONOTONE_CR);
    afficherVecteur(LENGTH, t);
    verifier(LENGTH, t);
    return 0;
}
