#ifndef AUDIO_ENGINE_H
#define AUDIO_ENGINE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

typedef struct {
    char Notename[2];
    unsigned int fmtCode;
    unsigned int fmtChannels;
    uint32_t fmtSampleRate;
    uint32_t fmtByteRate;
    unsigned int fmtBlockAlign;
    unsigned int fmtBitsPerSample;
}WavData;



int ReadNote(void);

#endif // AUDIO_ENGINE_H