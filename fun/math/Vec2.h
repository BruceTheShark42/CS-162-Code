// Made by Bruce Cosgrove

#ifndef VEC2_H
#define VEC2_H

template<class T>
struct Vec2 {
	// Constructors
	Vec2();
	Vec2(T x, T y);
	Vec2(const Vec2 &v);
	
	// Addition
	Vec2& add(T x, T y);
	Vec2& add(const Vec2 &v);
	Vec2  operator+(const Vec2 &v);
	Vec2& operator+=(const Vec2 &v);
	
	// Subtraction
	Vec2& sub(T x, T y);
	Vec2& sub(const Vec2 &v);
	Vec2  operator-(const Vec2 &v);
	Vec2& operator-=(const Vec2 &v);
	
	// Multiplication
	Vec2& mul(T x, T y);
	Vec2& mul(const Vec2 &v);
	Vec2& mul(T k);
	Vec2  operator*(const Vec2 &v);
	Vec2& operator*=(const Vec2 &v);
	Vec2  operator*(T k);
	Vec2& operator*=(T k);
	
	// Division
	Vec2& div(T x, T y);
	Vec2& div(const Vec2 &v);
	Vec2& div(T k);
	Vec2  operator/(const Vec2 &v);
	Vec2& operator/=(const Vec2 &v);
	Vec2  operator/(T k);
	Vec2& operator/=(T k);
	
	// Dot Product
	T dot(T x, T y);
	T dot(const Vec2 &v);
	
	// Cross Product
	Vec2 cpd();
	
	// Magnitude
	T mag();
	
	// Normalize
	Vec2& nml();
	
	// Print
	void print();
	
	// Values
	T x, y;
};

template class Vec2<float>;
typedef Vec2<float> Vec2f;

#endif
