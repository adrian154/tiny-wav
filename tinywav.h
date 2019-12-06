#include <stdint.h>
#include <stdio.h>

extern void encodeWAV(FILE *output, uint16_t *left, uint16_t *right, unsigned int length);
