/*
1. Se consideră un tablou de N elemente întregi (N fiind citit de la tastatură). 
Să se realizeze următoarele operații asupra elementelor tabloului:
- să se citească elementele tabloului
- să se afișeze elementele tabloului
- să se afișeze suma elementelor pare respectiv suma elementelor impare
- să se afișeze mimimul elementelor tabloului
- să se calculeze produsul elementelor tabloului
- să se afișeze elementele tabloului sortat descrescător
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

int compare(const void* a, const void* b)
{
	return -(*(int*)a - *(int*)b);
}

void problema_01()
{
	int array[MAX_ARRAY];
	int size;
	read_array(array, INTEGER, ARRAY_1D, &size, NULL);
	print_array(array, INTEGER, ARRAY_1D, size, 0, NULL);

	int minimum = INT_MAX;
	int maximum = INT_MIN;
	int sum_odd = 0;
	int sum_even = 0;
	long long product = 1;

	for (int i = 0; i < size; i++)
	{
		product *= array[i];

		minimum = MIN(minimum, array[i]);
		maximum = MAX(maximum, array[i]);

		if (array[i] % 2 == 0)
			sum_even += array[i];
		else
			sum_odd += array[i];
	}

	printf("Minimul din tablou este: %d\nMaximul din tablous este: %d\nSuma numerelor pare din tablou este: %d\nSuma numerelor impare din tablou este: %d\nProdusul elementelor din tablou este: %lld\n", minimum, maximum, sum_even, sum_odd, product);

	qsort(array, size, sizeof(int), compare);
	print_array(array, INTEGER, ARRAY_1D, size, 0, "Tabloul sortat descrescator este: ");
}