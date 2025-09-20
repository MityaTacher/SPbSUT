#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// йнмярюмрш йнд ю
#define U 5.0
#define a 2.0

// мювюкэмне, йнмевмне
#define tn 0.0
#define tk 2.0 * M_PI

// йнмярюмрш йнд а
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


int main()
{
    int N = 50;
    double dt = (tk - tn) / (N - 1.0);
    int i = 0;
    double t = tn;
    while (i < N)
        {
            printf("%d\tUvx(%lf)=%lf\n", i + 1, t, Uvx(t));
            printf("%d\tUvix(%lf)=%lf\n", i + 1, t, Uvix(t));
            i++;
            t += dt;
        }
    return 0;
}
