#include "doctest.h"
#include <stdexcept>
#include "sources/Fraction.hpp"

using namespace std;
using namespace ariel;


TEST_CASE("+"){
   Fraction x(1,5);
   Fraction y(0,5);
   Fraction z(8,2);
   CHECK_EQ(x+y,x);
   CHECK_EQ(x+x,0.4);
   CHECK_EQ(2+y,2);
   CHECK_EQ(z+x,4.2);
}
TEST_CASE("-"){
   Fraction x(1,5);
   Fraction y(0,5);
   Fraction z(8,2);
   CHECK_EQ(x-y,x);
   CHECK_EQ(x-x,0.0);
   CHECK_EQ(y-2,-2.0);
   CHECK_EQ(z-y,3.8);
}

TEST_CASE("*"){
    Fraction x(1,5);
    Fraction y(0,5);
    Fraction z(8,2);
    CHECK_EQ(x*y,0.0);
    CHECK_EQ(x*x,0.04);
    CHECK_EQ(2*y,0.0);
    CHECK_EQ(x*z,0.8);
}

TEST_CASE("/"){
    Fraction x(1,5);
    Fraction y(0,5);
    Fraction z(8,2);
    CHECK_THROWS(x/y);
    CHECK_EQ(x/x,1.0);
    CHECK_EQ(y/2,0.0);
    CHECK_EQ(z/x,20.0);
    CHECK_EQ(x/z,0.05);
}

TEST_CASE("<,>,<=,>=,=="){
    Fraction x(1,5);
    Fraction y(0,5);
    Fraction z(8,2);
    CHECK_GT(x,y);
    CHECK_LT(x,z);
    CHECK_GE(z,3.0);
    CHECK_LE(y,0);
    CHECK_EQ(y,0.0);
}
TEST_CASE(" ++ , -- "){
    Fraction x(1,2);
    CHECK_EQ(x--,-1.5);
    CHECK_EQ(--x,-1.5);
    CHECK_EQ(++x,1.5);
    CHECK_EQ(x++,1.5);
    Fraction y(1,1);
    CHECK_EQ(y--,0);
    CHECK_EQ(--y,0);
}
