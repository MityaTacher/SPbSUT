#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define U1 15.0
#define U2 8.0
#define T 2.0

#define tn 0.0
#define tk 4.0

#define V1 32.0
#define V2 60.0

#define Uvx1 12.0
#define Uvx2 20.0


double Uvx(double t)
{
    return U1 * cos(2 * M_PI * t / T) + U2 * cos(3 * M_PI * t / T);
}


double Uvix(double t)
{
    if (Uvx(t) <= Uvx1)
    {
        return V1;
    }
    else if (Uvx1 < Uvx(t) && Uvx(t) <= Uvx2)
    {
        return (Uvx(t) - Uvx1) * (V2 - V1) / (Uvx2 - Uvx1) + V1;
    }
    else
    {
        return V2;
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
            printf("%d\tUvx(%.9f)=%.3f\n", i + 1, t, Uvx(t));
            printf("%d\tUvix(%.9f)=%.3f\n", i + 1, t, Uvix(t));
            i++;
            t += dt;
        }
    return 0;
}
