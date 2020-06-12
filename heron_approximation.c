#include "heron_approximation.h"

double heron_approximation(const double x) {
    double result = x;
    double const eps = 1E-9;
    double const a = 0.02;
    printf("heron approximation input %f   %f %f\n", result, eps, fabs(1.0 - (a*result)));

    while(fabs(1.0 - a*result) >= eps) {
        //printf("heron approximation input %f %f\n", result, fabs(1.0 - a*result));
        result *= 2.0 - (a*result);
        printf("heron approximation input %f %f\n", result, fabs(1.0 - a*result));
    }
    return result ;

}
