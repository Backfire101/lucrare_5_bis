/*
14. Scrieţi un program interactiv care realizează gestionarea unei agende telefonice. 
Programul va crea agenda telefonică și va permite căutarea unei persoane și afișarea numărului de telefon corespunzător, precum și afișarea agendei în ordine alfabetică.
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

void add_entry(char phonebook[MAX_ARRAY][2][MAX_ARRAY], int* size)
{
	if (*size >= MAX_ARRAY)
	{
		printf("Agenda este plina!\n");
		return;
	}

	char name_surname[MAX_ARRAY];
	char phone_number[MAX_ARRAY];

	printf("Dati numele si prenumle: ");
	fgets(name_surname, sizeof(name_surname), stdin);
	name_surname[strcspn(name_surname, "\n")] = '\0';

	printf("Dati numarul de telefon: ");
	fgets(phone_number, sizeof(phone_number), stdin);
	phone_number[strcspn(phone_number, "\n")] = '\0';

	int position = *size;

	for (int i = 0; i < *size; i++)
		if (strcmp(name_surname, phonebook[i][0]) == 0)
		{
			printf("Persoana este deja in dictionar!");
			return;
		}
		else
			if (strcmp(name_surname, phonebook[i][0]) < 0)
			{
				position = i;
				break;
			}

	for (int i = *size; i > position; i--)
	{
		strcpy(phonebook[i][0], phonebook[i - 1][0]);
		strcpy(phonebook[i][1], phonebook[i - 1][1]);
	}

	strcpy(phonebook[position][0], name_surname);
	strcpy(phonebook[position][1], phone_number);

	(*size)++;

	printf("Persoana adaugata cu succes!\n");
}

void print_phonebook(char phonebook[MAX_ARRAY][2][MAX_ARRAY], int size)
{
	if (size == 0)
	{
		printf("Agenda este gola!\n");
		return;
	}

	printf("Persoanele din agenda sunt:\n");

	for (int i = 0; i < size; i++)
		printf("%s - %s\n", phonebook[i][0], phonebook[i][1]);
}

void search_phonebook(char phonebook[MAX_ARRAY][2][MAX_ARRAY], int size)
{
	if (size == 0)
	{
		printf("Agenda este gola!\n");
		return;
	}

	char name_surname[MAX_ARRAY];

	printf("Dati un nume: ");
	fgets(name_surname, sizeof(name_surname), stdin);
	name_surname[strcspn(name_surname, "\n")] = '\0';

	bool found = false;

	for (int i = 0; i < size; i++)
		if (strstr(phonebook[i][0], name_surname) != NULL)
		{
			printf("%s - %s\n", phonebook[i][0], phonebook[i][1]);
			found = true;
		}
	if(!found)
		printf("Persoana nu sa gasit in agenda!\n");
}

void problema_14()
{
	char phonebook[MAX_ARRAY][2][MAX_ARRAY];
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
		case 'A': add_entry(phonebook, &size); break;
		case 'L': print_phonebook(phonebook, size); break;
		case 'C': search_phonebook(phonebook, size); break;
		case 'X': printf("Program in cheiat!\n"); break;
		default: printf("Nu ati introdus o actiune corecta!\n"); break;
		}

	} while (action != 'X');
}