// Made by Bruce Cosgrove

#ifndef COMPLEX_H
#define COMPLEX_H
template<class T>
class Complex {
public:
	Complex();
	Complex(const T real, const T imag);
	Complex operator+(const Complex &cplx);
	Complex& operator+=(const Complex &cplx);
	Complex operator-(const Complex &cplx);
	Complex& operator-=(const Complex &cplx);
	Complex operator*(const Complex &cplx);
	Complex& operator*=(const Complex &cplx);
	Complex operator/(const Complex &cplx);
	Complex& operator/=(const Complex &cplx);
	T getReal();
	T getImag();
	void setReal(const T real);
	void setImag(const T imag);
	void print() const;
private:
	T real, imag;
};
template class Complex<float>;
typedef Complex<float> Cplxf;
#endif
