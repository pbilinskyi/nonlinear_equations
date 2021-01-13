#include <iostream>
#include <cmath>
#include "functions.h"

double eps = 1e-5;

// fixed point iteration
double phi(double x){
    return x - 0.1*f(x);
}

double phi_der(double x){
    return x - 0.1*f(x);
}

double iterative_process_fixed(double x_0, double n_max){
    double x_prev = x_0;
    double x_next = x_0;
    double err = std::abs(x_next - x_prev);
    int n = 0;
    bool flag = true;

    std::cout << "n       x_n       |x_n - x_n-1|      f(x_n)" << std::endl;
    while ((n < n_max) && ((err > eps) || (std::abs(f(x_prev)) > eps))){
        ++n;
        x_next = phi(x_prev);
        err = std::abs(x_next - x_prev);
        x_prev = x_next;
        // printing table
        printf("%d    %f       %f        %f", n, x_next, err, f(x_next));
        if ((err < eps) && (abs(f(x_next)) < eps) && flag){
            std::cout << " <--" << std::endl;
            flag = false;
        }
        else{
            std::cout << std::endl;
        }
    }
    return x_next;
}

double iterative_process_hordes(double x_0, double x_1, double n_max){

    double x_prev = x_1;
    double x_next = x_0;
    double err = std::abs(x_next - x_prev);
    int n = 1;
    bool flag = true;

    std::cout << " n         x_n         |x_n - x_n-1|        f(x_n)" << std::endl;
    while ((n < n_max) && ((err > eps) || (std::abs(f(x_prev)) > eps))){
        ++n;
        x_next = x_prev - f(x_prev)*(x_prev - x_0)/(f(x_prev) - f(x_0));
        err = std::abs(x_next - x_prev);
        x_prev = x_next;
        // printing table
        printf("%2d %15.6f %15.6f %15.6f", n, x_next, err, f(x_next));
        if ((err < eps) && (abs(f(x_next)) < eps) && flag){
            std::cout << " <--" << std::endl;
            flag = false;
        }
        else{
            std::cout << std::endl;
        }
    }
    return x_next;
}

int main() {
    double a = 1.2;
    double b = 1.4;

    std::cout << "==Fixed point iteration==" << std::endl;
    double x_fixed = iterative_process_fixed(a, 100);
    std::cout << "x = " << x_fixed << std::endl;

    std::cout << "==Hordes==" << std::endl;
    double x_hord  = iterative_process_hordes(a, (a + b)/2, 100);
    std::cout << "x = " << x_fixed << std::endl;
    return 0;
}
