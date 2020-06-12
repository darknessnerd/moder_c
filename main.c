#include <stdint.h>


#include <stdlib.h>
#include "heron_approximation.h"
#include "sorting.h"



/* The main thing that this program does */
int main()
{
    // Declarations
    double A[5] = {
        [0] = 9.0 ,
        [1] = 2.9 ,
        [4] = 3.E+25 ,
        [3] = .00007
    };
    printf("SIZE_MAX: %zu \n", SIZE_MAX);
    // Doing some work
    for(size_t i = 0; i < 5; ++i) {
       printf("element %lu is %g, \tits  square  is %g\n", i, A[i], A[i]*A[i]);
    }

    //heron
    double x = 0.5;
    printf("heron approximation %f\n", heron_approximation(x));


    // Sorting
    int arr[] = { 12, 11, 13, 5, 6, 7 };
    int arr_size = sizeof(arr) / sizeof(arr[0]);
    printf("Given array is \n");
    printArray(arr, arr_size);
    quick_sort(arr, arr_size - 1);
    printf("\nSorted array is \n");
    printArray(arr, arr_size);

    return EXIT_SUCCESS;
}
