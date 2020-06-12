#ifndef SORTING_H_INCLUDED
#define SORTING_H_INCLUDED
#include <stdlib.h>
#include <stdio.h>
void merge_sort(int* a, size_t length);
void quick_sort(int* a, size_t length);
void bubble_sort(int* a, size_t length);
/* UTILITY FUNCTIONS */
/* Function to print an array */
void printArray(int *a, int size);
#endif // SORTING_H_INCLUDED
