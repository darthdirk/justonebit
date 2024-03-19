
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdint.h>

#define BITVALUE(x, n) (((x) >> (n)) & 0x1)

#define READONLY    0x1    //00000001
#define HIDDEN      0x2    //00000010
#define SYSTEM      0x4    //00000100
#define VOL_LABEL   0x8    //00001000
#define SUBDIR      0x10   //00010000
#define ARCHIVE     0x20   //00100000


void printBitInfo(uint32_t x) {
    printf("x = %d\n", x);

    int numbits = sizeof(x) * 8;
    for (int i = 0; i < numbits; i++) {
        // Prints the binary in High order bits first 
        // otherwise (x, i));
        printf("%d", BITVALUE(x, numbits - 1 - i));
    }
    printf("\n");

    if (x & READONLY) {
        printf("read only! \n");
    }

    if (x & HIDDEN) {
        printf("hidden! \n");
    }

    if (x & SYSTEM) {
        printf("system! \n");
    }
}

int main(void) {
    uint32_t x = 42; //101010
    printBitInfo(x);

    x = x | SYSTEM;   // Sets but x |= SYSTEM; is more elegent  
    x = x & ~HIDDEN;  // Clears  x &= ~HIDDEN;
    x = x ^ READONLY; // Toggle  x ^= READONLY;

    printBitInfo(x);
    return EXIT_SUCCESS;
}