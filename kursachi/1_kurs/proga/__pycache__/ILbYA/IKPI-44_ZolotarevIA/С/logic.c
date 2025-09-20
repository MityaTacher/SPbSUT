#include <math.h>
#include <stdlib.h>
#include <stdio.h>

// constanti dlya KOD A
#define U 10.0
#define a 1.5

// NACHALNAYA i KONECHNAYA TOCHKI
#define tn -1.5
#define tk 1.5

// constanti dlya KOD B
#define a1 0.25
#define a2 0.5
#define a3 1.1
#define a4 25.0

#define b1 9.0
#define b2 7.75
#define b3 0.25
#define b4 -29.75

#define Uvx1 5.0
#define Uvx2 15.0
#define Uvx3 30.0


double Uvx(double t)
{
    return U * exp(-pow(a, 2) * pow(t, 2));
}

double Uvix(double t)
{
    if (Uvx(t) <= Uvx1)
    {
        return a1 * Uvx(t) + b1;
    }
    else if (Uvx1 < Uvx(t) && Uvx(t) <= Uvx2)
    {
        return a2 * Uvx(t) + b2;
    }
    else if (Uvx2 < Uvx(t) && Uvx(t) <= Uvx3)
    {
        return a3 * Uvx(t) + b3;
    }
    else
    {
        return a4 * Uvx(t) + b4;
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


double get_param(int N, double *uvix_array)
{
    double dt = (tk - tn) / (N - 1.0);
    for (int i = 0; i < N; i++)
    {
        if (uvix_array[i] >= 11.11)
        {
            return dt * i + tn;
        }
    }
    return 0;
}

