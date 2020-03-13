// Made by Bruce Cosgrove

#include "Complex.h"
#include <iostream>

template<class T> Complex<T>::Complex() : real(0), imag(0) {}
template<class T> Complex<T>::Complex(const T real, const T imag) : real(real), imag(imag) {}
template<class T> Complex<T> Complex<T>::operator+(const Complex &cplx) { return Complex(real + cplx.real, imag + cplx.imag); }
template<class T> Complex<T>& Complex<T>::operator+=(const Complex &cplx) { real += cplx.real; imag += cplx.imag; return *this; }
template<class T> Complex<T> Complex<T>::operator-(const Complex &cplx) { return Complex(real - cplx.real, imag - cplx.imag); }
template<class T> Complex<T>& Complex<T>::operator-=(const Complex &cplx) { real -= cplx.real; imag -= cplx.imag; return *this; }
template<class T> Complex<T> Complex<T>::operator*(const Complex &cplx) { return Complex(real * cplx.real - imag * cplx.imag, real * cplx.imag + imag * cplx.real); }
template<class T> Complex<T>& Complex<T>::operator*=(const Complex &cplx) { real *= cplx.real; imag *= cplx.imag; return *this; }
template<class T> Complex<T> Complex<T>::operator/(const Complex &cplx) { return Complex(real / cplx.real, imag / cplx.imag); }
template<class T> Complex<T>& Complex<T>::operator/=(const Complex &cplx) { real /= cplx.real; imag /= cplx.imag; return *this; }
template<class T> T Complex<T>::getReal() { return real; }
template<class T> T Complex<T>::getImag() { return imag; }
template<class T> void Complex<T>::setReal(const T real) { this->real = real; }
template<class T> void Complex<T>::setImag(const T imag) { this->imag = imag; }
template<class T> void Complex<T>::print() const { std::cout << real << " + " << imag << "i\n"; }
