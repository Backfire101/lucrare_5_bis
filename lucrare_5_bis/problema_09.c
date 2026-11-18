/*
9. Să se scrie un program care citește de la tastatură doi vectori a și b cu câte n respectiv m elemente și inserează vectorul b în vectorul a începând de la poziția k (k citit de la tastatură).
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

void problema_09()
{
	int array_a[MAX_ARRAY];
	int array_b[MAX_ARRAY];
	int size_a;
	int size_b;

	read_array(array_a, INTEGER, ARRAY_1D, &size_a, NULL);
	read_array(array_b, INTEGER, ARRAY_1D, &size_b, NULL);
	
	int start;
	printf("Dati pozitia de inceput: ");
	scanf("%d", &start);

	for (int i = size_b - 1; i > size_b - size_a - 1; i--)
		array_b[i + size_a] = array_b[i];

	for (int i = 0; i < size_a; i++)
		array_b[i + start - 1] = array_a[i];

	size_b += size_a;

	print_array(array_b, INTEGER, ARRAY_1D, size_b, NULL, "Tabloul modificat este: ");
}