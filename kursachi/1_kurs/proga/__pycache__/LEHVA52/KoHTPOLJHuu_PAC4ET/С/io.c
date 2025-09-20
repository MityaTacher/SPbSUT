#include <stdlib.h>
#include <stdio.h>

#include "menu.h"

void print_arrays(int N, double *time, double *Uvx, double *Uvix) {
    printf("+------+----------+----------+----------+\n");
    printf("|  No  |   time   |   Uvx    |   Uvix   |\n");
    printf("+------+----------+----------+----------+\n");

    for (int i = 0; i < N; i++) {
        printf("| %4d | %8.4f | %8.4f | %8.4f |\n", i + 1, time[i], Uvx[i], Uvix[i]);
    }

    printf("+------+----------+----------+----------+\n");
}

void save_array(int N, double *array, char *name)
{
    FILE *file = fopen(name, "w");
    if (!file)
    {
        perror("File error");
        return;
    }
    int i = 0;
    while (i < N)
    {
        fprintf(file, "%lf\n", array[i]);
        i++;
    }
    fclose(file);
}
