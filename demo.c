#include <stdio.h>
#include <stdlib.h>
#include "tinywav.h"

int main(int argc, char *argv[]) {
	
	FILE *output = fopen("output.wav", "wb");
	
	uint16_t *buffer = malloc(44100 * sizeof(uint16_t));
	for(int i = 0; i < 44100; i++) {
		buffer = (i % 10) == 0 ? 0xFFFF : 0x0000;	
	}
	
	encodeWAV(output, buffer, buffer, 44100);
	
}
