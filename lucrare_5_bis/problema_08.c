/*
8. Să se scrie un program care citește de la tastatură un șir N de numere întregi și inserează la mijlocul șirului media aritmetică a elementelor sale.
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

void problema_08()
{
	int array[MAX_ARRAY];
	int size;

	read_array(array, INTEGER, ARRAY_1D, &size, NULL);

	int sum = 0;
	for (int i = 0; i < size; i++)
		sum += array[i];
	
	for (int i = size; i > size / 2; i--)
		array[i] = array[i - 1];
	array[size / 2] = sum / size ;
	size++;

	print_array(array, INTEGER, ARRAY_1D, size, NULL, "Matricea modificata este:\n");
}