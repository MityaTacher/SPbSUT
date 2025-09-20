#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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
