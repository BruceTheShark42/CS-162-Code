// Made by Bruce Cosgrove

#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>

template<class T>
class vec4 {
public:
	vec4();
	vec4(const T &x, const T &y, const T &z, const T &w);
public:
	vec4 operator + (const vec4 &v);
	vec4 operator - (const vec4 &v);
	vec4 operator + (const T &k);
	vec4 operator - (const T &k);
	vec4 operator * (const T &k);
	vec4 operator / (const T &k);
	vec4 operator += (const vec4 &v);
	vec4 operator -= (const vec4 &v);
	vec4 operator += (const T &k);
	vec4 operator -= (const T &k);
	vec4 operator *= (const T &k);
	vec4 operator /= (const T &k);
	friend std::ostream& operator << (std::ostream &ostr, const vec4 &v) {
		 return ostr << '(' << v.x << ',' << v.y << ',' << v.z << ',' << v.w << ')';
	}
public:
	T x, y, z, w;
};

template class vec4<float>;
template class vec4<double>;
template class vec4<char>;
template class vec4<short>;
template class vec4<int>;
template class vec4<long>;
template class vec4<unsigned char>;
template class vec4<unsigned short>;
template class vec4<unsigned int>;
template class vec4<unsigned long>;

typedef vec4<float> vec4f;
typedef vec4<double> vec4d;
typedef vec4<char> vec4c;
typedef vec4<short> vec4s;
typedef vec4<int> vec4i;
typedef vec4<long> vec4l;
typedef vec4<unsigned char> vec4uc;
typedef vec4<unsigned short> vec4us;
typedef vec4<unsigned int> vec4ui;
typedef vec4<unsigned long> vec4ul;

#endif
