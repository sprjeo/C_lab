#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

#define FILEPATH_SIZE 256

int main(int argc, const char* argv[]) {
    FILE* input_file = NULL;
    int  userSelectedItem = 0, massiveLenght = 0, loadCounter = 0, i = 0;
    long currentNumber, firstMassive[128], secondMassive[128], cacheValue, maxValue = LONG_MIN, maxIndex = -1, sum = 0;
    char flag = 0;
    char* filepath, * currentString;

    printf("input flag:\n");
     scanf("%c", &flag);
     filepath = calloc(FILEPATH_SIZE, sizeof(char));
    printf("input path to file:\n");
    scanf("%s", filepath);
    

    if (flag == 'c' || flag == 'd' || flag == 'e')
    {
        printf("\nInput index of the massive element:\n");
        scanf("%d", &userSelectedItem);
        if (userSelectedItem < 0 || userSelectedItem >= 128) printf("Incorrect index");
    }

    if (!(input_file = fopen(filepath, "r"))) {
        printf("Input file not opened\n");
        return -1;
    }
    free(filepath);


    currentString = malloc(sizeof(double));
    while (!feof(input_file))
    {
        fscanf(input_file, "%s", currentString);
        if (sscanf(currentString, "%ld", &currentNumber) != 1) continue;

        firstMassive[massiveLenght++] = currentNumber;
    }
    free(currentString);





    switch (flag)
    {
    case 'a':
        for (i = 0; i < massiveLenght; i++)
        {
            if (i % 2 == 1) secondMassive[loadCounter++] = firstMassive[i];
        }
        break;



    case 'b':
        for (i = 0; i < massiveLenght; i++)
        {
            if (firstMassive[i] % 2 == 0) secondMassive[loadCounter++] = firstMassive[i];
        }
        break;



    case 'c':
        for (i = 0; i < massiveLenght; i++)
        {
            if (i == userSelectedItem) continue;

            cacheValue = labs(firstMassive[userSelectedItem] - firstMassive[i]);
            if (cacheValue > maxValue)
            {
                maxValue = cacheValue;
                maxIndex = i;
            }
        }

        if (maxIndex != -1) secondMassive[loadCounter++] = firstMassive[maxIndex];
        break;



    case 'd':
        for (i = userSelectedItem - 1; i >= 0; i--)
        {
            sum += firstMassive[i];
        }

        if (sum != 0) secondMassive[loadCounter++] = sum;
        break;



    case 'e':
        for (i = 0; i < massiveLenght; i++)
        {
            if (i == userSelectedItem) continue;


            if (firstMassive[i] < firstMassive[userSelectedItem])
            {
                sum += firstMassive[i];

            }
        }
        if (sum != 0) secondMassive[loadCounter++] = sum;
        break;
    }


    printf("\nYour new massive:\n");
    for (i = 0; i < loadCounter; i++)
    {
        printf("%ld\t", secondMassive[i]);
        if (i % 5 == 4) printf("\n");
    }


    fclose(input_file);
    printf("\n");

    return 0;
}
