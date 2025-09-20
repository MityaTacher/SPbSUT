#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// constanti dlya KOD A
#define U0 40.0

// NACHALNAYA i KONECHNAYA TOCHKI
#define tn 0
#define tk (2.0 * M_PI)

// constanti dlya KOD B
#define a 2.5

#define b 10.0

#define Uvx1 10.0
#define Uvx2 30.0


double Uvx(double t)
{
    return U0 * fabs(sin(t));
}

double Uvix(double t)
{
    if (Uvx(t) <= Uvx1)
    {
        return a * Uvx1 + b;
    }
    else if (Uvx1 < Uvx(t) && Uvx(t) <= Uvx2)
    {
        return a * Uvx(t) + b;
    }
    else if (Uvx(t) > Uvx2)
    {
        return a * Uvx2 + b;
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
            printf("%d\tUvx(%.9lf) = %lf\n", i + 1, t, Uvx(t));
            printf("%d\tUvix(%.9lf) = %lf\n", i + 1, t, Uvix(t));
            i++;
            t += dt;
        }
    return 0;
}
