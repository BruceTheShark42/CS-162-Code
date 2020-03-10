// Made by Bruce Cosgrove

#ifndef VEC4_H
#define VEC4_H

template<class T>
struct Vec4 {
	// Constructors
	Vec4();
	Vec4(T x, T y, T z, T w);
	Vec4(const Vec4 &v);
	
	// Addition
	Vec4& add(T x, T y, T z, T w);
	Vec4& add(const Vec4 &v);
	Vec4  operator+(const Vec4 &v);
	Vec4& operator+=(const Vec4 &v);
	
	// Subtraction
	Vec4& sub(T x, T y, T z, T w);
	Vec4& sub(const Vec4 &v);
	Vec4  operator-(const Vec4 &v);
	Vec4& operator-=(const Vec4 &v);
	
	// Multiplication
	Vec4& mul(T x, T y, T z, T w);
	Vec4& mul(const Vec4 &v);
	Vec4& mul(T k);
	Vec4  operator*(const Vec4 &v);
	Vec4& operator*=(const Vec4 &v);
	Vec4  operator*(T k);
	Vec4& operator*=(T k);
	
	// Division
	Vec4& div(T x, T y, T z, T w);
	Vec4& div(const Vec4 &v);
	Vec4& div(T k);
	Vec4  operator/(const Vec4 &v);
	Vec4& operator/=(const Vec4 &v);
	Vec4  operator/(T k);
	Vec4& operator/=(T k);
	
	// Dot Product
	T dot(T x, T y, T z, T w);
	T dot(const Vec4 &v);
	
	// Cross Product
	Vec4 cpd(T x1, T y1, T z1, T w1, T x2, T y2, T z2, T w2);
	Vec4 cpd(const Vec4 &v1, const Vec4 &v2);
	
	// Magnitude
	T mag();
	
	// Normalize
	Vec4& nml();
	
	// Print
	void print();
	
	// Values
	T x, y, z, w;
};

template class Vec4<float>;
typedef Vec4<float> Vec4f;

#endif
