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

    printf("Time when Uvix -> 11.11: %.4f", get_param(N, Uvix_array));
}


void print_arrays(int N, double *time, double *Uvx, double *Uvix) {
    printf("+------+----------+----------+----------+\n");
    printf("|  No  |   time   |   Uvx    |   Uvix   |\n");
    printf("+------+----------+----------+----------+\n");

    for (int i = 0; i < N; i++) {
        printf("| %4d | %8.4f | %8.4f | %8.4f |\n", i + 1, time[i], Uvx[i], Uvix[i]);
    }

    printf("+------+----------+----------+----------+\n");
}

void print_param_with_an_error()
{
    double error_rate = 1;
    double eps = 0.01;
    double par = 1e+10, par1;
    int N = 11;;

    printf("+-----+--------------+--------------+\n");
    printf("|  N  |   Parametr   |  Error rate  |\n");
    printf("+-----+--------------+--------------+\n");

    while (error_rate > eps)
    {
        double Uvx_array[N], Uvix_array[N], time_array[N];
        fill_all_arrays(N, time_array, Uvx_array, Uvix_array);
        par1 = get_param(N, Uvix_array);
        error_rate = (par - par1) / par1;
        error_rate = (error_rate < 0.0 ? -error_rate : error_rate);
        printf("| %3d |  %10.6f  |  %10.4f  |\n", N, par1, (error_rate > 9999 ? 999.9999 : error_rate));
        par = par1;
        N *= 2;
    }
    printf("+-----+--------------+--------------+\n");
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
    printf("1 - Run verification calculation for N points\n");
    printf("2 - Compute parameter using N points\n");
    printf("3 - Compute parameter with specified accuracy\n");
    printf("4 - Save data to a file\n");
    printf("5 - Quit\n");
}
