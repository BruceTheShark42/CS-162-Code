// Made by Bruce Cosgrove

#include "Vector.h"

template<class T>
vec4<T>::vec4() : x((T)0), y((T)0), z((T)0), w((T)0) {}

template<class T>
vec4<T>::vec4(const T &x, const T &y, const T &z, const T &w) : x(x), y(y), z(z), w(w) {}

template<class T>
vec4<T> vec4<T>::operator + (const vec4<T> &v) {
	return vec4(x + v.x, y + v.y, z + v.z, w + v.w);
}

template<class T>
vec4<T> vec4<T>::operator - (const vec4<T> &v) {
	return vec4(x - v.x, y - v.y, z - v.z, w - v.w);
}

template<class T>
vec4<T> vec4<T>::operator + (const T &k) {
	return vec4(x + k, y + k, z + k, w + k);
}

template<class T>
vec4<T> vec4<T>::operator - (const T &k) {
	return vec4(x - k, y - k, z - k, w - k);
}

template<class T>
vec4<T> vec4<T>::operator * (const T &k) {
	return vec4(x * k, y * k, z * k, w * k);
}

template<class T>
vec4<T> vec4<T>::operator / (const T &k) {
	return vec4(x / k, y / k, z / k, w / k);
}

template<class T>
vec4<T> vec4<T>::operator += (const vec4<T> &v) {
	return vec4(x += v.x, y += v.y, z += v.z, w += v.w);
}

template<class T>
vec4<T> vec4<T>::operator -= (const vec4<T> &v) {
	return vec4(x -= v.x, y -= v.y, z -= v.z, w -= v.w);
}

template<class T>
vec4<T> vec4<T>::operator += (const T &k) {
	return vec4(x += k, y += k, z += k, w += k);
}

template<class T>
vec4<T> vec4<T>::operator -= (const T &k) {
	return vec4(x -= k, y -= k, z -= k, w -= k);
}

template<class T>
vec4<T> vec4<T>::operator *= (const T &k) {
	return vec4(x *= k, y *= k, z *= k, w *= k);
}

template<class T>
vec4<T> vec4<T>::operator /= (const T &k) {
	return vec4(x /= k, y /= k, z /= k, w /= k);
}
//
//template<class T>
//std::ostream& operator << (std::ostream &ostr, const vec4<T> &v) {
//	return ostr << '(' << v.x << ',' << v.y << ',' << v.z << ',' << v.w << ')';
//}
