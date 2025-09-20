#ifndef IO_H_INCLUDED
#define IO_H_INCLUDED

#include <vector>
#include <string>
#include "error_struct.h"

void print_arrays(int N, const std::vector<double>& time, const std::vector<double>& Uvx, const std::vector<double>& Uvix);
void save_array(int N, const std::vector<double>& array, const std::string& name);
int input_number_points();
void readFile(const std::string& name);
void print_struct(const std::vector<Error> error_list);

#endif // IO_H_INCLUDED
