#include <stdlib.h>
#include <stdio.h>

#include "io.h"
#include "logic.h"

#ifdef _WIN32
    #define CLEAR_SCREEN() system("cls")
#else
    #define CLEAR_SCREEN() system("clear")
#endif


void menu()
{
    int choice;
    char stop;
    while (1 == 1)
    {
        print_menu();

        scanf("%d", &choice);
        switch(choice)
        {
        case 1:
            print_write_voltages(0);
            break;
        case 2:
            print_parametr();
            break;
        case 3:
            print_param_with_an_error();
            break;
        case 4:
            print_write_voltages(1);
            break;
        case 5:
            return;
            break;
        default:
            CLEAR_SCREEN();
            continue;
            break;
        }
        printf("\nTerminate?[Y/N] ");
        getchar();
        stop = getchar();
        if (stop == 'y' || stop == 'Y')
        {
            return;
        }

        CLEAR_SCREEN();

    }
}
