#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// constanti dlya KOD A
#define U 5.0
#define T 0.00001

// NACHALNAYA i KONECHNAYA TOCHKI
#define tn 0
#define tk T

// constanti dlya KOD B
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
    else if (T / 4 <= t && t  < 3 * T / 4)
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
    return 77777.777777;
}


int main()
{
    int N = 50;
    double dt = (tk - tn) / (N - 1.0);
    int i = 0;
    double t = tn;
    while (i < N)
        {
            printf("%d\tUvx(%.9lf)=%.0lf\n", i + 1, t, Uvx(t));
            printf("%d\tUvix(%.9lf)=%.1lf\n", i + 1, t, Uvix(t));
            i++;
            t += dt;
        }
    return 0;
}
