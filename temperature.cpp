//
// Created by u211-16 on 27.04.2017.
//
#include"Temperature.h"
using namespace std;
std::istream & operator>>(std::istream & in, Temperature & t){
    char symbol;
    in>>t.value;
    if(!in){
        in.setstate(ios_base::failbit);
                return in;
    }
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
    default:
        in.setstate(ios_base::failbit);
    }
    if(convert(t, Kelvin).value < 0){
        in.setstate(ios_base::failbit);
        return in;
    }


    return in;
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
bool operator<(const Temperature & lhs,Temperature & rhs){
    Temperature out;
    out = convert(lhs,rhs.scale);
    return lhs.value < rhs.value;
}