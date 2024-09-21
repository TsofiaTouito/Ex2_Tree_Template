// tsofiatouito2@gmail.com

#include <iostream>
#include <string>
#include <sstream>

using namespace std;




class Complex{

    private:
    double rea, img;  //real for the real part, img for the imaginary aginery part

    public:
    Complex(const double& rea = 0.0,const double& img = 0.0) : rea(rea), img(img){};

    //Getters 
    double real() const;

    double imagin() const;

    //unary operators
    bool operator!() const;
    Complex operator-();

    //binary operators
    Complex operator+(const Complex&) const;
    Complex& operator+=(const Complex&);
    Complex& operator-=(const Complex&);
    
    Complex& operator*=(const Complex&);

    Complex operator++();
    Complex operator++(int);


    friend Complex operator-(const Complex&);
    friend Complex operator*(const Complex&);
    friend bool operator==(const Complex&, const Complex&);
    friend bool operator!=(const Complex&, const Complex&);

    // Friend function to convert Complex to string
    friend std::string to_string(const Complex& c) {
        std::ostringstream oss;
        if (c.img < 0) {
            oss << c.rea << " - " << -c.img << "i";
        } else {
            oss << c.rea << " + " << c.img << "i";
        }
        return oss.str();
    }

    // Overload ostream operator
    friend std::ostream& operator<<(std::ostream& stream, const Complex& c) {
        return stream << to_string(c);
    }

};
