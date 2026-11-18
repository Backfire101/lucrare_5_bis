/*
15. Se dă un şir de caractere care se termină cu caracterul EOF. Să se scrie un program C care converteşte un şir de caractere cifră în întregul corespunzător, restul caracterelor sunt neglijate.
Ex: Şirul ",ab 15 cd1;489$%"
Numerele: 15 1 489
*/

#define _CRT_SECURE_NO_WARNINGS  1
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>
#include <string.h>
#include "array_read_write.h" 
#include "probleme.h"

void problema_15()
{
	printf("Introduceti textul (terminati cu CTRL+Z pe un rand nou): ");

	int ch;
	int number = 0;
	bool in_number = false;
	bool found_any = false;

	while ((ch = getchar()) != EOF)
	{
		if (ch >= '0' && ch <= '9')
		{
			number = number * 10 + (ch - '0');
			in_number = true;
		}
		else if (in_number)
		{
			if (!found_any)
			{
				printf("Numerele: ");
				found_any = true;
			}
			printf("%d ", number);
			number = 0;
			in_number = false;
		}
	}

	if (in_number)
	{
		if (!found_any)
		{
			printf("Numerele: ");
			found_any = true;
		}
		printf("%d ", number);
	}

	if (!found_any)
	{
		printf("Nu sunt numere in sir!");
	}

	printf("\n");

	clearerr(stdin);
}