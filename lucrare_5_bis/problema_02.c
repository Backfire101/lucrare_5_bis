/*
2. Să se scrie un program care citește de la tastatură un număr N natural, apoi citește cele N elemente ale unui șir de numere naturale. 
Programul va calcula și afișa media aritmetică a numerelor prime ale șirului, respectiv media aritmetică a numerelor pare.
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

bool prime(int number)
{
	if (number <= 1)
		return false;
	else
		if (number == 2)
			return true;
		else
			if (number % 2 == 0)
				return false;
			else
				for (int i = 3; i * i <= number; i += 2)
					if (number % i == 0)
						return false;
	return true;
}

void problema_02()
{
	int array[MAX_ARRAY];
	int size;

	read_array(array, INTEGER, ARRAY_1D, &size, NULL);

	int sum_even = 0;
	int count_even = 0;

	int sum_prime = 0;
	int count_prime = 0;

	for (int i = 0; i < size; i++)
	{
		if (*(array + i) % 2 == 0)
			sum_even += array[i], count_even++;
		if (prime(*(array + i)))
			sum_prime += array[i], count_prime++;
	}

	if (count_even)
		printf("Media aritmetica a numerelor pare este: %.2f\n", (float)sum_even / (float)count_even);
	else
		printf("Nu exista numere pare in tablou!\n");

	if (count_prime)
		printf("Media aritmetica a numerelor prime este: %.2f\n", (float)sum_prime / (float)count_prime);
	else
		printf("Nu exista numere prime in tablou!\n");
}