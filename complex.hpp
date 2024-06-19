#ifndef COMPLEX_HPP
#define COMPLEX_HPP

#include <iostream>
#include <cmath>
/*
    Complex class that represents a complex number.
    To be used in the tree class.
*/
class Complex{
    private:
        double real;
        double imag;
    public:
        Complex(double r, double i) : real(r), imag(i) {}
        double get_real() const { return real; }
        double get_imag() const { return imag; }
        double magnitude() const { return sqrt(real * real + imag * imag); }
        Complex operator+(const Complex &c) const {
            return Complex(real + c.real, imag + c.imag);
        }
        Complex operator-(const Complex &c) const {
            return Complex(real - c.real, imag - c.imag);
        }
        Complex operator*(const Complex &c) const {
            return Complex(real * c.real - imag * c.imag, real * c.imag + imag * c.real);
        }
        Complex operator/(const Complex &c) const {
            double denominator = c.real * c.real + c.imag * c.imag;
            return Complex((real * c.real + imag * c.imag) / denominator, (imag * c.real - real * c.imag) / denominator);
        }
        friend std::ostream &operator<<(std::ostream &os, const Complex &c) {
            os << c.real << "+" << c.imag << "i";
            return os;
        }
        friend std::istream &operator>>(std::istream &is, Complex &c) {
            is >> c.real >> c.imag;
            return is;
        }
        bool operator==(const Complex &c) const {
            return real == c.real && imag == c.imag;
        }
        bool operator!=(const Complex &c) const {
            return !(*this == c);
        }
        Complex operator-() const {
            return Complex(-real, -imag);
        }
        Complex operator+=(const Complex &c) {
            real += c.real;
            imag += c.imag;
            return *this;
        }
        Complex operator-=(const Complex &c) {
            real -= c.real;
            imag -= c.imag;
            return *this;
        }
        Complex operator*=(const Complex &c) {
            double temp = real;
            real = real * c.real - imag * c.imag;
            imag = temp * c.imag + imag * c.real;
            return *this;
        }
        Complex operator/=(const Complex &c) {
            double denominator = c.real * c.real + c.imag * c.imag;
            double temp = real;
            real = (real * c.real + imag * c.imag) / denominator;
            imag = (imag * c.real - temp * c.imag) / denominator;
            return *this;
        }
};

#endif