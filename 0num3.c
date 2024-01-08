#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#define STRING_LEN 256 

void flagd(FILE* fi1, FILE* fi2)
{
	char ch;
	while ((ch = fgetc(fi1)) != EOF) {
		if (!isdigit(ch)) {
			fputc(ch, fi2);
		}
	}
}
void flagi(FILE* fi1, FILE* fi2)
{
	char ch;
	int c = 0;
	while ((ch = fgetc(fi1)) != EOF) {
		if (isalpha(ch)) {
			++c;
		}
		if (ch == '\n') {
			fputc(c + '0', fi2);
			fputc('\n', fi2);
			c = 0;
		}
	}
	fputc(c + '0', fi2);
}
void flags(FILE* fi1, FILE* fi2)
{
	char ch;
	int c = 0;
	while ((ch = fgetc(fi1)) != EOF) {
		if (!isalnum(ch) && ch != ' ') {
			++c;
		}
		if (ch == '\n') {
			fputc(c + '0', fi2);
			fputc('\n', fi2);
			c = 0;
		}
	}
	fputc(c + '0', fi2);
}
void flaga(FILE* fi1, FILE* fi2)
{
	char ch;
	while ((ch = fgetc(fi1)) != EOF) {
		if (!isdigit(ch)) {
			fprintf(fi2, "%d", ch);
		}
	}
}
void flagf(FILE* fi1, FILE* fi2)
{
	int count = 1;
	char c;
	while ((c = getc(fi1)) != EOF) {
		while (c != '\n') {
			if (count % 2 == 0) {
				if (isalpha(c)) {
					c = tolower(c);
				}
			}
			if (count % 5 == 0) {
				fprintf(fi2, "%d", c);
			}
			else {
				fprintf(fi2, "%c", c);
			}
			c = getc(fi1);
		}
		fprintf(fi2, "\n");
		++count;
	}
}

int main(int argc, char* argv[])
{
	FILE* fi1 = NULL;
	FILE* fi2 = NULL;
	fopen_s(&fi1, argv[2], "r");
	char* cond = argv[1];
	if (cond[0] == '-' || cond[0] == '/') {
		if (cond[1] == 'n')
		{
			fopen_s(&fi2, argv[3], "w");
			switch (cond[2])
			{
			case 'd':
				flagd(fi1, fi2);
				break;
			case 'i':
				flagi(fi1, fi2);
				break;
			case 's':
				flags(fi1, fi2);
				break;
			case 'a':
				flaga(fi1, fi2);
				break;
			case 'f':
				flagf(fi1, fi2);
				break;
			}
		

		}
		if (cond[1] != 'n' && argc <= 3) {
			fopen_s(&fi2, "out_.txt", "w");
			switch (cond[1])
			{
			case 'd':
				flagd(fi1, fi2);
				break;
			case 'i':
				flagi(fi1, fi2);
				break;
			case 's':
				flags(fi1, fi2);
				break;
			case 'a':
				flaga(fi1, fi2);
				break;
			case 'f':
				flagf(fi1, fi2);
				break;
			}
		}
	}
	else {
		printf("‘лаг не найден");
	}
}