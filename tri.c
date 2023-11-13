#include <stdio.h>
#include <time.h>
#include "outils.h"

void swap(int64_t t[], int a, int b) {
    if (a == b) return;
    int64_t _t = t[a];
    t[a] = t[b];
    t[b] = _t;
}

void selection_sort(int n, int64_t t[n]) {
    for (int i = 0; i < n - 1; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++) {
            if (t[j] < t[min]) min = j;
        }
        swap(t, i, min);
    }
}

void insertion_sort(int n, int64_t t[n]) {
    for (int i = 1; i < n; i++) {
        int x = t[i];
        int j = i;
        while (j > 0 && t[j - 1] > x) {
            t[j] = t[j - 1];
            j--;
        }
        t[j] = x;
    }
}

int partition(int64_t t[], int start, int end, unsigned short alt) {
    int j;
    if (!alt) {
        j = start;
        int64_t pivot = t[end];
        for (int i = start; i < end; i++) {
            if (t[i] <= pivot) {
                swap(t, i, j);
                j++;
            }
        }
    } else {
        int i = start;
        j = end;
        int64_t pivot = t[end];
        while (i < j) {
            while (t[i] <= pivot && i < j) i++;
            while (t[j] >= pivot && i < j) j--;
            swap(t, i, j);
        }
    }
    swap(t, j, end);
    return j;
}

void compute_fast_sort(int64_t t[], int start, int end, unsigned short alt) {
    if (start >= end) return;
    //printf("%i %i %hu\n", start, end, alt);
    int p = partition(t, start, end, alt);
    compute_fast_sort(t, start, p - 1, alt);
    compute_fast_sort(t, p + 1, end, alt);
}

void fast_sort(int n, int64_t t[n], unsigned short alt) {
    compute_fast_sort(t, 0, n - 1, alt);
}

void printExecTime(char * name, clock_t start) {
    clock_t now = clock();
    printf("%s took %li ms\n", name, now - start);
}

int main() {
    int lengths[] = {100, 1000, 5000, 10000, 50000, 100000, 500000};
    int n = 7;
    option_t opt = MONOTONE_DECR;
    for (int i = 0; i < n; i++) {
        int l = lengths[i];
        printf("Exec times for length = %i\n", l);
        int64_t t[l];
        clock_t start = clock();
        initialiser(l, t, opt);
        selection_sort(l, t);
        //afficherVecteur(l, t);
        verifier(l, t);
        printExecTime("Selection Sort", start);
        start = clock();
        initialiser(l, t, opt);
        insertion_sort(l, t);
        //afficherVecteur(l, t);
        verifier(l, t);
        printExecTime("Insertion Sort", start);
        start = clock();
        initialiser(l, t, opt);
        fast_sort(l, t, 0);
        //afficherVecteur(l, t);
        verifier(l, t);
        printExecTime("Fast Sort", start);
        start = clock();
        initialiser(l, t, opt);
        fast_sort(l, t, 1);
        //afficherVecteur(l, t);
        verifier(l, t);
        printExecTime("Fast Sort (ALT)", start);
        printf("\n");
    }
    return 0;
}
