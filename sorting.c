#include "sorting.h"
#include <stdbool.h>
// Util function
void printArray(int *a, int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", a[i]);
    printf("\n");
}

// MERGE SORT

void merge(int *a, size_t l, size_t m, size_t r) {

    size_t i, j, k;
    size_t n1 = m - l + 1;
    size_t n2 = r - m;

    // create temp arrays
    int left[n1];
    int right[n2];

    // copy data from a to left and right
    for (i = 0; i < n1; ++i)
        left[i] = a[l+i];
    for (j = 0; j < n2; ++j)
        right[j] = a[m + 1 + j];

    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while(i < n1 && j < n2) {
        if(left[i] <= right[j]) {
            a[k] = left[i];
            i++;
        }else{
            a[k] = right[j];
            j++;
        }
        k++;
    }

        /* Copy the remaining elements of L[], if there
       are any */
    while (i < n1) {
        a[k] = left[i];
        i++;
        k++;
    }

    /* Copy the remaining elements of R[], if there
       are any */
    while (j < n2) {
        a[k] = right[j];
        j++;
        k++;
    }
}

void merge_sort_internal(int *a, size_t l, size_t r) {
    // Base case. A list of zero or one elements is sorted, by definition.
    if((r-l)+1 <= 1)
        return;

    size_t middle_index = l + ( r - l ) / 2;
    merge_sort_internal(a, l , middle_index);
    merge_sort_internal(a, middle_index+1, r);

    merge(a, l, middle_index, r);
    printf("%lu %lu %lu\n", l, middle_index ,r);
    printArray(a, 6);
}

void merge_sort(int *a, size_t length) {
    merge_sort_internal(a, 0, length-1);
}




// A utility function to swap two elements
void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}




// QUICK SORT
size_t partition(int* a, size_t l, size_t r) {
    size_t i = l, j = r;
    int pivot = a[(l+r)/2];
    while(i <= j) {
        while (a[i] < pivot)
            i++;
        while (a[j] > pivot)
            j--;
        if(i <= j) {
            swap(&a[i], &a[j]);
            i++;
            j--;
        }
    }
    return i;
}

void quick_sort_internal(int* a,size_t l, size_t r) {

      int index = partition(a, l, r);

      if (l < index - 1)
            quick_sort_internal(a, l, index - 1);
      if (index < r)
            quick_sort_internal(a, index, r);

}
void quick_sort(int* a, size_t length) {
    quick_sort_internal(a, 0, length-1);
}


void bubble_sort(int* a, size_t length){
    for (size_t i = 0; i < length-1; i++)
        // Last i elements are already in place
        for (size_t j = 0; j < length-i-1; j++)
            if (a[j] > a[j+1])
                swap(&a[j], &a[j+1]);
}

