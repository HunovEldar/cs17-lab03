//
// Created by u211-16 on 27.04.2017.
//

#ifndef CS17_LAB03_TEMPERATURE_H
#define CS17_LAB03_TEMPERATURE_H

#include<iostream>

enum Scale {
    Kelvin='K',
    Celsus='C',
    Farengete='F'
};

struct Temperature{
    Scale scale;
    double value;

};
std::istream & operator>>(std::istream & in, Temperature & t);
Temperature convert(const Temperature & from,Scale scale);
bool operator<(const Temperature & lhs,Temperature & rhs);


#endif //CS17_LAB03_TEMPERATURE_H

