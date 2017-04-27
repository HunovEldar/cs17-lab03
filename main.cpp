#include <iostream>
#include <vector>



#include "Temperature.h"
using namespace std;


int main() {

//     test_Temperature_input;

    size_t temp_count;
    cerr << "Enter number count: ";
    cin >> temp_count;

    cerr << "Enter numbers: ";
    vector<Temperature> temp(temp_count);
    for (size_t i = 0; i < temp_count; i++) {
        cin >> temp[i];
    }
    vector<Temperature> temprez(temp_count);
    for (size_t i = 0; i < temp_count; i++) {
         temprez[i]=convert(temp[i], Kelvin);
    }
    size_t column_count;
    cerr << "Enter column count: ";
    cin >> column_count;

    double min = temprez[0].value;
    double max = temprez[0].value;
    for ( const Temperature number : temp) {
        if (number.value< min) {
            min = number.value;
        }
        if (number.value > max) {
            max = number.value;
        }
    }

    vector<size_t> counts(column_count);
    for (Temperature number : temp) {
        size_t column = (size_t)((number.value - min) / (max - min) * column_count);
        if (column == column_count) {
            column--;
        }
        counts[column]++;
    }

    const size_t screen_width = 80;
    const size_t axis_width = 4;
    const size_t chart_width = screen_width - axis_width;

    // Можно было бы считать в предыдущем цикле, но так более наглядно.
    size_t max_count = 0;
    for (size_t count : counts) {
        if (count > max_count) {
            max_count = count;
        }
    }
    const bool scaling_needed = max_count > chart_width;

    for (size_t count : counts) {
        if (count < 100) {
            cout << ' ';
        }
        if (count < 10) {
            cout << ' ';
        }
        cout << count << "|";

        size_t height = count;
        if (scaling_needed) {
            // Point: код должен быть в первую очередь понятным.
            const double scaling_factor = (double)chart_width / max_count;
            height = (size_t)(count * scaling_factor);
        }

        for (size_t i = 0; i < height; i++) {
            cout << '*';
        }
        cout << '\n';
    }

    return 0;
}