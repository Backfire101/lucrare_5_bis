/*
4. Scrieți un program în C care realizează următoarele operații asupra unei matrici pătratice M de ordin N (N fiind declarată ca și constantă), având elemente întregi. 
Pentru fiecare operație asupra elementelor matricei se va defini o funcție fără parametri:
- void citire(void) - citește elementele matricii (se va introduce numărul de linii și coloane de la tastatură)
- void afisare(void) - afișează matricea pe linii și coloane
- void modifica(void) - scade valoarea fiecărui element al matricii cu suma indicilor elementului respectiv; se afișează apoi matricea modificată prin apelul funcției afisare.
- void transpusa(void) - calculează și afișează transpusa matricei
- void linia_suma_min(void) - determină linia din matrice care are suma minimă a elementelor, afișând indicele liniei și suma
- void calc_suma(void) - calculează și afiseaza suma elementelor matricei
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

int array[MAX_ARRAY][MAX_ARRAY];
int size_n, size_m;

void citire()
{
	read_array(array, INTEGER, ARRAY_2D, &size_n, &size_m);
}

void afisare()
{
	print_array(array, INTEGER, ARRAY_2D, size_n, size_m, NULL);
}

void modifica()
{
	for (int i = 0; i < size_n; i++)
		for (int j = 0; j < size_m; j++)
			array[i][j] -= (i + 1) + (j + 1);
	afisare();
}

void transpusa()
{
	int temp_array[MAX_ARRAY][MAX_ARRAY];
	for (int i = 0; i < size_n; i++)
		for (int j = 0; j < size_m; j++)
			temp_array[j][i] = array[i][j];

	size_n = size_n + size_m;
	size_m = size_n - size_m;
	size_n = size_n - size_m;

	for (int i = 0; i < size_n; i++)
		for (int j = 0; j < size_m; j++)
			array[i][j] = temp_array[i][j];
	afisare();
}

void linia_suma_min()
{
	int minimum = INT_MAX;

	for (int i = 0; i < size_n; i++)
	{
		int sum_row = 0;

		for (int j = 0; j < size_m; j++)
			sum_row += array[i][j];

		minimum = MIN(minimum, sum_row);
	}

	printf("Minimul sumei de pe coloane este: %d\n", minimum);
}

void calc_suma()
{
	int sum = 0;
	for (int i = 0; i < size_n; i++)
		for (int j = 0; j < size_m; j++)
			sum += array[i][j];

	printf("Suma tabloului este: %d\n", sum);
}

void problema_04()
{
	citire();
	afisare();
	modifica();
	transpusa();
	linia_suma_min();
	calc_suma();
}