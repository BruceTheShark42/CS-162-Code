// Made by Bruce Cosgrove

#ifndef VEC3_H
#define VEC3_H

template<class T>
struct Vec3 {
	// Constructors
	Vec3();
	Vec3(T x, T y, T z);
	Vec3(const Vec3 &v);
	
	// Addition
	Vec3& add(T x, T y, T z);
	Vec3& add(const Vec3 &v);
	Vec3  operator+(const Vec3 &v);
	Vec3& operator+=(const Vec3 &v);
	
	// Subtraction
	Vec3& sub(T x, T y, T z);
	Vec3& sub(const Vec3 &v);
	Vec3  operator-(const Vec3 &v);
	Vec3& operator-=(const Vec3 &v);
	
	// Multiplication
	Vec3& mul(T x, T y, T z);
	Vec3& mul(const Vec3 &v);
	Vec3& mul(T k);
	Vec3  operator*(const Vec3 &v);
	Vec3& operator*=(const Vec3 &v);
	Vec3  operator*(T k);
	Vec3& operator*=(T k);
	
	// Division
	Vec3& div(T x, T y, T z);
	Vec3& div(const Vec3 &v);
	Vec3& div(T k);
	Vec3  operator/(const Vec3 &v);
	Vec3& operator/=(const Vec3 &v);
	Vec3  operator/(T k);
	Vec3& operator/=(T k);
	
	// Dot Product
	T dot(T x, T y, T z);
	T dot(const Vec3 &v);
	
	// Cross Product
	Vec3 cpd(T x, T y, T z);
	Vec3 cpd(const Vec3 &v);
	
	// Magnitude
	T mag();
	
	// Normalize
	Vec3& nml();
	
	// Print
	void print();
	
	// Values
	T x, y, z;
};

template class Vec3<float>;
typedef Vec3<float> Vec3f;

#endif
