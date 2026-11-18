/*
17. Se citește de la tastatură un text care se termină cu EOF. Să se prelucreze textul astfel: se elimină toate caracterele nealfanumerice. Identificatorii şi numerele sunt tipărite separat. Întâi numerele în
ordinea apariţiei lor, după care identificatorii în ordine alfabetică.
*/
/*
18. Să se scrie un program care citește șiruri de la tastatură, fiecare pe un rând nou, până la apăsarea CTRL+Z, apoi realizează următoarele operații asupra șirurilor:
a. tipărește șirurile inversate;
b. afișează numărul de vocale din fiecare șir;
c. afișează numărul de șiruri care conțin numai cifre, respectiv numai litere.
*/

#define _CRT_SECURE_NO_WARNINGS  1
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>
#include <string.h>
#include "array_read_write.h" //tudor's own little header file
#include "probleme.h"

int main()
{
	int problema;
	printf("Dati numarul problemei: ");
	scanf("%d", &problema);

	int clean_buff;
	while ((clean_buff = getchar()) != '\n' && clean_buff != EOF) {}

	while (problema)
	{
		switch (problema)
		{
		case  1: problema_01(); break;
		case  2: problema_02(); break;
		case  3: problema_03(); break;
		case  4: problema_04(); break;
		case  5: problema_05(); break;
		case  6: problema_06(); break;
		case  7: problema_07(); break;
		case  8: problema_08(); break;
		case  9: problema_09(); break;
		case 10: problema_10(); break;
		case 11: problema_11(); break;
		case 12: problema_12(); break;
		case 13: problema_13(); break;
		case 14: problema_14(); break;
		case 15: problema_15(); break;
		case 16: problema_16(); break;
		case 17: problema_17(); break;
		case 18: problema_18(); break;
		default: printf("Nu exista problema numarul:%d", problema); break;
		}

		printf("\nDati numarul problemei:");
		scanf("%d", &problema);
		while ((clean_buff = getchar()) != '\n' && clean_buff != EOF) {}
	}

	return 0;
}


