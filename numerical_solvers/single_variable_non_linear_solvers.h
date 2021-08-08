// single_variable_non_linear_solvers.h

#pragma once
#include <cassert>
#include <vector>
#include <iostream>

double newton_raphson_method(double (*p_function)(double), double (*p_function_prime)(double), double seed, double epsilon = 1.0e-6, int max_iterations = 100);

/*
Dichotomy method based on intermediate value theorem for functions with opposing signs for endpoints. 
It's not useful in that regard (e.g., a(x-h)^2) + b for {h>=0, b>=0}, but it only requires a cts function.
*/
std::vector<std::vector<double>> calculate_dichotomy_candidates(double (*p_function)(double), std::vector<double> interval);
double dichotomy_method(double (*p_function)(double), std::vector<double> domain, int max_iterations = 20);
