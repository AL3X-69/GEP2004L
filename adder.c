#include <stdio.h>
#include <stdint.h>

uint8_t full_adder(uint8_t a, uint8_t b, uint8_t *c) {
    uint8_t t1 = a ^ b;
    uint8_t s = t1 ^ *c;
    *c = (a & b) | (t1 & *c);
    return s;
}

uint8_t add8(uint8_t a, uint8_t b) {
    uint8_t c = 0, r = 0;
    for (int i = 0; i < 8; i++) {
        uint8_t shiftedA = a >> i & 1, shiftedB = b >> i & 1;
        uint8_t s = full_adder(shiftedA, shiftedB, &c);
        r = r | (s << i);
    }
    return r;
}

int main() {
    int a = 120, b = 87, c = -25, d = 10;

    printf("%4i + %4i = %4hhi (valeur correcte = %4i)\n", a, b, add8(a, b), a + b);
    printf("%4i + %4i = %4hhi (valeur correcte = %4i)\n", c, d, add8(c, d), c + d);
}
