#ifndef IO_H_INCLUDED
#define IO_H_INCLUDED

void print_arrays(int N, double *time, double *Uvx, double *Uvix);
void save_array(int N, double *array, char *name);
int input_nuber_points();
void print_parametr();
void print_write_voltages(int write);
void print_menu();
void print_param_with_an_error();


#endif // IO_H_INCLUDED
