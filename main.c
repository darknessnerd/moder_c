#include <stdint.h>


#include <stdlib.h>
#include "heron_approximation.h"
#include "sorting.h"
#include "data_types.h"
enum corvid { magpie , raven , jay , chough , corvid_num , };

// A compound literal defines an object.
/*
Takeaway 1.5.6.9 A compound literal defines an object.
Overall, this form of macro has some pitfalls:
• Compound literals aren’t suitable for ICE.
• For our purpose here ,to declare named constants, the type T should be constqualifiedC. This ensures that the optimizer has a bit more slack to generate good
binary code for such a macro replacement.
• There must be space between the macro name and the () of the compound literal,
here indicated by the block comment comment. Otherwise, this would be interpreted as the
start of a definition of a function-like macro. We will see these much later.
• A backspace character \ at the very end of the line can be used to continue the
macro definition to the next line.
• There must be no ; at the end of the macro definition. Remember, it is all just
text replacement.
Takeaway 1.5.6.10 Don’t hide a terminating semicolon inside a macro.
Also, for readability of macros, please pity the poor occasional reader of your code:
Takeaway 1.5.6.11 Right-indent continuation markers for macros to the same column.
As you can see in the example, this helps to visualize the entire spread of the macro
definition easily.
*/
# define CORVID_NAME_MACRO /**/         \
( char const * const [ corvid_num ]){   \
    [raven] = " raven ",                \
    [magpie] = " magpie ",              \
    [jay] = "jay",                      \
    [chough] = "chough",                \
}

// Bit operations
# define FLOCK_MAGPIE (1U << magpie )
# define FLOCK_RAVEN (1U << raven )
# define FLOCK_JAY (1U << jay)
# define FLOCK_CHOUGH (1U << chough )
# define FLOCK_EMPTY 0U
# define FLOCK_FULL ((1U << corvid_num )-1)
/*
# define FLOCK_MAGPIE 1U
# define FLOCK_RAVEN 2U
# define FLOCK_JAY 4U
# define FLOCK_CHOUGH 8U
# define FLOCK_EMPTY 0U
# define FLOCK_FULL 15U
*/
// C Program for the binary
// representation of a given number
void bin(unsigned n)
{
    /* step 1 */
    if (n > 1)
        bin(n/2);

    /* step 2 */
    printf("%d", n % 2);
}
void printFlock(unsigned flock){
    printf("FLOCK_MAGPIE\tFLOCK_MAGPIE\tFLOCK_RAVEN\tFLOCK_JAY\tFLOCK_CHOUGH\t\n");
    if ( flock & FLOCK_MAGPIE ) printf("1\t\t\t");else printf("0\t\t\t");
    if ( flock & FLOCK_RAVEN ) printf("1\t\t\t");else printf("0\t\t\t");
    if ( flock & FLOCK_JAY ) printf("1\t\t\t");else printf("0\t\t\t");
    if ( flock & FLOCK_CHOUGH ) printf("1\t\t\t\n"); else printf("0\t\t\t\n");
}
/* The main thing that this program does */
int main()
{
    // Bit operations

    unsigned flock = FLOCK_EMPTY ;
    printFlock(flock);
    flock |= FLOCK_JAY ; // add a corvid
    printFlock(flock);
    flock |= FLOCK_FULL ;
    printFlock(flock);
    flock ^= FLOCK_MAGPIE ; // off magpie
    printFlock(flock);

    flock &= FLOCK_JAY ; // keep only JAY ON
    printFlock(flock);


    // Eunum example

    char const * const bird [corvid_num] = {
        [raven] = "raven",
        [magpie] = "magpie",
        [chough] = "chough",
        [jay] = "jay",
    };

    for( size_t i = 0; i < corvid_num ; ++i) {
        printf (" Corvid %d %s\n", i, bird[i] );
    }

    for( size_t i = 0; i < corvid_num ; ++i) {
        printf (" Corvid %d %s\n", i, CORVID_NAME_MACRO[i] );
    }
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
    bubble_sort(arr, arr_size);
    printf("\nSorted array is \n");
    printArray(arr, arr_size);

    example();
    example_matrix();
    return EXIT_SUCCESS;
}
