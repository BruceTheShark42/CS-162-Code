// Made by Bruce Cosgrove

#include "Vec3.h"
#include <cmath>
#include <iostream>

// Constructors
template<class T> Vec3<T>::Vec3() : x(0), y(0), z(0) {}
template<class T> Vec3<T>::Vec3(T x, T y, T z) : x(x), y(y), z(z) {}
template<class T> Vec3<T>::Vec3(const Vec3 &v) : x(v.x), y(v.y), z(v.z) {}

// Addition
template<class T> Vec3<T>& Vec3<T>::add(T x, T y, T z) { this->x += x; this->y += y; this->z += z; return *this; }
template<class T> Vec3<T>& Vec3<T>::add(const Vec3 &v) { x += v.x; y += v.y; z += v.z; return *this; }
template<class T> Vec3<T>  Vec3<T>::operator+(const Vec3 &v) { return Vec3(x + v.x, y + v.y, z + v.z); }
template<class T> Vec3<T>& Vec3<T>::operator+=(const Vec3 &v) { x += v.x; y += v.y; z += v.z; return *this; }

// Subtraction
template<class T> Vec3<T>& Vec3<T>::sub(T x, T y, T z) { this->x -= x; this->y -= y; this->z -= z; return *this; }
template<class T> Vec3<T>& Vec3<T>::sub(const Vec3 &v) { x -= v.x; y -= v.y; z -= v.z; return *this; }
template<class T> Vec3<T>  Vec3<T>::operator-(const Vec3 &v) { return Vec3(x - v.x, y - v.y, z - v.z); }
template<class T> Vec3<T>& Vec3<T>::operator-=(const Vec3 &v) { x -= v.x; y -= v.y; z -= v.z; return *this; }

// Multiplication
template<class T> Vec3<T>& Vec3<T>::mul(T x, T y, T z) { this->x *= x; this->y *= y; this->z *= z; return *this; }
template<class T> Vec3<T>& Vec3<T>::mul(const Vec3 &v) { x *= v.x; y *= v.y; z *= v.z; return *this; }
template<class T> Vec3<T>& Vec3<T>::mul(T k) { x *= k; y *= k; z *= k; return *this; }
template<class T> Vec3<T>  Vec3<T>::operator*(const Vec3 &v) { return Vec3(x * v.x, y * v.y, z * v.z); }
template<class T> Vec3<T>& Vec3<T>::operator*=(const Vec3 &v) { x *= v.x; y *= v.y; z *= v.z; return *this; }
template<class T> Vec3<T>  Vec3<T>::operator*(T k) { return Vec3(x * k, y * k, z * k); }
template<class T> Vec3<T>& Vec3<T>::operator*=(T k) { x *= k; y *= k; z *= k; return *this; }

// Division
template<class T> Vec3<T>& Vec3<T>::div(T x, T y, T z) { this->x /= x; this->y /= y; this->z /= z; return *this; }
template<class T> Vec3<T>& Vec3<T>::div(const Vec3 &v) { x /= v.x; y /= v.y; z /= v.z; return *this; }
template<class T> Vec3<T>& Vec3<T>::div(T k) { x /= k; y /= k; z /= k; return *this; }
template<class T> Vec3<T>  Vec3<T>::operator/(const Vec3 &v) { return Vec3(x / v.x, y / v.y, z / v.z); }
template<class T> Vec3<T>& Vec3<T>::operator/=(const Vec3 &v) { x /= v.x; y /= v.y; z /= v.z; return *this; }
template<class T> Vec3<T>  Vec3<T>::operator/(T k) { return Vec3(x / k, y / k, z / k); }
template<class T> Vec3<T>& Vec3<T>::operator/=(T k) { x /= k; y /= k; z /= k; return *this; }

// Dot Product
template<class T> T Vec3<T>::dot(T x, T y, T z) { return this->x * x + this->y * y + this->z * z; }
template<class T> T Vec3<T>::dot(const Vec3 &v) { return x * v.x + y * v.y + z * v.z; }

// Cross Product
template<class T> Vec3<T> Vec3<T>::cpd(T x, T y, T z) { return Vec3(this->y * z - this->z * y, this->z * x - this->x * z, this->x * y - this->y * x); }
template<class T> Vec3<T> Vec3<T>::cpd(const Vec3 &v) { return Vec3(y * v.z - z * v.y, z * v.x - x *v. z, x * v.y - y * v.x); }

// Magnitude
template<class T> T Vec3<T>::mag() { return std::sqrt(dot(x, y, z)); }

// Normalize
template<class T> Vec3<T>& Vec3<T>::nml() { return div(mag()); }

// Print
template<class T> void Vec3<T>::print() { std::cout << '(' << x << ", " << y << ", " << z << ")\n"; }
