/*
10. Să se caute un caracter într-un şir dat şi să se returneze indexul primei apariţii a caracterului în şir.
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

void problema_10()
{
	char string[MAX_ARRAY];

	printf("Dati un sir de caractere: ");

	fgets(string, sizeof(string), stdin);
	string[strcspn(string, "\n")] = '\0';

	int length = strlen(string);

	char character;
	printf("Dati caracterul cautat: ");
	character = fgetc(stdin);

	int position = 0;
	for (int i = 0; i < length; i++)
		if (character == string[i])
		{
			position = i + 1; 
			break;
		}
	if (position)
		printf("Prima aparitie a caracterului '%c' este pe pozitia: %d", character, position);
	else
		printf("Caracterul '%c' nu apare in sir!", character);
}