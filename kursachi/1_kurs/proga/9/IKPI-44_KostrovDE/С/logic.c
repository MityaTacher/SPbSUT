#include <math.h>
#include <stdlib.h>
#include <stdio.h>


#define TN 5.0
#define TK 50.0

#define T1 15.0
#define T2 45.0
#define A 20.0
#define B 0.5
#define C 17.0

#define A1 5.0
#define B1 0.5


double Uvx(double t)
{
    if (t <= T1)
    {
        return A * (t - TN);
    }
    if (T1 < t && t <= T2)
    {
        return A * (T1 - TN) - B * (t - T1);
    }
    if (t > T2)
    {
        return A * (T1 - TN) - B * (T2 - T1) - C * (t - T2);
    }
    printf("\tt = %F\tSomething went wrong...\n", t);
    return 0;
}


double Uvix(double t)
{
    return A1 * exp(B1 * Uvx(t));
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
    double dt = (TK - TN) / (N - 1.0);
    double t = TN;
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


double two_point_equation(double x, double x1, double x2, double y1, double y2)
{
    return (x - x1) * (y2 - y1) / (x2 - x1 + 0.0) + y1;
}


double get_real_param()
{
    return A * (T1 - TN) - B * (T2 - T1) - C * (45 - T2);
}


double get_param(int N, double time_array[], double Uvx_array[])
{
    const int boreder_point = 45;
    int border;
    for (int i = 0; i < N; i++)
    {
        if (time_array[i] > 45)
        {
            border = i;
            break;
        }
    }
    double Uvx = two_point_equation(45,
        time_array[border - 1], time_array[border],
        Uvx_array[border - 1], Uvx_array[border]);
    return Uvx;
}

