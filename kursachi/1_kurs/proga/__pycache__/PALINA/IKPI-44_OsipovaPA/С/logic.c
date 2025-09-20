#include <math.h>
#include <stdlib.h>
#include <stdio.h>


#define U 5.0
#define T 0.00001

#define tn 0
#define tk T

#define U0 5
#define U1 10
#define U2 75
#define U3 90

#define Uvx0 0
#define Uvx1 10
#define Uvx2 40
#define Uvx3 10


double Uvx(double t)
{
    if (0 <= t && t < T / 4)
    {
        return 0;
    }
    else if (T / 4 <= t && t < 3 * T / 4)
    {
        return U;
    }
    else
    {
        return 0;
    }
}


double Uvix(double t)
{
    if (Uvx(t) <= Uvx1)
    {
        return (Uvx(t) - Uvx0) * (U1 - U0) / (Uvx1 - Uvx0) + U0;
    }
    else if (Uvx1 < Uvx(t) && Uvx(t) <= Uvx2)
    {
        return (Uvx(t) - Uvx1) * (U2- U1) / (Uvx2 - Uvx1) + U1;
    }
    else if (Uvx2 < Uvx(t) && Uvx(t) <= Uvx3)
    {
        return (Uvx(t) - Uvx2) * (U3 - U2) / (Uvx3 - Uvx2) + U2;
    }
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


double get_impuls_lenght(int N, double *input_array)
{
    double dt = (tk - tn) / (N - 1.0);
    double Uavg = (get_max_value(N, input_array) + get_min_value(N, input_array)) / 2.0;
    double dlit = 0;
    for (int i = 0; i < N; i++)
    {
        if (input_array[i] > Uavg)
        {
            dlit += dt;
        }
    }
    return dlit;
}

