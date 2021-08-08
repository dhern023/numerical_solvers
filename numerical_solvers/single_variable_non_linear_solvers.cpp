#include "single_variable_non_linear_solvers.h"

double newton_raphson_method(double (*p_function)(double), double (*p_function_prime)(double), double seed, double epsilon, int max_iterations)
{
	int iterations = 0;
	std::vector<double> results(2, seed);
	do
	{
		results[0] = results[1];
		results[1] = results[0] - (*p_function)(results[0]) / (*p_function_prime)(results[0]);
		std::cout << results[0] << ", " << results[1] << std::endl;
		iterations++;
	} while ((std::abs(results[1] - results[0]) > epsilon) && (iterations < max_iterations));

	return results[1];
}

std::vector<std::vector<double>> calculate_dichotomy_candidates(double (*p_function)(double), std::vector<double> interval)
{
	assert(interval.size() == 2);
	
	std::vector<std::vector<double>> candidates;

	double m = (interval[0] + interval[-1]) / 2;

	if ((*p_function)(interval[0]) * (*p_function)(m) < 0)
	{
		std::vector<double> left_interval = { interval[0],m };
		candidates.push_back(left_interval);
	}

	if ((*p_function)(m) * (*p_function)(interval[1]) < 0)
	{
		std::vector<double> right_interval = { m, interval[1] };
		candidates.push_back(right_interval);
	}

	return candidates;	
}

double dichotomy_method(double (*p_function)(double), std::vector<double> domain, int max_iterations)
{
	assert(domain.size() == 2);
	assert(domain[0] < domain[1]);
	assert((*p_function)(domain[0]) * (*p_function)(domain[1]) < 0); //f(b) and f(a) must have opposing signs"

	std::vector<std::vector<double>> candidates = calculate_dichotomy_candidates((*p_function), domain);

	for (size_t i = 0; i < max_iterations; i++)
	{
		std::vector<std::vector<double>> next_candidates;
		for (size_t j = 0; j < candidates.size(); j++)
		{
			next_candidates = calculate_dichotomy_candidates((*p_function), candidates[j]);
		}
		candidates = next_candidates;
	}
	return (candidates[0][0] + candidates[0][1]) / 2;
}