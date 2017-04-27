//
// Created by u211-16 on 27.04.2017.
//
#include <sstream>
#include <cassert>
#include "Temperature.h"
using namespace std;

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
    istringstream in4("-100K");
    in4>>t;
    assert(!in4);

}
int main()
{
test_Temperature_input();
    return 0;
}
