/*
7. Să se scrie un program care citește de la tasatură doi vectori a și b cu câte n elemente fiecare. 
Programul va calcula și afișa valoarea expresiei E = min(a[1],b[1]) + min(a[2],b[2])+...+ min(a[N],b[N]).
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

void problema_07()
{
	int array_a[MAX_ARRAY];
	int array_b[MAX_ARRAY];
	int size_a;
	int size_b;
	int size;

	read_array(array_a, INTEGER, ARRAY_1D, &size_a, NULL);
	read_array(array_b, INTEGER, ARRAY_1D, &size_b, NULL);

	size = MIN(size_a, size_b);
	int expression = 0;

	for (int i = 0; i < size; i++)
		expression += MIN(array_a[i] , array_b[i]);

	printf("Valoarea expresiei E=%d\n", expression);
}