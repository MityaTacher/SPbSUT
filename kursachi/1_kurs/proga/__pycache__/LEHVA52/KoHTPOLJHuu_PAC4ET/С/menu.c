#include <stdlib.h>
#include <stdio.h>

#include "io.h"
#include "logic.h"

#ifdef _WIN32
    #define CLEAR_SCREEN() system("cls")
#else
    #define CLEAR_SCREEN() system("clear")
#endif

void print_parametr()
{

}


void print_write_voltages(double time_array[], double Uvx_array[], double Uvix_array[], int write)
{
    int N = 0;
    printf("Enter number of points: ");
    scanf("%d", &N);
    get_time(N, time_array);
    get_io_voltage(N, time_array, Uvx_array, 0);
    get_io_voltage(N, time_array, Uvix_array, 1);
    if (write == 0)
    {
        print_arrays(N, time_array, Uvx_array, Uvix_array);
    }
    else
    {
        save_array(N, time_array, "../data/time_array.txt");
        save_array(N, Uvx_array, "../data/Uvx_array.txt");
        save_array(N, Uvix_array, "../data/Uvix_array.txt");
        printf("Done");
    }
}


void menu()
{
    int N = 13;
    double Uvx_array[N], Uvix_array[N], time_array[N];

    int ch;
    char stop;
    while (1 == 1)
    {
        printf("1 - control calculation for n points\n2 - calculation of a parameter with a given accuracy\n3 - writing data to a file\n");
        scanf("%d", &ch);
        switch(ch)
        {
        case 1:
            print_write_voltages(time_array, Uvx_array, Uvix_array, 0);
            break;
        case 2:
            print_parametr(); // TODO  make func param
            break;
        case 3:
            print_write_voltages(time_array, Uvx_array, Uvix_array, 1);
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
        CLEAR_SCREEN();

    }
}
