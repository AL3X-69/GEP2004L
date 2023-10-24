#include <stddef.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

#define START_N 10 // iteration start (int)
#define END_N 1000 // iteration end (int)
#define STEP_N 10 // iteration step (int)
#define START_X -10 // values start (double)
#define END_X 10 // values end (double)
#define STEP_X 1 // values step (double)

double expo(double x, int n) {
    float sum = 1;
    float an = 1;
    for (int i = 1; i <= n; i++) {
        an *= x / i;
        sum += an;
    }
    return sum;
}

size_t getLen(double x) {
    char buf[20];
    sprintf(buf, "%.6g", x);
    return strlen(buf);
}

size_t getIntLen(int x) {
    char buf[20];
    sprintf(buf, "%i", x);
    return strlen(buf);
}

size_t getMaxLen(double t[], int n) {
    size_t r = 0;
    for (int i = 0; i <= n; i++) {
        size_t l = getLen(t[i]);
        if (l > r) r = l;
    }
    return r;
}

size_t max(size_t a, size_t b) {
    return a > b ? a : b;
}

size_t sum(size_t t[], int n) {
    size_t r = 0;
    for (int i = 0; i < n; i++) r += t[i];
    return r;
}

void printCharNTimes(char c, size_t n) {
    for (size_t i = 0; i < n; i++) printf("%c", c);
}

void printlnCharNTimes(char c, size_t n) {
    printCharNTimes(c, n);
    printf("\n");
}

void printPadded(double v, size_t length) {
    size_t _l = getLen(v);
    printCharNTimes(' ', length - _l);
    printf("%.6g ", v);
}

void printColumn(short pl, short pr) {
    if (pl) printf(" ");
    printf("#");
    if (pr) printf(" ");
}

int main() {
    int nx = (abs(START_X) + abs(END_X)) / STEP_X;
    int nn = (abs(START_N) + abs(END_N)) / STEP_N;
    double ref[nx], r[nn][nx];

    // filling reference array
    for (int i = 0; i < nx; i++) ref[i] = exp(START_X + i * STEP_X);

    // filling experimental array
    for (int i = 0; i < nn; i++)
        for (int j = 0; j < nx; j++)
            r[i][j] = expo(START_X + j * STEP_X, START_N + i * STEP_N);

    // computing length for table
    size_t columnLengths[nx + 1];
    columnLengths[0] = max(getIntLen(START_N), getIntLen(END_N));
    for (int i = 0; i < nx; i++) {
        size_t l = max(getLen(ref[i]), getLen(START_X + i * STEP_X));
        for (int j = 0; j < nn; j++) {
            size_t _l = getLen(r[j][i]);
            if (_l > l) l = _l;
        }
        columnLengths[i + 1] = l;
    }
    size_t totalLength = sum(columnLengths, nx + 1) + nx + 6;

    // Printing table
    printlnCharNTimes('#', totalLength);
    // x
    printColumn(0, 1);
    printCharNTimes(' ', columnLengths[0]);
    printColumn(1, 1);
    for (int i = 0; i < nx; i++) printPadded(START_X + i * STEP_X, columnLengths[i + 1]);
    printColumn(0, 0);
    printf("\n");
    printlnCharNTimes('#', totalLength);

    // reference
    printColumn(0, 1);
    printCharNTimes(' ', columnLengths[0]);
    printColumn(1, 1);
    for (int i = 0; i < nx; i++) printPadded(ref[i], columnLengths[i + 1]);
    printColumn(0, 0);
    printf("\n");
    printlnCharNTimes('#', totalLength);
    // experimental
    for (int i = 0; i < nn; i++) {
        printColumn(0, 1);
        printPadded(START_N + i * STEP_N, columnLengths[0]);
        printColumn(0, 1);
        for (int j = 0; j < nx; j++) printPadded(r[i][j], columnLengths[j + 1]);
        printColumn(0, 0);
        printf("\n");
    }
    printlnCharNTimes('#', totalLength);

    return 0;
}
