#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <limits.h> =
#define MASS_COUNT 10


int getMassiveMinValue(const int[]);
int getMassiveMaxValue(const int[]);
void printMassive(const int[]);
void switchMassiveValues(int[]);
void randomizeMassive(int[]);


int main(int argc, const char* argv[]) {

    int mass[MASS_COUNT] = { 0 };
    int maxv, minv;

    randomizeMassive(mass);
    printf("Your massive:\t");
    printMassive(mass);
    minv = getMassiveMinValue(mass);
    printf("Min value:\t\t%d\n", minv);

    maxv = getMassiveMaxValue(mass);
    printf("Max value:\t\t%d\n", maxv);

    switchMassiveValues(mass);
    printf("New massive:\t");
    printMassive(mass);


    return 0;
}

void randomizeMassive(int mass[]) {
    unsigned seed = (unsigned)time(NULL);
    srand(seed);
    for (int i = 0; i < MASS_COUNT; i++)
    {
        mass[i] = rand() % 100;
    }
}

void printMassive(const int mass[]) {
    for (int i = 0; i < MASS_COUNT; i++) {
        printf("%d ", mass[i]);
    }
    printf("\n");
}


int getMassiveMaxValue(const int mass[])
{ 
    int max = INT_MIN;
    for (int i = 0; i < MASS_COUNT; i++)
    {
        if (mass[i] > max) max = mass[i];
    }

    return max;
}

int getMassiveMinValue(const int mass[]) {
    int min = INT_MAX;
    for (int i = 0; i < MASS_COUNT; i++) {
        if (mass[i] < min) min = mass[i];
    }

    return min;
}

void switchMassiveValues(int mass[]) {
    int max = INT_MIN, maxindex = 0;
    int min = INT_MAX, minindex = 0; 

    for (int i = 0; i < MASS_COUNT; i++) {
        if (mass[i] > max)
        {
            max = mass[i];
            maxindex = i;
        }
    }

    for (int i = 0; i < MASS_COUNT; i++) {
        if (mass[i] < min)
        {
            min = mass[i];
            minindex = i;
        }
    }

    mass[minindex] = max;
    mass[maxindex] = min;

}