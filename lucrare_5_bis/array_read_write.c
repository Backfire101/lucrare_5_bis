#define _CRT_SECURE_NO_WARNINGS  1
#include <stdio.h>
#include "array_read_write.h"

void read_array(void* array, int data_type, int array_type, int* size_1, int* size_2)
{
	if (data_type == INTEGER)
	{
		if (array_type == ARRAY_1D)
		{
			int* temp_arr = (int*)array;

			printf("Dati dimensiunea tabloului: ");
			scanf("%d", size_1);

			printf("Dati elementele tabloului: ");
			for (int i = 0; i < *size_1; i++)
				scanf("%d", &temp_arr[i]);
		}
		else if (array_type == ARRAY_2D)
		{
			int (*temp_arr)[MAX_ARRAY] = (int (*)[MAX_ARRAY])array;

			printf("Dati dimensiunile tabloului: ");
			scanf("%d %d", size_1, size_2);

			printf("Dati elementele tabloului: ");
			for (int i = 0; i < *size_1; i++)
				for (int j = 0; j < *size_2; j++)
					scanf("%d", &temp_arr[i][j]);
		}
	}
	else if (data_type == DOUBLE)
	{
		if (array_type == ARRAY_1D)
		{
			double* temp_arr = (double*)array;
			printf("Dati dimensiunea tabloului: ");
			scanf("%d", size_1);
			printf("Dati elementele tabloului: ");
			for (int i = 0; i < *size_1; i++)
				scanf("%lf", &temp_arr[i]);
		}
		else if (array_type == ARRAY_2D)
		{
			double (*temp_arr)[MAX_ARRAY] = (double (*)[MAX_ARRAY])array;

			printf("Dati dimensiunile tabloului: ");
			scanf("%d %d", size_1, size_2);

			printf("Dati elementele tabloului: ");
			for (int i = 0; i < *size_1; i++)
				for (int j = 0; j < *size_2; j++)
					scanf("%lf", &temp_arr[i][j]);
		}
	}
}

void print_array(void* array, int data_type, int array_type, int size_1, int size_2, const char* print_message)
{
	if (data_type == INTEGER)
	{

		if (array_type == ARRAY_1D)
		{
			int* temp_arr = (int*)array;

			if (print_message != NULL)
				printf("%s", print_message);
			else
				printf("Elementele tabloului sunt: ");
			for (int i = 0; i < size_1; i++)
				printf("%d ", temp_arr[i]);
			printf("\n");
		}
		else if (array_type == ARRAY_2D)
		{
			int (*temp_arr)[MAX_ARRAY] = (int (*)[MAX_ARRAY])array;

			if (print_message != NULL)
				printf("%s\n", print_message);
			else
				printf("Elementele tabloului sunt:\n");
			for (int i = 0; i < size_1; i++)
			{
				for (int j = 0; j < size_2; j++)
					printf("%d ", temp_arr[i][j]);
				printf("\n");
			}
			printf("\n");
		}
	}
	else if (data_type == DOUBLE)
	{
		if (array_type == ARRAY_1D)
		{
			double* temp_arr = (double*)array;

			if (print_message != NULL)
				printf("%s", print_message);
			else
				printf("Elementele tabloului sunt: ");
			for (int i = 0; i < size_1; i++)
				printf("%.2lf ", temp_arr[i]);
			printf("\n");
		}
		else if (array_type == ARRAY_2D)
		{
			double (*temp_arr)[MAX_ARRAY] = (double (*)[MAX_ARRAY])array;

			if (print_message != NULL)
				printf("%s\n", print_message);
			else
				printf("Elementele tabloului sunt:\n");
			for (int i = 0; i < size_1; i++)
			{
				for (int j = 0; j < size_2; j++)
					printf("%.2lf ", temp_arr[i][j]);
				printf("\n");
			}
			printf("\n");
		}
	}
}