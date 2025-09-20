#include "io.h"
#include "error_struct.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <filesystem>
#include <windows.h>

using namespace std;

void print_arrays(int N, const vector<double>& time, const vector<double>& Uvx, const vector<double>& Uvix) {
    cout << "+------+------------+----------+----------+\n";
    cout << "|  No  |    time    |   Uvx    |   Uvix   |\n";
    cout << "+------+------------+----------+----------+\n";

    for (int i = 0; i < N; i++) {
        cout << "| " << setw(4) << i + 1
                  << " | " << setw(10) << fixed << setprecision(7) << time[i]
                  << " | " << setw(8) << setprecision(4) << Uvx[i]
                  << " | " << setw(8) << Uvix[i] << " |\n";
    }

    cout << "+------+------------+----------+----------+\n";
}

void save_array(int N, const vector<double>& array_, const string& name) {
    filesystem::path dir = filesystem::path(name).parent_path();
    if (!dir.empty() && !filesystem::exists(dir)) {
        filesystem::create_directories(dir);
    }

    ofstream file(name);
    if (!file.is_open()) {
        cerr << "File error: " << name << endl;
        return;
    }
    file << fixed << setprecision(10);
    for (int i = 0; i < N; i++) {
        file << array_[i] << "\n";
    }
    file.close();
}

void print_struct(const vector<Error> error_list){
    cout << "+-----+--------------|---------------+------------+\n";
    cout << "|  N  | Input length | Output length | Error rate |\n";
    cout << "+-----+--------------|---------------+------------+\n";

    for (int i = 0; i < error_list.size(); i++){
        cout << "| " << setw(3) << error_list[i].N
                << " | " << setw(12) << fixed << setprecision(6) << error_list[i].Uvx_parametr
                << " | " << setw(13) << fixed << setprecision(6) << error_list[i].Uvix_parametr
                << " | " << setw(10) << (error_list[i].error_rate > 9999 ? scientific : fixed)
                << setprecision(4) << error_list[i].error_rate << " |\n";
    }
    cout << "+-----+--------------|---------------+------------+\n";
}


void readFile(const string& name) {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    ifstream file(name);
    string line;
    while (getline(file, line)) {
        cout << line << endl;
    }
}

int input_number_points() {
    int N;
    cout << "Enter number of points: ";
    cin >> N;
    return N;
}
