#include <stdio.h>
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
} WavFormat[17];


unsigned int Transfer_Bytes( const unsigned char Data[], int x)
{
    int result = 0;
    for(int i =x; i>-1; i--)
    {
        result = result*256 + (unsigned int)Data[i];
    }
    return result;
}

uint32_t Read_FileData(FILE *file)
{
    char chunkID[5];
    unsigned char sizeBytes[4];
    
    // Initialize variables to hold the format information
    unsigned int fmtCode = 0;
    unsigned int fmtChannels = 0;
    uint32_t fmtSampleRate = 0;
    uint32_t fmtByteRate = 0;
    unsigned int fmtBlockAlign = 0;
    unsigned int fmtBitsPerSample = 0;
    
    if(fread(chunkID, 1, 4, file) != 4)
    {
        printf("Failed to read chunk ID.\n");
        fclose(file);
        return 1;
    }
    printf("Chunk ID: %.4s\n", chunkID);
    
    if(fread(sizeBytes, 1, 4, file) != 4)
    {
        printf("Failed to read chunk size.\n");
        return 1;
    }
    
    printf("Chunk Size: %u\n", *(unsigned int*)sizeBytes);
    if(memcmp(chunkID, "fmt ", 4) == 0){


        
        unsigned char fmtData[16];
        if(fread(fmtData, 1, sizeof(fmtData), file) != sizeof(fmtData))
        {
            printf("Failed to read fmt data.\n");
            return 1;
        }
        // chunk data read
        
        fmtCode = Transfer_Bytes(&fmtData[0], 2);
        fmtChannels = Transfer_Bytes(&fmtData[2], 2);
        fmtSampleRate = Transfer_Bytes(&fmtData[4], 4);
        fmtByteRate = Transfer_Bytes(&fmtData[8], 4);
        fmtBlockAlign = Transfer_Bytes(&fmtData[12], 2);
        fmtBitsPerSample = Transfer_Bytes(&fmtData[14], 2);

    }
    else
    {
        printf("Unexpected chunk ID: %.4s\n", chunkID);
    }
    
    printf("\nResult of chunk data read\n");
    printf("Format Code : %u\n", fmtCode);
    printf("Channels : %u\n", fmtChannels);
    printf("Sample Rate : %u\n", fmtSampleRate);
    printf("Byte Rate : %u\n", fmtByteRate);
    printf("Block Align : %u\n", fmtBlockAlign);
    printf("Bits Per Sample : %u\n", fmtBitsPerSample);





    return 0;
}

int FileCheck(FILE *file){
    unsigned char header[12];

    size_t count = fread(header, 1, sizeof(header), file);

    if (count != sizeof(header))
    {
        printf("Failed to read header.\n");
        fclose(file);
        return 1;
    }

    if(memcmp(header, "RIFF", 4)!=0||memcmp(&header[8], "WAVE", 4)!=0)
    {
         printf("Failed to read header RIFF and WAVE.\n");
        fclose(file);
        return 1;
    }
    
    return 0;
}

int ReadNote(void)
{
    FILE *note[17];
    int audioData[17] = {0};
    note[0] = fopen("asset/note/C4.wav", "rb");

    for(int i = 1; i < 17; i++)
    {
       if (note[i] == NULL)
    {
        printf("Failed to open note[%d] file.\n", i);
        return 1;
    }
    }
    
    for(int i = 0; i < 17; i++)
    {
        if(FileCheck(note[i]) == 0)
        {
            Read_FileData(note[i]);
        }
        else 
        {
            printf("FileCheck failed for note[%d].\n", i);
            fclose(note[i]);
            return 1;
        }
    }
    


    
    
    
    fclose(note);
    return 0;
}