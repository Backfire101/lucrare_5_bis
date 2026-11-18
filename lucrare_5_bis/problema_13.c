/*
13. Să se scrie un program interactiv care gestionează un dicționar de cuvinte, inițial vid; pentru fiecare cuvânt se reține echivalentul său într-o limbă străină (de exemplu engleză). Programul va citi de la
tastatură un caracter și va realiza următoarele comenzi:
- A - adaugă un cuvânt în dictionar (cuvântul și echivalentul său in limba străină)
- L - listează dicționarul în ordinea alfabetică a cuvintelor
- C - citește de la tastatură un cuvânt și caută în dicționar cuvântul, în cazul în care îl găsește afișează traducerea acestuia, iar în caz contrar afișează un mesaj (Cuvânt inexistent)
- X - terminare program
*/

#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>
#include <string.h>
#include "array_read_write.h" 
#include "probleme.h"

void add_word(char dictionary[MAX_ARRAY][2][MAX_ARRAY], int* size)
{
	if (*size >= MAX_ARRAY)
	{
		printf("Dictionarul este plin!\n");
		return;
	}

	char word[MAX_ARRAY];
	char synonim[MAX_ARRAY];

	printf("Dati un cuvant: ");
	fgets(word, sizeof(word), stdin);
	word[strcspn(word, "\n")] = '\0';

	printf("Dati un sinonimul: ");
	fgets(synonim, sizeof(synonim), stdin);
	synonim[strcspn(synonim, "\n")] = '\0';

	int position = *size;

	for (int i = 0; i < *size; i++)
		if (strcmp(word, dictionary[i][0]) == 0)
		{
			printf("Cuvantul este deja in dictionar!");
			return;
		}
		else
			if (strcmp(word, dictionary[i][0]) < 0)
			{
				position = i;
				break;
			}

	for (int i = *size; i > position; i--)
	{
		strcpy(dictionary[i][0], dictionary[i - 1][0]);
		strcpy(dictionary[i][1], dictionary[i - 1][1]);
	}

	strcpy(dictionary[position][0], word);
	strcpy(dictionary[position][1], synonim);

	(*size)++;

	printf("Cuvant adaugat cu succes!\n");
}

void print_dictionary(char dictionary[MAX_ARRAY][2][MAX_ARRAY], int size)
{
	if (size == 0)
	{
		printf("Dictionarul este gol!\n");
		return;
	}

	printf("Cuvintele din dictionar sunt:\n");

	for (int i = 0; i < size; i++)
		printf("%s - %s\n", dictionary[i][0], dictionary[i][1]);
}

void search_dictionary(char dictionary[MAX_ARRAY][2][MAX_ARRAY], int size)
{
	if (size == 0)
	{
		printf("Dictionarul este gol!\n");
		return;
	}

	char word[MAX_ARRAY];

	printf("Dati un cuvant: ");
	fgets(word, sizeof(word), stdin);
	word[strcspn(word, "\n")] = '\0';

	for (int i = 0; i < size; i++)
		if (strcmp(word, dictionary[i][0]) == 0 || strcmp(word, dictionary[i][1]) == 0)
		{
			printf("%s - %s\n", dictionary[i][0], dictionary[i][1]);
			return;
		}

	printf("Cuvantul nu sa gasit in dictionar!");
}

void problema_13()
{
	char dictionary[MAX_ARRAY][2][MAX_ARRAY];
	int size = 0;

	char action;
	do
	{
		printf("Introduceti actiunea dorita: ");

		action = fgetc(stdin); 
		
		int clean_buff;
		while ((clean_buff = getchar()) != '\n' && clean_buff != EOF) {}

		switch (action)
		{
		case 'A': add_word(dictionary, &size); break;
		case 'L': print_dictionary(dictionary, size); break;
		case 'C': search_dictionary(dictionary, size); break; 
		case 'X': printf("Program in cheiat!\n"); break;
		default : printf("Nu ati introdus o actiune corecta!\n"); break;
		}

	} while (action != 'X');
}