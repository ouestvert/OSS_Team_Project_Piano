#include "raylib.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

struct Wavfile{
    char ChunkID[4];
    int ChunkSize;
    char Format[4];
    char Subchunk1ID[5];
    int32_t Subchunk1Size;
    int AudioFormat;
    int NumChannels;
    uint32_t SampleRate;
    uint32_t ByteRate;
    uint16_t BlockAlign;
    uint16_t BitsPerSample;
    char Subchunk2ID[5];
    uint32_t Subchunk2Size;
    int32_t *Samples;
    int32_t SampleSize;
} Result[13];






int Little(char data[], int size){
    int result = 0;
    for(int i= size-1; i>=0; i--){

        result = result*256 + (unsigned char)data[i];
    }
    return result;
}


// 4 id  4 s /2 2 4 4 2 2/
// Read SubChunk1
int ReadSC1(FILE *in, int i){
    
    char Subchunk1[24] = {0};
    char Fmtcheck[5] = {0};
    int found = 0;

    while (fread(Fmtcheck, sizeof(char), 4, in) == 4) {
        if (strcmp(Fmtcheck, "fmt ") == 0) {
            found = 1;
         break;
        }

        fseek(in, -3, SEEK_CUR);
        
    }

    if (found == 0) {
        printf("Error: Could not find 'fmt ' chunk.\n");
        return 1;
    }

    fseek(in, -4, SEEK_CUR);

    fread(Subchunk1, sizeof(char), 24, in);
    
    strcpy_s(Result[i].Subchunk1ID, sizeof(Result[i].Subchunk1ID), Fmtcheck);   
    Result[i].Subchunk1Size = Little(&Subchunk1[4], 4);
    Result[i].AudioFormat = Little(&Subchunk1[8], 2);
    Result[i].NumChannels = Little(&Subchunk1[10], 2);
    Result[i].SampleRate = Little(&Subchunk1[12], 4);
    Result[i].ByteRate = Little(&Subchunk1[16], 4);
    Result[i].BlockAlign = Little(&Subchunk1[20], 2);
    Result[i].BitsPerSample = Little(&Subchunk1[22], 2);
    printf("Chunk ID: %s\n", Subchunk1);
    printf("subchunk1size: %d\n", Result[i].Subchunk1Size);
    printf("audioformat: %d\n", Result[i].AudioFormat);
    printf("numchannels: %d\n", Result[i].NumChannels);
    printf("samplerate: %d\n", Result[i].SampleRate);
    printf("Byterate: %d\n", Result[i].ByteRate);
    printf("blockalign: %d\n", Result[i].BlockAlign);
    printf("bitspersample: %d\n", Result[i].BitsPerSample);
    return 0;

}

int ReadSC2(FILE *in, int i){
    char DataCheck[5] = {0};
    char Subchunk2[8] = {0};
    int found = 0;
    while (fread(DataCheck, sizeof(char), 4, in) == 4) {
        if (strcmp(DataCheck, "data") == 0) {
            found = 1;
            break;
        }

        fseek(in, -3, SEEK_CUR);
        
    }

    if (found == 0) {
        printf("Error: Could not find 'fmt ' chunk.\n");
        return 1;
    }

    fseek(in, -4, SEEK_CUR);

    fread(Subchunk2, sizeof(char), 8, in);
    

    
    strcpy_s(Result[i].Subchunk2ID, sizeof(Result[i].Subchunk2ID), DataCheck);   
    Result[i].Subchunk2Size = Little(&Subchunk2[4], 4);
    printf("\nChunk ID: %s\n", Subchunk2);
    printf("%d\n", Result[i].Subchunk2Size);
    return 0;
}

int Check_Header(FILE *in){
    char Header[12] ={0};
    fread(Header, sizeof(char), 12, in);
    
    if(strncmp(Header, "RIFF", 4) != 0|| strncmp(&Header[8], "WAVE", 4) != 0){
        printf("Error: Not a valid WAV file (Missing 'RIFF' header)\n");
        return 1;
    }

   
    return 0;
}
    

int ReadWav(){
    FILE *in[13];
    
    in[0] = fopen("asset/note/C4.wav", "rb");
    in[1] = fopen("asset/note/C#4.wav", "rb");
    in[2] = fopen("asset/note/D4.wav", "rb");
    in[3] = fopen("asset/note/D#4.wav", "rb");
    in[4] = fopen("asset/note/E4.wav", "rb");
    in[5] = fopen("asset/note/F4.wav", "rb");
    in[6] = fopen("asset/note/F#4.wav", "rb");
    in[7] = fopen("asset/note/G4.wav", "rb");
    in[8] = fopen("asset/note/G#4.wav", "rb");
    in[9] = fopen("asset/note/A4.wav", "rb");
    in[10] = fopen("asset/note/A#4.wav", "rb");
    in[11] = fopen("asset/note/B4.wav", "rb");
    in[12] = fopen("asset/note/C5.wav", "rb");


    for(int i =0; i<13; i++){
        if(in[i] == NULL){
            printf("Error: Could not open file\n");
            return 1;
        }
        if(Check_Header(in[i]) != 0){
            printf("Error: Check_Header failed in[%d]\n", i);
            return 1;
        }
        if(ReadSC1(in[i], i) != 0){
            printf("Error: ReadSC1 failed in[%d]\n", i);
            return 1;
        }
        if(ReadSC2(in[i], i)!=0){
            printf("Error: ReadSC2 failed in[%d]\n", i);
            return 1;
        }
        






    }






    return 0;
}