#include <iostream>
#include <vector>
#include <sstream>
#include <cassert>
using namespace std;



enum Scale {
    Kelvin='K',
    Celsus='C',
    Farengete='F'
};

struct Temperature{
    Scale scale;
    double value;

};
//Temperature t;




istream & operator>>(istream & in, Temperature & t){
    char symbol;
    in>>t.value;
    in>>symbol;
    switch(symbol)
    {
    case 'K':
        t.scale=Kelvin;
        break;
    case 'C':
        t.scale=Celsus;
        break;
    case 'F':
        t.scale=Farengete;
        break;
    }
    return in;
}

void test_Temperature_input() {
    istringstream in("4K");
    Temperature t;
    in >> t;
    assert(t.value == 4);
    assert(t.scale == Kelvin);
    istringstream in1("12C");
    in1 >> t;
    assert(t.value == 12);
    assert(t.scale == Celsus);
    istringstream in2("17F");
    in2 >> t;
    assert(t.value == 17);
    assert(t.scale == Farengete);
}

Temperature convert(const Temperature & from,Scale scale)
{
    double kel;
    Temperature to;
    switch (from.scale){
    case Kelvin: kel= from.value;
        break;
    case Celsus: kel= from.value+273;
        break;
    case Farengete: kel= 1.8*(from.value-273)+32;
        break;
    }
    switch(scale){
    case Kelvin: to.value = kel;
        break;
    case Celsus: to.value = kel-273;
        break;
    case Farengete: to.value = (kel-32)/1.8+273;
        break;
    }
    to.scale=scale;
    return to;
}

int main() {

     test_Temperature_input;

    size_t number_count;
    cerr << "Enter number count: ";
    cin >> number_count;

    cerr << "Enter numbers: ";
    vector<double> numbers(number_count);
    for (size_t i = 0; i < number_count; i++) {
        cin >> numbers[i];
    }

    size_t column_count;
    cerr << "Enter column count: ";
    cin >> column_count;

    double min = numbers[0];
    double max = numbers[0];
    for (double number : numbers) {
        if (number < min) {
            min = number;
        }
        if (number > max) {
            max = number;
        }
    }

    vector<size_t> counts(column_count);
    for (double number : numbers) {
        size_t column = (size_t)((number - min) / (max - min) * column_count);
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