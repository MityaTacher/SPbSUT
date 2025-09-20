#include <math.h>
#include <stdlib.h>
#include <stdio.h>


// constanti dlya KOD A
#define U0 5.0
#define U1 15.0
#define U2 10.0
#define T 1

// NACHALNAYA i KONECHNAYA TOCHKI
#define tn 0
#define tk T

// constanti dlya KOD B
#define Uvx1 10.0
#define Uvx2 20.0
#define Uvix1 35.0
#define Uvix2 60.0



double Uvx(double t)
{
    return U0 + U1 * sin(2 * M_PI * t / T) + U2 * sin(4 * M_PI * t / T);
}

double Uvix(double t)
{
    double Uvx_current = Uvx(t);
    if (Uvx_current <= Uvx1)
    {
        return Uvix1;
    } else if (Uvx1 < Uvx_current && Uvx_current <= Uvx2)
    {
        return (Uvx_current - Uvx1) * (Uvix2 - Uvix1) / (Uvx2 - Uvx1) + Uvix1;
    } else
    {
        return Uvix2;
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


double get_max_Uvx(int N, double *uvx_array)
{
    double dt = (tk - tn) / (N - 1.0);
    double Umax = get_max_value(N, uvx_array);
    for (int i = 0; i < N; i++)
    {
        if (uvx_array[i] == Umax)
        {
            return i * dt;
        }
    }
}

