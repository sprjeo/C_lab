#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <math.h>

int main( int argc, char *argv[])
{
	int value, primality_flag, value1, ten, sum, factorial;
	
	if (argc != 3)
	{
		printf("incorrect number of arguments");
	}
	
	else
	{
		value = atoi(argv[1]);

		if (value <= 0)
			printf("incorrect number");
		
		else if ((strcmp(argv[2], "-h") == 0) || (strcmp(argv[2], "/h") == 0))
		{
			if (value > 100)
				printf("there are no multiples within 100");
			else
			{
				for (int i = 1; i <= 100; i++)
				{
					if (value * i <= 100)
						printf("%d\t", value * i);
				}
			}
			
		}
		else if ((strcmp(argv[2], "-p") == 0) || (strcmp(argv[2], "/p") == 0))
		{
			if (value == 1)
			{
				printf("Nor prime neither composite\n");
			}
			else if (value == 2 )
			{
				printf("prime\n");
			}
			else if (value % 2 == 0)
			{
				printf("composite\n");
			}
			else
			{
				primality_flag = 1;
				for (int i = 3; i <= value; i += 2)
				{
					if (value % i == 0)
					{
						primality_flag = 0;
						break;
					}
					if (primality_flag == 0)
					{
						printf("composite\n");
						break;
					}
					else
					{
						printf("prime\n");
						break;
					}

				}
			}
			

		}
		else if ((strcmp(argv[2], "-s") == 0) || (strcmp(argv[2], "/s") == 0))
		{
			ten = 1;
			value1 = value;
			while (value1 != 0)
			{
				value1 = value1 / 10;
				ten = (ten * 10);
			}
			if (ten != 10)
			{
				ten = ten / 10;
			
				while (ten > 0)
				{
					printf("%d\t", (value / ten));
					value = value - (value / ten) * ten;
					ten = ten / 10;

				}
			}
			else
			{
				printf("%d", value);
			}

			//for (int i = ; i == 0; i/10 )
		}
		else if ((strcmp(argv[2], "-e") == 0) || (strcmp(argv[2], "/e") == 0))
		{
			if (value > 10)
			{
				printf("number greater than 10");
			}
			else
			{
				for (int i = 1; i <= 10; i= i++ )
				{
					for (int j = 1; j <= value; j++)
					{
						printf("%.0f\t", pow(i, j));		
					}
					printf("\n");
				}
			}
		}
		else if ((strcmp(argv[2], "-a") == 0) || (strcmp(argv[2], "/a") == 0))
		{
			sum = 0;
			for (int i = 1; i <= value; i++)
			{
				sum = sum + i;
			}
			printf("%d", sum);	
		}
		else if ((strcmp(argv[2], "-f") == 0) || (strcmp(argv[2], "/f") == 0))
		{
			factorial = 1;
			for (int i = 1; i <= value; i++)
			{
				factorial = factorial * i;
			}
			printf("%d", factorial);
		}
		else
		{
			printf("unknown flag");
		}
	}
	return 0;
}