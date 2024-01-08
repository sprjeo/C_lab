#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <math.h>

int main(int argc, char* argv[])
{
	int a, b, c, discriminant;
	double sqrt_d, root1, root2;

	if (argc != 2)
	{
		printf("incorrect number of arguments");
	}
	else if ((strcmp(argv[1], "-q") == 0) || (strcmp(argv[1], "/q") == 0))
	{
		scanf("%d", &a);
		scanf("%d", &b);
		scanf("%d", &c);
		if (a == 0)
		{
			printf("%d", (-c / b));
		}
		else if (a == 0 && b == 0 && c == 0)
		{
			printf("infinite number of solution");
		}
		else
		{
			discriminant = (b * b) - (4 * a * c);
			sqrt_d = sqrt(abs(discriminant));

			if (discriminant > 0)
			{
				root1 = (-b + sqrt_d) / 2 * a;
				root2 = (-b - sqrt_d) / 2 * a;
				printf("%0.f\t%0.f", root1, root2);
			}
			else if (discriminant == 0)
			{
				root1 = -b / 2 * a;
				printf("%0.f", root1);
			}
			else if (discriminant < 0)
			{
				printf("(%d + i*%.0f)/%d\t(%d - i*%.0f)/%d", -b , sqrt_d, 2 * a, -b, sqrt_d, 2 * a) ;
			}
				
		}
	}
	else if ((strcmp(argv[1], "-m") == 0) || (strcmp(argv[1], "/m") == 0))
	{
		scanf("%d", &a);
		scanf("%d", &b);
		if (a != 0 && b != 0)
		{
			if (a % b == 0)
			{
				printf("%d is multiple of %d", a, b);
			}
			else
			{
				printf("%d is not multiple of %d", a, b);
			}
		}
		else
			printf("incorrect numbers");
	}
	else if ((strcmp(argv[1], "-t") == 0) || (strcmp(argv[1], "/t") == 0))
	{
		scanf("%d", &a);
		scanf("%d", &b);
		scanf("%d", &c);
		if (a > 0 && b > 0 && c > 0)
		{
			if (a * a == (b * b + c * c) || b * b == (a * a + c * c) || c * c == (b * b + a * a))
			{
				printf("the entered values can be the sides of a right triangle");
			}
			else
			{
				printf("the entered values cannot be the sides of a right triangle");
			}
		}
		else
		{
			printf("incorrect numbers");
		}
		
	}
	else
	{
		printf("unknown flag");
	}
	
}
