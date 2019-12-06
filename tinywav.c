#include "tinywav.h"

void encodeWAV(FILE *output, uint16_t *left, uint16_t *right, unsigned int length) {
	
	/* Chunk ID for the whole file. "RIFF" */
	fputc('R', output);
	fputc('I', output);
	fputc('F', output);
	fputc('F', output);
	
	/* Chunk size; size of file except this field and the previous one (-8) */
	unsigned int chunkSz = 36 + length * 4;
	fputc((chunkSz >> 24) & 0xFF, output);
	fputc((chunkSz >> 16) & 0xFF, output);
	fputc((chunkSz >> 8) & 0xFF, output);
	fputc(chunkSz & 0xFF, output);
	
	/* Format. "WAVE" */
	fputc('W', output);
	fputc('A', output);
	fputc('V', output);
	fputc('E', output);
	
	/* Subchunk ID. "fmt " */
	fputc('f', output);
	fputc('m', output);
	fputc('t', output);
	fputc(' ', output);
	
	/* Subchunk size. Fixed at 16. */
	fputc(0, output);
	fputc(0, output);
	fputc(0, output);
	fputc(16, output);
	
	/* Audio format, 1 for LPCM */
	fputc(0, output);
	fputc(1, output);
	
	/* Number of channels. */
	fputc(0, output);
	fputc(2, output);
	
	/* Sample rate. */
	fputc(0, output);
	fputc(0, output);
	fputc(0xAC, output);
	fputc(0x44, output);
	
	/* Byte rate. */
	fputc(0x00, output);
	fputc(0x02, output);
	fputc(0xB1, output);
	fputc(0x10, output);
	
	/* Block alignment, e.g. how many bytes for one sample from every channel. */
	fputc(0x00, output);
	fputc(0x04, output);
	
	/* Bits per sample. */
	fputc(0x00, output);
	fputc(0x02, output);
	
	/* Subchunk 2 ID. "data" */
	fputc('d', output);
	fputc('a', output);
	fputc('t', output);
	fputc('a', output);

	/* Subchunk 2 size. Data size. */
	fputc((length >> 24) & 0xFF, output);
	fputc((length >> 16) & 0xFF, output);
	fputc((length >> 8) & 0xFF, output);
	fputc(length & 0xFF, output);
	
	/* Actual data. */
	for(unsigned int i = 0; i < length; i++) {
		fputc((left[i] >> 8) & 0xFF, output);
		fputc(left[i] & 0xFF, output);
		fputc((right[i] >> 8) & 0xFF, output);
		fputc(right[i] & 0xFF, output);
	}
	
	fclose(file);
	
}
