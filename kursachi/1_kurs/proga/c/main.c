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

double Uvx(double t)
{
    if (t <= T1)
    {
        return A * (t - TN);
    }
    if (T1 < t && t <= T2)
    {
        return A * (T1 - TN) - B * (t - T1);
    }
    if (t > T2)
    {
        return A * (T1 - TN) - B * (T2 - T1) - C * (t - T2);
    }
    printf("\tt = %F\tSomething went wrong...\n", t);
    return 0;
}

double Uvix(double t)
{
    return A1 * exp(B1 * Uvx(t));
}

double getParam()
{
    return A * (T1 - TN) - B * (T2 - T1) - C * (45 - T2);
}

void printData(int print)
{
    int N;
    printf("Enter N: ");
    scanf("%d", &N);
    double DT = (TK - TN) / (N - 1.0);
    FILE *f1, *f2, *f3;
    f1 = fopen("massiv_t.txt", "w");
    f2 = fopen("massiv_Uvx.txt", "w");
    f3 = fopen("massiv_Uvix.txt", "w");
    if (print == 1)
    {
        printf("%.*s\n", 43, "-------------------------------------------");
        printf("%.*s\n", 43, "|  No  |    t   |    Uvx   |     Uvix     |");
        printf("%.*s\n", 43, "|------|--------|----------|--------------|");
    }
    int i = 0;
    double t = TN;
    while (i != N)
    {
        if (t != TN && print == 1) printf("%.*s\n", 43, "|------|--------|----------|--------------|");
        if (print == 1) printf("|  %2d  |  %4.1f  |  %6.2f  |  %10.4e  |\n", i + 1, t, Uvx(t), Uvix(t));
        fprintf(f1, "%4.1f\n", t);
        fprintf(f2, "%6.2f\n", Uvx(t));
        fprintf(f3, "%10.4f\n", Uvix(t));
        t += DT;
        i++;
    }
    if (print == 1) printf("%.*s\n", 43, "-------------------------------------------");
    fclose(f1);
    fclose(f2);
    fclose(f3);
}

void printParametr()
{
    int t;
    printf("Set the parametr's accuracy (from 0 to 15): ");
    scanf("%d", &t);
    printf("Parametr: %.*f\n", t, getParam());
}

int main()
{
    int ch;
    char stop;
    while (1 == 1)
    {
        printf("1 - control calculation for n points\n2 - calculation of a parameter with a given accuracy\n3 - writing data to a file\n");
        scanf("%d", &ch);
        switch(ch)
        {
        case 1:
            printData(1);
            break;
        case 2:
            printParametr();
            break;
        case 3:
            printData(0);
            printf("Done");
            break;
        default:
            continue;
            break;
        }
        printf("\nTerminate?[Y/N] ");
        getchar();
        stop = getchar();
        if (stop == 'y' || stop == 'Y')
        {
            break;
        }
    }
    return 0;
}
