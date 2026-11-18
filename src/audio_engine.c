#include <stdio.h>
#include <string.h>
#include <stdint.h>

typedef struct WavFormatData{
    char Notename[2];
    unsigned int fmtCode;
    unsigned int fmtChannels;
    uint32_t fmtSampleRate;
    uint32_t fmtByteRate;
    unsigned int fmtBlockAlign;
    unsigned int fmtBitsPerSample;
}WavData;

static unsigned int Transfer_Bytes(const unsigned char Data[], int x)
{
    int result = 0;

    for (int i = x-1; i >= 0; i--)
    {
        result = result * 256 + (unsigned int)Data[i];
    }

    return result;
}

static uint32_t Read_FileData(FILE *file, struct WavFormatData *noteData)
{
    char chunkID[5];
    unsigned char sizeBytes[4];

    
    noteData->fmtCode = 0;
    noteData->fmtChannels = 0;
    noteData->fmtSampleRate = 0;
    noteData->fmtByteRate = 0;
    noteData->fmtBlockAlign = 0;
    noteData->fmtBitsPerSample = 0;
    //임시 파일 포인터 이동 추후 더 나은 방식으로 수정 예정(청크의 시작이 junk이고 원하는 fmt가 64byte 이후에 위치하기 때문에)
    fseek(file, 84, SEEK_SET);
    

    if (fread(chunkID, 1, 4, file) != 4)
    {
        printf("Failed to read chunk ID.\n");
        fclose(file);
        return 1;
    }

    

    if (fread(sizeBytes, 1, 4, file) != 4)
    {
        printf("Failed to read chunk size.\n");
        return 1;
    }

    

    if (memcmp(chunkID, "fmt ", 4) == 0)
    {
        unsigned char fmtData[16];

        if (fread(fmtData, 1, sizeof(fmtData), file) != sizeof(fmtData))
        {
            printf("Failed to read fmt data.\n");
            return 1;
        }

        // chunk data read
        noteData->fmtCode = Transfer_Bytes(&fmtData[0], 2);
        noteData->fmtChannels = Transfer_Bytes(&fmtData[2], 2);
        noteData->fmtSampleRate = Transfer_Bytes(&fmtData[4], 4);
        noteData->fmtByteRate = Transfer_Bytes(&fmtData[8], 4);
        noteData->fmtBlockAlign = Transfer_Bytes(&fmtData[12], 2);
        noteData->fmtBitsPerSample = Transfer_Bytes(&fmtData[14], 2);
    }
    else
    {
        printf("Unexpected chunk ID: %.4s\n", chunkID);
        return 1;
    }

    printf("\nResult of chunk data read \n");
    printf("Chunk ID: %.4s\n", chunkID);
    printf("Chunk Size: %u\n", *(unsigned int*)sizeBytes);
    printf("Format Code : %u\n", noteData->fmtCode);
    printf("Channels : %u\n", noteData->fmtChannels);
    printf("Sample Rate : %u\n", noteData->fmtSampleRate);
    printf("Byte Rate : %u\n", noteData->fmtByteRate);
    printf("Block Align : %u\n", noteData->fmtBlockAlign);
    printf("Bits Per Sample : %u\n", noteData->fmtBitsPerSample);

    return 0;
}

static int FileCheck(FILE *file)
{
    unsigned char header[12];

    size_t count = fread(header, 1, sizeof(header), file);

    if (count != sizeof(header))
    {
        printf("Failed to read header.\n");
        fclose(file);
        return 1;
    }

    if (memcmp(header, "RIFF", 4) != 0 ||
        memcmp(&header[8], "WAVE", 4) != 0)
    {
        printf("Failed to read header RIFF and WAVE.\n");
        fclose(file);
        return 1;
    }

    return 0;
}

int ReadNote(void)
{
    FILE *note[13];
    note[0] = fopen("asset/note/C4.wav", "rb");
    note[1] = fopen("asset/note/C#4.wav", "rb");
    note[2] = fopen("asset/note/D4.wav", "rb");
    note[3] = fopen("asset/note/D#4.wav", "rb");
    note[4] = fopen("asset/note/E4.wav", "rb");
    note[5] = fopen("asset/note/F4.wav", "rb");
    note[6] = fopen("asset/note/F#4.wav", "rb");
    note[7] = fopen("asset/note/G4.wav", "rb");
    note[8] = fopen("asset/note/G#4.wav", "rb");
    note[9] = fopen("asset/note/A4.wav", "rb");
    note[10] = fopen("asset/note/A#4.wav", "rb");
    note[11] = fopen("asset/note/B4.wav", "rb");
    note[12] = fopen("asset/note/C5.wav", "rb");
    WavData  noteFormat[13] = {0};
    
    
    
    for (int i = 0; i < 13; i++)
    {
        
        if (FileCheck(note[i]) == 0)
        {
           
            Read_FileData(note[i], &noteFormat[i]);
            fclose(note[i]);
        }
        else
        {
            printf("FileCheck failed for note[%d].\n", i);
            fclose(note[i]);
            return 1;
        }
    }

    
    return 0;
}