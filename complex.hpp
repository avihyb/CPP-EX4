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
        double img;
    public:
        Complex(double r, double i) : real(r), img(i) {}
        double get_real() const { return real; }
        double get_imag() const { return img; }
        double magnitude() const { return sqrt(real * real + img * img); }
        
        Complex operator+(const Complex &c) const {
            return Complex(real + c.real, img + c.img);
        }
        Complex operator-(const Complex &c) const {
            return Complex(real - c.real, img - c.img);
        }
        Complex operator*(const Complex &c) const {
            return Complex(real * c.real - img * c.img, real * c.img + img * c.real);
        }
        Complex operator/(const Complex &c) const {
            double denominator = c.real * c.real + c.img * c.img;
            return Complex((real * c.real + img * c.img) / denominator, (img * c.real - real * c.img) / denominator);
        }
        
        friend std::ostream &operator<<(std::ostream &os, const Complex &c) {
            os << c.real << "+" << c.img << "i";
            return os;
        }
        friend std::istream &operator>>(std::istream &is, Complex &c) {
            is >> c.real >> c.img;
            return is;
        }

        bool operator==(const Complex &c) const {
            return real == c.real && img == c.img;
        }
        bool operator!=(const Complex &c) const {
            return !(*this == c);
        }
        
        Complex operator-() const {
            return Complex(-real, -img);
        }
        Complex operator+=(const Complex &c) {
            real += c.real;
            img += c.img;
            return *this;
        }
        Complex operator-=(const Complex &c) {
            real -= c.real;
            img -= c.img;
            return *this;
        }
        Complex operator*=(const Complex &c) {
            double temp = real;
            real = real * c.real - img * c.img;
            img = temp * c.img + img * c.real;
            return *this;
        }
        Complex operator/=(const Complex &c) {
            double denominator = c.real * c.real + c.img * c.img;
            double temp = real;
            real = (real * c.real + img * c.img) / denominator;
            img = (img * c.real - temp * c.img) / denominator;
            return *this;
        }

        bool operator<(const Complex &c) const {
            return magnitude() < c.magnitude();
        }

        bool operator<=(const Complex &c) const {
            return magnitude() <= c.magnitude();
        }

        bool operator>(const Complex &c) const {
            return magnitude() > c.magnitude();
        }

        bool operator>=(const Complex &c) const {
            return magnitude() >= c.magnitude();
        }
};

#endif
