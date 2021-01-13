#include <iostream>
#include <cmath>
#include "functions.h"

double eps = 1e-5;

double iterative_process_fixed(double x_0, double n_apr){
    double x_prev = x_0;
    double x_next = x_0;
    double err = std::abs(x_next - x_prev);
    int n = 0;
    bool flag = true;

    std::cout << "n       x_n       |x_n - x_n-1|      f(x_n)" << std::endl;
    while ((n < n_apr) || ((err > eps) || (std::abs(f(x_prev)) > eps))){
        ++n;
        x_next = phi(x_prev);
        err = std::abs(x_next - x_prev);
        x_prev = x_next;
        // printing table
        printf("%d    %f       %f        %f", n, x_next, err, f(x_next));
        if ((err < eps) && (std::abs(f(x_next)) < eps) && flag){
            std::cout << " <--" << std::endl;
            flag = false;
        }
        else{
            std::cout << std::endl;
        }
    }
    return x_next;
}

double iterative_process_Newton_mod(double x_0, double n_max){

    double x_prev = x_0;
    double x_next = x_0;
    double err = std::abs(x_next - x_prev);
    int n = 0;
    bool flag = true;

    std::cout << " n         x_n         |x_n - x_n-1|        f(x_n)" << std::endl;
    while ((n < n_max) && ((err > eps) || (std::abs(f(x_prev)) > eps))){
        ++n;
        x_next = x_prev - f(x_prev)/f_der(x_prev);
        err = std::abs(x_next - x_prev);
        x_prev = x_next;
        // printing table
        printf("%2d %15.6f %15.6f %15.6f", n, x_next, err, f(x_next));
        if ((err < eps) && (std::abs(f(x_next)) < eps) && flag){
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
    double x_next = x_1;
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
        if ((err < eps) && (std::abs(f(x_next)) < eps) && flag){
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
    int n_apr = 27; // CHANGE THIS NUMBER!
    double x_fixed = iterative_process_fixed(a, n_apr);
    std::cout << "x = " << x_fixed << std::endl;

    std::cout << "==Newton modified========" << std::endl;
    double x_newton_mod  = iterative_process_Newton_mod(a, 100);
    std::cout << "x = " << x_newton_mod << std::endl;

    std::cout << "==Hordes=================" << std::endl;
    double x_hord  = iterative_process_hordes(a, (a + b)/2, 100);
    std::cout << "x = " << x_fixed << std::endl;

    return 0;
}
