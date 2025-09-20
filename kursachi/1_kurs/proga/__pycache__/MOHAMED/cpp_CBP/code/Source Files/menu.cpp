#include "menu.h"
#include "io.h"
#include "logic.h"
#include <iostream>
#include <cstdlib>
#include <iomanip>

using namespace std;

#ifdef _WIN32
    #define CLEAR_SCREEN() system("cls")
#else
    #define CLEAR_SCREEN() system("clear")
#endif

void print_parameter() {
    int N = input_number_points();
    vector<double> Uvx_array(N), Uvix_array(N), time_array(N);
    fill_all_arrays(N, time_array, Uvx_array, Uvix_array);

    cout << "Input signal pulse width: " << setprecision(7) << get_impuls_length(N, Uvx_array)
              << "\nOutput signal pulse width: " << get_impuls_length(N, Uvix_array);
}

void print_write_voltages(bool write) {
    int N = input_number_points();
    vector<double> Uvx_array(N), Uvix_array(N), time_array(N);
    fill_all_arrays(N, time_array, Uvx_array, Uvix_array);

    if (!write) {
        print_arrays(N, time_array, Uvx_array, Uvix_array);
    }
    else {
        save_array(N, time_array, "data/time_array.txt");
        save_array(N, Uvx_array, "data/Uvx_array.txt");
        save_array(N, Uvix_array, "data/Uvix_array.txt");
        cout << "Done";
    }
}

void menu() {
    int choice;
    string stop;

    while (true) {
        readFile("code/Resources Files/zastavka.txt");
        cout << "1 - Control calculation for N points\n";
        cout << "2 - Calculation of a parameter with N points\n";
        cout << "3 - Calculation of a parameter with a given accuracy\n";
        cout << "4 - Writing data to a file\n";
        cout << "5 - Exit\n";
        cout << "Enter your choice: ";

        cin >> choice;
        switch(choice) {
            case 1:
                print_write_voltages(false);
                break;
            case 2:
                print_parameter();
                break;
            case 3:
                print_struct(get_param_with_an_error());
                break;
            case 4:
                print_write_voltages(true);
                break;
            case 5:
                return;
            default:
                CLEAR_SCREEN();
                continue;
        }

        cout << "\nTerminate?[Y/N] ";
        cin >> stop;
        if (stop == "y" || stop == "Y") {
            return;
        }

        CLEAR_SCREEN();
    }
}
