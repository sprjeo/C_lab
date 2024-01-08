#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

#define STRING_LEN 256


void appendFileFromAnother(const char* inputfile_name, FILE* outputFile);

int main(int argc, const char* argv[]) {

    FILE* outputFile = NULL, * fileslistFile = NULL;
    char* currentFile_path, * outputFile_path;
    int i;


    if (argc < 2)
    {
        printf("Invalid arguments\n");
        return 1;
    }

    outputFile_path = calloc(STRING_LEN, sizeof(char));
    printf("Input output file path:\n");
    scanf("%s", outputFile_path);

    if (!(outputFile = fopen(outputFile_path, "w"))) {
        printf("Output file not opened\n");
        return -1;
    }


    currentFile_path = calloc(STRING_LEN, sizeof(char));

    if (!strcmp(argv[1], "-fi") || !strcmp(argv[1], "/fi"))
    {
        if (!(fileslistFile = fopen(argv[2], "r")))
        {
            fclose(outputFile);
            printf("Input file not opened\n");
            return -1;
        }

        while (!feof(fileslistFile))
        {
            fscanf(fileslistFile, "%s", currentFile_path);
            appendFileFromAnother(currentFile_path, outputFile);
        }

        printf("Output file created\n");
    }


    if (!strcmp(argv[1], "-cin") || !strcmp(argv[1], "/cin"))
    {
        while (1)
        {
            printf("Input filepath (Stop to exit):\n");
            scanf("%s", currentFile_path);
            if (!strcmp(currentFile_path, "Stop")) break;

            appendFileFromAnother(currentFile_path, outputFile);
        }

        printf("Output file created\n");
    }


    if (!strcmp(argv[1], "-arg") || !strcmp(argv[1], "/arg"))
    {
        for (i = 2; i < argc; i++)
        {
            appendFileFromAnother(argv[i], outputFile);

        }

        printf("Output file created\n");
    }


    free(currentFile_path);
    fclose(outputFile);
    return 0;
}


void appendFileFromAnother(const char* inputFile_path, FILE* outputFile)
{
    FILE* inputFile = NULL;
    char ch;

    if (!(inputFile = fopen(inputFile_path, "r"))) {
        printf("Input file not opened\n");
        return;
    }

    while ((ch = fgetc(inputFile)) != EOF)
    {
        fputc(ch, outputFile);
    }

    fclose(inputFile);
}