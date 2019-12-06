# tiny-wav
Extremely lightweight WAV-file encoder written in C

## Usage
`tiny-wave` offers one function:
```
extern void encodeWAV(FILE *output, short *left, short *right, unsigned int length);
```
where:
```
FILE *output = file that the WAV will be written to
short *left = left channel WAV data
short *right = right channel WAV data
unsigned int length = number of samples (not total, in each channel)
```
`encodeWAV` will close `output`.

The quality of the WAV is fixed at 16 bits with a sample rate of 44.1kHz which gives it a bitrate of around 1,378kbps. This is equivalent to CD quality.

For more info about usage, take a look at `demo.c`.
