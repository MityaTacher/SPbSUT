#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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


int main()
{
    int N = 50;
    double dt = (tk - tn) / (N - 1.0);
    int i = 0;
    double t = tn;
    while (i < N)
        {
            printf("%d\tUvx(%.9lf)=%.4lf\n", i + 1, t, Uvx(t));
            printf("%d\tUvix(%.9lf)=%.4lf\n", i + 1, t, Uvix(t));
            i++;
            t += dt;
        }
    return 0;
}
