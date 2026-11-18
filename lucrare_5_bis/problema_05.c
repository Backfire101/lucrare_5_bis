/*
5. Să se scrie un program care citește de la tastatură un șir N de numere întregi și afișează elementele cu proprietatea că suma cifrelor lor este divizibilă cu o valoare V dată.
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

void problema_05()
{
	int array[MAX_ARRAY];
	int size;

	read_array(array, INTEGER, ARRAY_1D, &size, NULL);
	
	int variable;

	printf("Dati valoare V: ");
	scanf("%d", &variable);

	printf("Numerele cu propietatea ca suma cifrelor se divide cu V sunt:");

	for (int i = 0; i < size; i++)
	{
		int sum = 0;

		int temp_number = abs(array[i]);

		while (temp_number)
		{
			sum += temp_number % 10;
			temp_number /= 10;
		}

		if (sum % variable == 0)
			printf(" %d", array[i]);
	}

	printf("\n");
}