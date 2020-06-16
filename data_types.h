#ifndef DATA_TYPES_H_INCLUDED
#define DATA_TYPES_H_INCLUDED

/*
Arrays: These combine items that all have the same base type (subsection 6.1).
Structures: These combine items that may have different base types (subsection 6.3).
The two other strategies to derive data types are more involved:
Pointers: Entities that refer to an object in memory.
Pointers are by far the most involved concept, and we will delay a full discussion
of them to section 11. Here, in subsection 6.2, we will only discuss them as
opaque data types, without even mentioning the real purpose they fulfill.
Unions: These overlay items of different base types in the same memory location.
Unions require a deeper understanding of C’s memory model and are not of
much use in a programmer’s everyday life
*/
#include <stdio.h>

int dot_product(const int a[static 1], const int b[static 1], size_t length) {
    int product = 0;
    for(size_t i = 0; i < length; ++i) {
        product += a[i]*b[i];
    }
    return product;
}

void printVector(int a[static 1], size_t length)
{
    printf("[");
    for (size_t i = 0; i < length; i++)
        printf("%d , ", a[i]);
    printf("]");
}

void printMatrix(size_t r, size_t c, const int a[r][c] )
{
    printf("\n");
    for (size_t i = 0; i < r; i++) {
        printf("\t");
        for (size_t j = 0; j < c; j++)
            printf("%d\t", a[i][j]);
        printf("\n");
    }
    printf("\n");
}

matrix_product() {

}

void example(){
    int a[] = {1 ,3 ,-5 };
    int b[] = {4 ,-2 ,-1 };
    size_t length = 3;
    printVector(a, length);
    printVector(b, length);
    printf("= %d\n", dot_product(a, b, length));

}
void example_matrix_multiplication(){
    int a[3][3] = {
        { 1, 2, 0, },
        { 0, 1, 1, },
        { 2, 0, 1, },
    };
    int b[3][3] = {
        { 1, 1, 2,  },
        { 2, 1, 1,  },
        { 1, 2, 1,  },
    };

    int result[3][3] = {};

    size_t r = 3;
    size_t c = 3;
    size_t k = 3;
    for (size_t i = 0; i < r; i++) {
        for (size_t j = 0; j < c; j++){
            for (size_t m = 0; m < k; m++){
                result[i][j] += a[i][m]*b[m][j];
            }
        }
    }

    printMatrix(r, c, result);

}

#endif // DATA_TYPES_H_INCLUDED
