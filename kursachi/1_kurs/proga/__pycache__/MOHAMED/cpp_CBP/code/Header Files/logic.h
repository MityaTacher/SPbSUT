#ifndef LOGIC_H_INCLUDED
#define LOGIC_H_INCLUDED

#include <vector>
#include "error_struct.h"

double Uvx(double t);
double Uvix(double t);
void get_io_voltage(int N, const std::vector<double>& time_array, std::vector<double>& output_array, int func);
void get_time(int N, std::vector<double>& output_array);
void fill_all_arrays(int N, std::vector<double>& time_array, std::vector<double>& Uvx_array, std::vector<double>& Uvix_array);
double get_impuls_length(int N, const std::vector<double>& input_array);
std::vector<Error> get_param_with_an_error();

#endif // LOGIC_H_INCLUDED
