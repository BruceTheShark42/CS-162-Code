// Made by Bruce Cosgrove

#include "Vector.h"

template<class T>
	// Constructors
	Vec2();
	Vec2(T &x, T &y);
	
	// Addition
	Vec2& add(T &x, T &y);
	Vec2& add(Vec2 &v);
	Vec2& operator+(Vec2 &v);
	Vec2& operator+=(Vec2 &v);
	
	// Subtraction
	Vec2& sub(T &x, T &y);
	Vec2& sub(Vec2 &v);
	Vec2  operator-(Vec2 &v);
	Vec2& operator-=(Vec2 &v);
	
	// Multiplication
	Vec2& mul(T &x, T &y);
	Vec2& mul(Vec2 &v);
	Vec2  operator*(Vec2 &v);
	Vec2& operator*=(Vec2 &v);
	Vec2  operator*(T &k);
	Vec2& operator*=(T &k);
	
	// Division
	Vec2& div(T &x, T &y);
	Vec2& div(Vec2 &v);
	Vec2  operator/(Vec2 &v);
	Vec2& operator/=(Vec2 &v);
	Vec2  operator/(T &k);
	Vec2& operator/=(T &k);
	
	// Dot Product
	T dot(T &x, T &y);
	T dot(Vec2 &v);
	
	// Magnitude
	T mag();
	
	// Normalize
	Vec2& nml();
	
	// Distance
	T dst(T &x, T &y);
	T dst(Vec2 &v);
