#include <cmath>

#ifndef PROJECT_FUNCTIONS_H
#define PROJECT_FUNCTIONS_H


double f(double x){
    return pow(x, 5) - 3*pow(x, 2) + 1;
}

double f_der(double x){
    return 5*pow(x, 4) - 6*x ;
}

// fixed point iteration
double phi(double x){
    return x - 0.1*f(x);
}

//double phi_der(double x){
//    return x - 0.1*f(x);
//}

#endif //PROJECT_FUNCTIONS_H
