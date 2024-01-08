#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>

double geometric_mean(int count, ...)
{
    va_list args;
    double product = 1.0, num;
    int arg_count_error = 0, arg_negative_numbers_err = 0, i;

    if (count == 0)
    {
        return 1;
    }

    va_start(args, count);

    for (i = 0; i < count; i++)
    {
        num = va_arg(args, double);
        if (num < 0)
        {
            arg_negative_numbers_err++;
        }
        product *= num;
    }

    va_end(args);


    if (arg_negative_numbers_err % 2 != 0)
    {
        return 2;
    }


    return pow(product, 1.0 / count);
}



long power(long num, long deg)
{
    long result = 1;
    while (deg)
    {
        if (deg % 2 == 0)
        {
            deg /= 2;
            num *= num;
        }
        else
        {
            deg--;
            result *= num;
        }
    }

    return result;
}

double power1(long num, long deg)
{
    double result = 1;
    if (deg < 0)
    {
        deg = -deg;

        while (deg)
        {
            if (deg % 2 == 0)
            {
                deg /= 2;
                num *= num;
            }
            else
            {
                deg--;
                result *= num;
            }
        }

        return 1 / result;
    }
    else
    {
        while (deg)
        {
            if (deg % 2 == 0)
            {
                deg /= 2;
                num *= num;
            }
            else
            {
                deg--;
                result *= num;
            }
        }

        return result;
    }
}

int main()
{
    long num;
    long deg;
    printf("Enter number:\n");
    scanf("%d", &num);
    printf("Enter degree:\n");
    scanf("%d", &deg);
    if (deg > 0)
    {
        long i = power(num, deg);
        printf("%i\n", i);
    }
    if (deg < 0)
    {
        double i = power1(num, deg);
        printf("%f\n", i);
    }

    double j = geometric_mean(3, 2.5, 3.5, 3.0);
    printf("%f", j);

}




