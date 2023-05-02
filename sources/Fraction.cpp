#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <cmath>
#include <algorithm>

#include "Fraction.hpp"

using namespace std;
namespace ariel{

    Fraction::Fraction(int numerator,int denominator){
        if (denominator == 0) {
            throw invalid_argument("Denominator cannot be zero.");
        }
        if (denominator < 0) {
            numerator *= -1;
            denominator *= -1;
        }
        int gcdNum = __gcd(abs(numerator), denominator);
        _numerator = numerator / gcdNum;
        _denominator = denominator / gcdNum;
    }

    Fraction::Fraction(float frac){
        if(frac == 0){
            _numerator = 0;
            _denominator = 1;
        }
        else{
            int sign = frac < 0 ? -1 : 1;
            int numerator = abs(frac) * 1000;
            int denominator = 1000;
            int gcdNumDen = __gcd(abs(numerator), denominator);
            _numerator = sign * numerator / gcdNumDen;
            _denominator = denominator / gcdNumDen;
        }
    }
    float Fraction:: fraction_to_float(const Fraction& num){
        float result = static_cast<float>(num.getNumerator()) / num.getDenominator();
        return round(result * 1000.0) / 1000.0;   
    }

    // operator: +
    Fraction Fraction:: operator + (const Fraction& other) const {
        long checkNum = (long)(_numerator * other.getDenominator() )+ (long)(_denominator * other.getNumerator());
        if (checkNum > numeric_limits<int>::max() ||checkNum < numeric_limits<int>::min())
        {
            throw overflow_error("overflow error");
        }
        
        int nume = (_numerator * other.getDenominator() )+ (_denominator * other.getNumerator());
        int dene = _denominator * other.getDenominator();
        return Fraction(nume,dene);
    }
    Fraction  operator + (float num1, const Fraction& num2){
        Fraction temp = Fraction(num1) + num2;
        return temp;
    }
    Fraction operator + (const Fraction& num1, float num2){
        Fraction temp = num1 +Fraction(num2);
        return temp;
    }


    // operator: -
    Fraction Fraction:: operator - (const Fraction& other) const {
        long check = (long)(_numerator * other.getDenominator() )- (_denominator * other.getNumerator());;
        if (check > numeric_limits<int>::max())
        {
            throw overflow_error("overflow error");
        }
        int nume = (_numerator * other.getDenominator() )- (_denominator * other.getNumerator());
        int dene = _denominator * other.getDenominator();
        return Fraction(nume,dene);
    }

    Fraction  operator - (float num1, const Fraction& num2){
        Fraction temp = Fraction(num1) - num2;
        return temp;
    }
    Fraction operator - (const Fraction& num1, float num2){
        Fraction temp = num1 -Fraction(num2);
        return temp;
    }


    // operator: *
    Fraction Fraction:: operator * (const Fraction& other) const {
        long checkNum = ((long)_numerator * other.getNumerator());
        long checkDen = ((long)_denominator * other.getDenominator());
        if (checkNum > numeric_limits<int>::max() || checkDen > numeric_limits<int>::max())
        {
            throw overflow_error("overflow error");
        }
        int nume = _numerator * other.getNumerator();
        int deno = _denominator * other.getDenominator();
        return Fraction(nume,deno);
    }
    Fraction  operator * (float num1, const Fraction& num2){
        Fraction temp = Fraction(num1) * num2;
        return temp;
    }
    Fraction operator * (const Fraction& num1, float num2){
        Fraction temp = Fraction(num2) * num1;
        return temp;
    }


    // operator: /
    Fraction Fraction:: operator / (const Fraction& other) const {
        if(other == 0){
            throw runtime_error("Cant divide by zero.");
        }
        long checkNum = ((long) _numerator * other.getDenominator());
        long checkDen = ((long)_denominator * other.getNumerator());
        if (checkNum > numeric_limits<int>::max() || checkDen > numeric_limits<int>::max())
        {
            throw overflow_error("overflow error");
        }
        
        int nume = _numerator * other.getDenominator();
        int deno = _denominator * other.getNumerator();
        return Fraction(nume,deno);
    }
    Fraction  operator / (float num1, const Fraction& num2){
        if(num2 == 0){
           throw runtime_error("Cant divide by zero."); 
        }
        Fraction temp = Fraction(num1) / num2;
        return temp;
    }
    Fraction operator / (const Fraction& num1, float num2){
        if(num2 == 0){
           throw runtime_error("Cant divide by zero."); 
        }
        Fraction temp = num1/Fraction(num2);
        return temp;
    }

    // operator: ==
    bool Fraction:: operator == (const Fraction& other)const{
        float thisFloat = this->fraction_to_float(*this);
        float otherFloat = other.fraction_to_float(other);

        if(thisFloat == otherFloat){
            return true;
        }
        return false;       
    }
    bool operator == (float num1,const Fraction& num2){
        return Fraction(num1) == num2;
    }
    bool operator == (const Fraction& num1,float num2){
        return  num1 == Fraction(num2);
    }


    // operator: >
    bool Fraction::operator>(const Fraction& other) const {
        float check = fraction_to_float(other);
        return fraction_to_float(*this) > check;
    }

    bool operator>(float num1, const Fraction& num2) {
        float check = num2.fraction_to_float(num2);
        return num1 > check;
    }

    bool operator > (const Fraction& num1,float num2){
        float check = Fraction::fraction_to_float(num1);
        return check > num2;
    }


    //operator: <
    bool Fraction::operator<(const Fraction& other) const {
        float check = fraction_to_float(other);
        return fraction_to_float(*this) < check;
    }

    bool operator<(float num1, const Fraction& num2) {
        float check = num2.fraction_to_float(num2);
        return num1 < check;
    }

    bool operator < (const Fraction& num1,float num2){
        float check = Fraction::fraction_to_float(num1);
        return check < num2;
    }


    //operator: >=
    bool Fraction:: operator >= (const Fraction& other)const{
        return this->_numerator * other._denominator >= other._numerator * this->_denominator;
    }
    bool operator >= (float num1,const Fraction& num2){
        return Fraction(num1) >= num2;
    }
    bool operator >= (const Fraction& num1,float num2){
        return num1 >= Fraction(num2);
    }


    //operator: <=
    bool Fraction:: operator <= (const Fraction& other)const{
     return this->_numerator * other._denominator <= other._numerator * this->_denominator;
    }
    bool operator <= (float num1,const Fraction& num2){
        return Fraction(num1) <= num2;
    }
    bool operator <= (const Fraction& num1,float num2){
        return num1 <= Fraction(num2);
    }


    //operator: <<
    std::ostream& operator<<(std::ostream& ost, const Fraction& frac){
        ost << frac.getNumerator() << "/" << frac.getDenominator();
        return ost;
    }


    //operator: >>
    std::istream& operator >> (std::istream& input,Fraction& frac){
        int num, den;
        input >> num >> den;
        if(input.fail()){
            throw runtime_error("invalid argument!\n usage int numerator int denominator\n");
        }
        else if (den == 0) throw runtime_error("Denominator cannot be zero.");
        else{
            frac = Fraction(num,den);
        }
        return input;
    }
}
