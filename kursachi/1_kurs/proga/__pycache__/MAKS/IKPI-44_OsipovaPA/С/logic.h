#ifndef LOGIC_H_INCLUDED
#define LOGIC_H_INCLUDED

double Uvx(double t);
double Uvix(double t);
void get_io_voltage(int N, double *time_array, double *output_array, int func);
void get_time(int N, double *output_array);
void fill_all_arrays(int N, double time_array[], double Uvx_array[], double Uvix_array[]);
double get_impuls_lenght(int N, double *input_array);

#endif // LOGIC_H_INCLUDED
