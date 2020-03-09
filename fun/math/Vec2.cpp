// Made by Bruce Cosgrove

#include "Vec2.h"
#include <cmath>
#include <iostream>

// Constructors
template<class T> Vec2<T>::Vec2() : x(0), y(0) {}
template<class T> Vec2<T>::Vec2(T x, T y) : x(x), y(y) {}
template<class T> Vec2<T>::Vec2(const Vec2 &v) : x(v.x), y(v.y) {}

// Addition
template<class T> Vec2<T>& Vec2<T>::add(T x, T y) { this->x += x; this->y += y; return *this; }
template<class T> Vec2<T>& Vec2<T>::add(const Vec2 &v) { x += v.x; y += v.y; return *this; }
template<class T> Vec2<T>  Vec2<T>::operator+(const Vec2 &v) { return Vec2(x + v.x, y + v.y); }
template<class T> Vec2<T>& Vec2<T>::operator+=(const Vec2 &v) { x += v.x; y += v.y; return *this; }

// Subtraction
template<class T> Vec2<T>& Vec2<T>::sub(T x, T y) { this->x -= x; this->y -= y; return *this; }
template<class T> Vec2<T>& Vec2<T>::sub(const Vec2 &v) { x -= v.x; y -= v.y; return *this; }
template<class T> Vec2<T>  Vec2<T>::operator-(const Vec2 &v) { return Vec2(x - v.x, y - v.y); }
template<class T> Vec2<T>& Vec2<T>::operator-=(const Vec2 &v) { x -= v.x; y -= v.y; return *this; }

// Multiplication
template<class T> Vec2<T>& Vec2<T>::mul(T x, T y) { this->x *= x; this->y *= y; return *this; }
template<class T> Vec2<T>& Vec2<T>::mul(const Vec2 &v) { x *= v.x; y *= v.y; return *this; }
template<class T> Vec2<T>& Vec2<T>::mul(T k) { x *= k; y *= k; return *this; }
template<class T> Vec2<T>  Vec2<T>::operator*(const Vec2 &v) { return Vec2(x * v.x, y * v.y); }
template<class T> Vec2<T>& Vec2<T>::operator*=(const Vec2 &v) { x *= v.x; y *= v.y; return *this; }
template<class T> Vec2<T>  Vec2<T>::operator*(T k) { return Vec2(x * k, y * k); }
template<class T> Vec2<T>& Vec2<T>::operator*=(T k) { x *= k; y *= k; return *this; }

// Division
template<class T> Vec2<T>& Vec2<T>::div(T x, T y) { this->x /= x; this->y /= y; return *this; }
template<class T> Vec2<T>& Vec2<T>::div(const Vec2 &v) { x /= v.x; y /= v.y; return *this; }
template<class T> Vec2<T>& Vec2<T>::div(T k) { x /= k; y /= k; return *this; }
template<class T> Vec2<T>  Vec2<T>::operator/(const Vec2 &v) { return Vec2(x / v.x, y / v.y); }
template<class T> Vec2<T>& Vec2<T>::operator/=(const Vec2 &v) { x /= v.x; y /= v.y; return *this; }
template<class T> Vec2<T>  Vec2<T>::operator/(T k) { return Vec2(x / k, y / k); }
template<class T> Vec2<T>& Vec2<T>::operator/=(T k) { x /= k; y /= k; return *this; }

// Dot Product
template<class T> T Vec2<T>::dot(T x, T y) { return this->x * x + this->y * y; }
template<class T> T Vec2<T>::dot(const Vec2 &v) { return x * v.x + y * v.y; }

// Magnitude
template<class T> T Vec2<T>::mag() { return std::sqrt(dot(x, y)); }

// Normalize
template<class T> Vec2<T>& Vec2<T>::nml() { return div(mag()); }

// Print
template<class T> void Vec2<T>::print() { std::cout << '(' << x << ", " << y << ")\n"; }
