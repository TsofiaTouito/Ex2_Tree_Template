// tsofiatouito2@gmail.com

#include <iostream>
#include "Complex.hpp"


double Complex::real() const {
    return this->rea;
}

double Complex::imagin() const{
    return this->img;
}


// Logical NOT
bool Complex::operator!() const{
    return rea == 0 && img == 0;
}

Complex Complex::operator-(){
    return Complex(-rea, -img);
}

//binary operators
Complex Complex::operator+(const Complex& other) const{
    return Complex(this->rea + other.real(), this->img + other.imagin());
}


Complex& Complex::operator+=(const Complex& other){
    this->rea += other.real();
    this->img += other.imagin();
    return *this;
}


Complex& Complex::operator-=(const Complex& other){
    this->rea -= other.real();
    this->img -= other.imagin();
    return *this;
}
    
// (a+bi)*(c+di) = 
// (ac-bd) + (ad+bc)i
Complex& Complex::operator*=(const Complex& other) {
    double new_re = rea * other.real() - img * other.imagin();
    double new_im = rea * other.imagin() + img * other.real();
    rea = new_re;  // Update real part
    img = new_im;  // Update imaginary part
    return *this;
}

Complex Complex::operator++(){
    this->rea++;
    return *this;
}

Complex Complex::operator++(int){
    Complex copy = *this;
    rea++;
    return copy;
}


Complex operator-(const Complex& c1, const Complex& c2) {
    return Complex(c1.real() - c2.real(), c1.imagin() - c2.imagin());
}


Complex operator*(const Complex& c1, const Complex& c2) {
    return Complex (c1.real() * c2.real() - c1.imagin() * c2.imagin(),
                    c1.real() * c2.imagin() + c1.imagin() * c2.real());
}


bool operator==(const Complex& c1, const Complex& c2) {
    return c1.real()==c2.real() && c1.imagin() == c2.imagin();
}

// return ( (c1._re!=c2._re) || (c1._im!=c2._im) );
bool operator!=(const Complex& c1, const Complex& c2) {
    return (!(c1==c2));
}


