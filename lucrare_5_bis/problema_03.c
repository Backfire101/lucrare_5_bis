/*
3. Să se scrie un program care citește de la tastatură un număr N natural, apoi citește cele N elemente ale unui șir de numere naturale. 
Programul va determina minimul dintre elementele negative aflate pe poziții pare din cadrul tabloului, respectiv maximul dintre elementele pozitive aflate pe poziții impare.
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

void problema_03()
{
	int array[MAX_ARRAY];
	int size;
	read_array(array, INTEGER, ARRAY_1D, &size, NULL);

	int minimum = INT_MAX;
	int maximum = INT_MIN;

	bool pozitive_exists = false; 
	bool negative_exists = false;

	for (int i = 0; i < size; i++)
	{
		if (i % 2 == 1 && array[i] > 0)
			maximum = MAX(maximum, array[i]), pozitive_exists = true;
		
		if ( i % 2 == 0 && array[i] < 0)
			minimum = MIN(minimum, array[i]) , negative_exists = true;
	}

	if (negative_exists)
		printf("Minimul dintre numerele negative de pe pozitii pare este: %d\n", minimum);
	else
		printf("Nu sunt numere negative pe pozitii pare!\n");

	if (pozitive_exists)
		printf("Maximul dintre numere pozitive de pe pozitii impare este: %d\n", maximum);
	else
		printf("Nu sunt numere pozitive pe pozitii impare!\n");
}