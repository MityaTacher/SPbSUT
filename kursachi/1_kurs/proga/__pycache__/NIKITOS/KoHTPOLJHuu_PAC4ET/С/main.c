#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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
