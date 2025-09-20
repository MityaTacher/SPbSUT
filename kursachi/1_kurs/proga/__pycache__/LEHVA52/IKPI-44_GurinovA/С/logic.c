#include <math.h>
#include <stdlib.h>
#include <stdio.h>


#define U 5.0
#define a 2.0

#define tn 0.0
#define tk 2.0 * M_PI

#define a1 2.0
#define b1 -5.0
#define Uvx1 20.0


double Uvx(double t)
{
    return U * exp(a * sin(t));
}


double Uvix(double t)
{
    if (Uvx(t) <= Uvx1)
    {
        return a1 * Uvx(t) + b1;
    }
    return a1 * Uvx1 + b1;
}


void get_io_voltage(int N, double *time_array, double *output_array, int func)
{
    int i = 0;
    while (i < N)
        {
            if (func == 0)
            {
                output_array[i] = Uvx(time_array[i]);
            } else
            {
                output_array[i] = Uvix(time_array[i]);
            }
            i++;
        }
}


void get_time(int N, double *output_array)
{
    double dt = (tk - tn) / (N - 1.0);
    double t = tn;
    int i = 0;
    while (i < N)
        {
            output_array[i] = t;
            i++;
            t += dt;
        }
}


void fill_all_arrays(int N, double time_array[], double Uvx_array[], double Uvix_array[])
{
    get_time(N, time_array);
    get_io_voltage(N, time_array, Uvx_array, 0);
    get_io_voltage(N, time_array, Uvix_array, 1);
}


double get_max_value(int N, double *input_array)
{
    double max = input_array[0];
    for (int i = 0; i < N; i++)
    {
        if (input_array[i] > max)
        {
            max = input_array[i];
        }
    }
    return max;
}


double get_min_value(int N, double *input_array)
{
    double min = input_array[0];
    for (int i = 0; i < N; i++)
    {
        if (input_array[i] < min)
        {
            min = input_array[i];
        }
    }
    return min;
}


double get_trailing_edge_duration(int N, double *input_array)
{
    double Umax =  get_max_value(N, input_array);
    double Umin =  get_min_value(N, input_array);
    double U1 = Umin + 0.1 * (Umax - Umin);
    double U2 = Umin + 0.9 * (Umax - Umin);

    double dt = (tk - tn) / (N - 1.0);
    double dlit = 0;
    for (int i = 0; i < N - 1; i++)
    {
        if (input_array[i] >= U1 && input_array[i] < U2 && input_array[i + 1] < input_array[i])
        {
            dlit += dt;
        }
    }
    return dlit;
}
