#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

#define STRING_LEN 256

int getMassiveSize(char*);

int main(int argc, const char* argv[]) {

    char* collumn1, * collumn2, * collumn3, * inputFile_path, c;
    long positionInFile, positionInFile_Cache;
    FILE* inputFile = NULL;

    inputFile_path = calloc(STRING_LEN, sizeof(char));
    printf("Input file path:\n");
    scanf("%s", inputFile_path);


    if (argc != 2) {
        printf("Invalid arguments\n");
        return 1;
    }

    if (!(inputFile = fopen(inputFile_path, "r+"))) {
        free(inputFile_path);
        printf("Input file not opened");
        return -1;
    }

    free(inputFile_path);

    collumn1 = calloc(STRING_LEN, sizeof(char));
    collumn2 = calloc(STRING_LEN, sizeof(char));
    collumn3 = calloc(STRING_LEN, sizeof(char));

    while (!feof(inputFile))
    {
        
        positionInFile_Cache = ftell(inputFile);
        fscanf(inputFile, "%s%s%s", collumn1, collumn2, collumn3);
        positionInFile = ftell(inputFile);
        fseek(inputFile, -(positionInFile - positionInFile_Cache), SEEK_CUR); 

        fwrite(collumn3, sizeof(char), getMassiveSize(collumn3), inputFile);
        fwrite("\t", sizeof(char), sizeof(char), inputFile);

        fwrite(collumn1, sizeof(char), getMassiveSize(collumn1), inputFile);
        fwrite("\t", sizeof(char), sizeof(char), inputFile);

        fwrite(collumn2, sizeof(char), getMassiveSize(collumn2), inputFile);
        fwrite("\n", sizeof(char), sizeof(char), inputFile);

      
        if ((c = fgetc(inputFile) == EOF)) break;
        fseek(inputFile, -1, SEEK_CUR);
    }


    printf("%s", "File updated\n");
    free(collumn1);
    free(collumn2);
    free(collumn3);
    fclose(inputFile);
    return 0;
}

int getMassiveSize(char* mass)
{
    int counter = 0;
    while (mass[counter] != '\0') counter++;
    return counter;
}

