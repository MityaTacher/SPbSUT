#include "logic.h"
#include "error_struct.h"
#include <cmath>
#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

constexpr double U = 5;
constexpr double T = 2.0 * pow(10, -5);

constexpr double U1 = 2.0;
constexpr double U2 = 50.0;

constexpr double tn = 0.0;
constexpr double tk = T * 2.0;

double Uvx(double t) {
    if (0 <= t && t < T / 2)
    {
        return 2 * U * t / T;
    }
    else if (T / 2 <= t && t < T)
    {
        return 2 * U * (T-t) / T;
    }
    else if (T <= t && t < 3 * T / 2)
    {
        return 2 * U * (t - T) / T;
    }
    else if (3 * T / 2 <= t && t <= 2 * T)
    {
        return 2 * U * (2 * T - t) / T ;
    }
}

double Uvix(double t) {
    double current_Uvx = Uvx(t);
    if (current_Uvx < U1)
    {
        return U2 / pow(U1, 2) * current_Uvx * (2 * U1 - current_Uvx);
    }
    else
    {
        return U2;
    }
}

void get_io_voltage(int N, const vector<double>& time_array, vector<double>& output_array, int func) {
    for (int i = 0; i < N; i++) {
        output_array[i] = (func == 0) ? Uvx(time_array[i]) : Uvix(time_array[i]);
    }
}

void get_time(int N, vector<double>& output_array) {
    double dt = (tk - tn) / (N - 1.0);
    double t = tn;
    for (int i = 0; i < N; i++) {
        output_array[i] = t;
        t += dt;
    }
}

void fill_all_arrays(int N, vector<double>& time_array, vector<double>& Uvx_array, vector<double>& Uvix_array) {
    get_time(N, time_array);
    get_io_voltage(N, time_array, Uvx_array, 0);
    get_io_voltage(N, time_array, Uvix_array, 1);
}

double get_impuls_length(int N, const vector<double>& input_array) {
    double max = input_array[0];
    double min = input_array[0];

    for (int i = 1; i < N; i++) {
        if (input_array[i] > max) max = input_array[i];
        if (input_array[i] < min) min = input_array[i];
    }

    double dt = (tk - tn) / (N - 1.0);
    double Uavg = (max + min) / 2.0;
    double dlit = 0;

    for (int i = 0; i < N; i++) {
        if (input_array[i] > Uavg) {
            dlit += dt;
        }
    }
    return dlit;
}


vector<Error> get_param_with_an_error() {
    double error_rate_Uvx = 1, error_rate_Uvix = 1;
    constexpr double eps = 0.01;
    double par_Uvx = 1e+10, par1_Uvx;
    double par_Uvix = 1e+10, par1_Uvix;
    int N = 11, c = 0;
    vector<Error> error_list;

    while (error_rate_Uvx > eps && error_rate_Uvix > eps) {
        vector<double> Uvx_array(N), Uvix_array(N), time_array(N);
        fill_all_arrays(N, time_array, Uvx_array, Uvix_array);

        par1_Uvx = get_impuls_length(N, Uvx_array);
        par1_Uvix = get_impuls_length(N, Uvix_array);
        error_rate_Uvx = fabs(par_Uvx - par1_Uvx) / par1_Uvx;
        error_rate_Uvix = fabs(par_Uvix - par1_Uvix) / par1_Uvix;

        Error error {N, par1_Uvx, par1_Uvix, max(error_rate_Uvx, error_rate_Uvix)};
        error_list.push_back(error);

        par_Uvx = par1_Uvx;
        par_Uvix = par1_Uvix;
        N *= 2;
        c++;
    }
    return error_list;
}




