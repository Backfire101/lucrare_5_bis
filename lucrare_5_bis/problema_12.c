/*
12. Scrieţi un program care să numere spaţiile, virgulele şi punctele care apar într-un şir (Folosiţi o instrucţiune switch).
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

void problema_12()
{
	char string[MAX_ARRAY];

	printf("Dati un sir de caracter: ");

	fgets(string, sizeof(string), stdin);
	string[strcspn(string, "\n")] = '\0';

	int length = strlen(string);

	int spa = 0, com = 0, dot = 0;

	for(int i = 0 ; i < length ; i ++)
		switch (string[i])
		{
		case ' ': spa++; break;
		case '.': dot++; break;
		case ',': com++; break;
		default : break;
		}

	printf("In sirul de caracter sunt %d spatii, %d virgule si %d puncte.", spa, com, dot);
}