#include <math.h>
#include <stdlib.h>
#include <stdio.h>


// constanti dlya KOD A
#define U 2.0
#define a 3.0

// NACHALNAYA i KONECHNAYA TOCHKI
#define tn M_PI
#define tk 2.0 * M_PI

// constanti dlya KOD B
#define a1 2.0
#define b1 4.0
#define c1 -1.0


double Uvx(double t)
{
    return U * exp(a * sin(t));
}

double Uvix(double t)
{
    return a1 * pow(Uvx(t), 2) + b1 * Uvx(t) + c1;
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


double get_time_min_Uvix(int N, double *uvix_array)
{
    double dt = (tk - tn) / (N - 1.0);
    double Umin = get_min_value(N, uvix_array);
    double dlit = 0;
    for (int i = 0; i < N; i++)
    {
        if (uvix_array[i] == Umin)
        {
            return dlit + tn;
        }
        else
        {
            dlit += dt;
        }
    }
}

