#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define TN 5.0
#define TK 50.0
#define T1 15.0
#define T2 45.0
#define A 20.0
#define B 0.5
#define C 17.0
#define A1 5.0
#define B1 0.5
#define N 51.0
#define DT (TK - TN) / (N - 1.0)

double Uvx(double t)
{
    if (t < T1)
    {
        return A * (t - TN);
    }
    if (T1 < t && t < T2)
    {
        return A * (T1 - TN) - B * (t - T1);
    }
    if (t > T2)
    {
        return A * (T1 - TN) - B * (T2 - T1) - C * (t - T2);
    }
    printf("\t\tSomething went wrong...\n");
    return 0;
}

double Uvix(double t)
{
    return A1 * exp(B1 * Uvx(t));
}

double get_param()
{
    return (A * (T1 - TN) - B * (T2 - T1)) / C + 45 - T2;
}

int main()
{
    FILE *f1, *f2, *f3;
    f1 = fopen("massiv_t.txt", "w");
    f2 = fopen("massiv_Uvx.txt", "w");
    f3 = fopen("massiv_Uvix.txt", "w");
    printf("%.*s\n", 36, "------------------------------------");
    for (double t = TN; t <= TK; t += DT)
    {
        if (t != TN) printf("%.*s\n", 36, "|--------|----------|--------------|");
        printf("|  %4.1f  |  %6.2f  |  %10.4e  |\n", t, Uvx(t), Uvix(t));
        fprintf(f1, "\n%4.1f", t);
        fprintf(f2, "\n%6.2f", Uvx(t));
        fprintf(f3, "\n%10.4f", Uvix(t));
    }
    printf("%.*s\n", 36, "------------------------------------");
    fclose(f1);
    fclose(f2);
    fclose(f3);


    printf("Parametr: %.4f", get_param());

    return 0;
}
