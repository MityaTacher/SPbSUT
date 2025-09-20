#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// constanti dlya KOD A
#define U 250.0

// NACHALNAYA i KONECHNAYA TOCHKI
#define tn -10.0
#define tk 10.0

// constanti dlya KOD B
#define a 400.0
#define U0 50.0
#define U1 100.0


double Uvx(double t)
{
    if (t <= 0)
    {
        return (t - tn) * (U - 0) / (0 - tn) + 0;
    } else
    {
        return (t - 0) * (0 - U) / (tk - 0) + U;
    }
}


double Uvix(double t)
{
    if (0 <= Uvx(t) && Uvx(t) <= U0)
    {
        return pow(a * pow(Uvx(t), 2), (1.0 / 3.0));
    } else
    {
        return U1;
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
