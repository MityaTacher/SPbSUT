#include <math.h>

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
