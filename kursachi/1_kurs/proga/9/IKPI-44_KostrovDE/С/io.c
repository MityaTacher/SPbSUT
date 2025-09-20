#include <stdlib.h>
#include <stdio.h>

#include "logic.h"


void save_array(int N, double *array, char *name)
{
    FILE *file = fopen(name, "w");
    if (!file)
    {
        perror("File error");
        return;
    }
    int i = 0;
    while (i < N)
    {
        fprintf(file, "%.15lf\n", array[i]);
        i++;
    }
    fclose(file);
}


int input_nuber_points()
{
    int N;
    printf("Enter number of points: ");
    scanf("%d", &N);
    return N;
}


void print_parametr()
{
    int N = input_nuber_points();
    double Uvx_array[N], Uvix_array[N], time_array[N];
    fill_all_arrays(N, time_array, Uvx_array, Uvix_array);

    double parametr = get_param(N, time_array, Uvx_array);
    double real_parametr = get_real_param();
    double error = (1 - parametr / real_parametr) * 100;
    printf("Parameter value: %4.2f\tError: %3.3f%%",
           parametr, error);
}


void print_arrays(int N, double *time, double *Uvx, double *Uvix) {
    printf("+------+--------+----------+--------------+\n");
    printf("|  No  |  time  |   Uvx    |     Uvix     |\n");
    printf("+------+--------+----------+--------------+\n");

    for (int i = 0; i < N; i++) {
        printf("|  %2d  |  %4.1f  |  %6.2f  |  %10.4e  |\n", i + 1, time[i], Uvx[i], Uvix[i]);
    }

    printf("+------+--------+----------+--------------+\n");
}


void print_param_with_an_error()
{
    double error_rate = 1;
    double eps = 0.01;
    double par;
    int N = 11;

    printf("+-----+------------+-----------+\n");
    printf("|  N  |  Parametr  |   Error   |\n");
    printf("+-----+------------+-----------+\n");

    while (error_rate > eps)
    {
        double Uvx_array[N], Uvix_array[N], time_array[N];
        fill_all_arrays(N, time_array, Uvx_array, Uvix_array);
        par = get_param(N, time_array, Uvx_array);
        error_rate = 1 - par / get_real_param();
        printf("| %3d |  %3.4f  |   %.4f  |\n", N, par, error_rate);
        N *= 2;
    }
    printf("+-----+------------+-----------+\n");
}


void print_write_voltages(int write)
{
    int N = input_nuber_points();
    double Uvx_array[N], Uvix_array[N], time_array[N];
    fill_all_arrays(N, time_array, Uvx_array, Uvix_array);

    if (write == 0)
    {
        print_arrays(N, time_array, Uvx_array, Uvix_array);
    }
    else
    {
        save_array(N, time_array, "data/time_array.txt");
        save_array(N, Uvx_array, "data/Uvx_array.txt");
        save_array(N, Uvix_array, "data/Uvix_array.txt");
        printf("Done");
    }
}


void print_menu()
{
    printf("1 - Control calculation for N points\n");
    printf("2 - Calculation of a parameter with N points\n");
    printf("3 - Calculation of a parameter with a given accuracy\n");
    printf("4 - Writing data to a file\n");
    printf("5 - Exit\n");
}
