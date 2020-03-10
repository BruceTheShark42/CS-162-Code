// Made by Bruce Cosgrove

#include "Vec4.h"
#include <cmath>
#include <iostream>

// Constructors
template<class T> Vec4<T>::Vec4() : x(0), y(0), z(0), w(0) {}
template<class T> Vec4<T>::Vec4(T x, T y, T z, T w) : x(x), y(y), z(z), w(w) {}
template<class T> Vec4<T>::Vec4(const Vec4 &v) : x(v.x), y(v.y), z(v.z), w(v.w) {}

// Addition
template<class T> Vec4<T>& Vec4<T>::add(T x, T y, T z, T w) { this->x += x; this->y += y; this->z += z; this->w += w; return *this; }
template<class T> Vec4<T>& Vec4<T>::add(const Vec4 &v) { return add(v.x, v.y, v.z, v.w); }
template<class T> Vec4<T>  Vec4<T>::operator+(const Vec4 &v) { return Vec4(x + v.x, y + v.y, z + v.z, w + v.w); }
template<class T> Vec4<T>& Vec4<T>::operator+=(const Vec4 &v) { return add(v.x, v.y, v.z, v.w); }

// Subtraction
template<class T> Vec4<T>& Vec4<T>::sub(T x, T y, T z, T w) { this->x -= x; this->y -= y; this->z -= z; this->w -= w; return *this; }
template<class T> Vec4<T>& Vec4<T>::sub(const Vec4 &v) { return sub(v.x, v.y, v.z, v.w); }
template<class T> Vec4<T>  Vec4<T>::operator-(const Vec4 &v) { return Vec4(x - v.x, y - v.y, z - v.z, w - v.w); }
template<class T> Vec4<T>& Vec4<T>::operator-=(const Vec4 &v) { return sub(v.x, v.y, v.z, v.w); }

// Multiplication
template<class T> Vec4<T>& Vec4<T>::mul(T x, T y, T z, T w) { this->x *= x; this->y *= y; this->z *= z; this->w *= w; return *this; }
template<class T> Vec4<T>& Vec4<T>::mul(const Vec4 &v) { return mul(v.x, v.y, v.z, v.w); }
template<class T> Vec4<T>& Vec4<T>::mul(T k) { return mul(k, k, k, k); }
template<class T> Vec4<T>  Vec4<T>::operator*(const Vec4 &v) { return Vec4(x * v.x, y * v.y, z * v.z, w * v.w); }
template<class T> Vec4<T>& Vec4<T>::operator*=(const Vec4 &v) { return mul(v.x, v.y, v.z, v.w); }
template<class T> Vec4<T>  Vec4<T>::operator*(T k) { return Vec4(x * k, y * k, z * k, w * k); }
template<class T> Vec4<T>& Vec4<T>::operator*=(T k) { return mul(k, k, k, k); }

// Division
template<class T> Vec4<T>& Vec4<T>::div(T x, T y, T z, T w) { this->x /= x; this->y /= y; this->z /= z; this->w /= w; return *this; }
template<class T> Vec4<T>& Vec4<T>::div(const Vec4 &v) { return div(v.x, v.y, v.z, v.w); }
template<class T> Vec4<T>& Vec4<T>::div(T k) { return div(k, k, k, k); }
template<class T> Vec4<T>  Vec4<T>::operator/(const Vec4 &v) { return Vec4(x / v.x, y / v.y, z / v.z, w / v.w); }
template<class T> Vec4<T>& Vec4<T>::operator/=(const Vec4 &v) { return div(v.x, v.y, v.z, v.w); }
template<class T> Vec4<T>  Vec4<T>::operator/(T k) { return Vec4(x / k, y / k, z / k, w / k); }
template<class T> Vec4<T>& Vec4<T>::operator/=(T k) { return div(k, k, k, k); }

// Dot Product
template<class T> T Vec4<T>::dot(T x, T y, T z, T w) { return this->x * x + this->y * y + this->z * z + this->w * w; }
template<class T> T Vec4<T>::dot(const Vec4 &v) { return dot(v.x, v.y, v.z, v.w); }

// Cross Product
template<class T> Vec4<T> Vec4<T>::cpd(T x1, T y1, T z1, T w1, T x2, T y2, T z2, T w2) {
	return Vec4(
		(
			 y * (z1 * w2 - w1 * z2)
			-z * (w1 * y2 - y1 * w2)
			+w * (y1 * z2 - z1 * y2)
		),
		-(
			 x * (z1 * w2 - w1 * z2)
			-z * (w1 * x2 - x1 * w2)
			+w * (x1 * z1 - z2 * x2)
		),
		(
			 x * (y1 * w2 - w1 * y2)
			-y * (w1 * x2 - x1 * w2)
			+w * (x1 * y2 - y1 * x2)
		),
		-(
			 x * (y1 * z2 - z1 * y2)
			-y * (z1 * x2 - x1 * z2)
			+z * (x1 * y2 - y1 * x2)
		)
	);
}
template<class T> Vec4<T> Vec4<T>::cpd(const Vec4 &v1, const Vec4 &v2) { return cpd(v1.x, v1.y, v1.z, v1.w, v2.x, v2.y, v2.z, v2.w); }

// Magnitude
template<class T> T Vec4<T>::mag() { return std::sqrt(dot(x, y, z, w)); }

// Normalize
template<class T> Vec4<T>& Vec4<T>::nml() { return div(mag()); }

// Print
template<class T> void Vec4<T>::print() { std::cout << '(' << x << ", " << y << ", " << z << ", " << w << ")\n"; }
