#ifndef ARRAY_READ_WRITE_H
#define ARRAY_READ_WRITE_H

#define INTEGER 1
#define DOUBLE 2

#define ARRAY_1D 1
#define ARRAY_2D 2

#define MAX_ARRAY 256

#define MIN(a, b)   ((a) < (b) ? (a) : (b))
#define MAX(a, b)   ((a) > (b) ? (a) : (b))


void read_array(void* array, int data_type, int array_type, int* size_1, int* size_2);
void print_array(void* array, int data_type, int array_type, int size_1, int size_2, const char *print_message);

#endif