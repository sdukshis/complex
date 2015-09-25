#ifndef COMPLEX_H
#define COMPLEX_H

#include <math.h>

class Complex {
 public:
    Complex() = default;

    Complex(double real)
        : re_(real) {}

    Complex(double real, double imag)
        : re_(real)
        , im_(imag) {}

    Complex(const Complex &) = default;

    Complex(Complex &&) = default;

    Complex & operator=(const Complex &) = default;

    Complex & operator=(Complex &&) = default;

    double real() const { return re_; }

    double imag() const { return im_; }

    double modulo() const { return sqrt(re_*re_ + im_*im_); }

    double arg() const { return atan2(im_, re_); }

    friend Complex operator+(const Complex &lhs, const Complex &rhs) {
        return Complex(lhs.re_ + rhs.re_, lhs.im_ + rhs.im_);
    }

 private:
    double re_ = 0.0;
    double im_ = 0.0;
};

#endif