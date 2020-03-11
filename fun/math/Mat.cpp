// Made by Bruce Cosgrove

#include "Mat.h"
#include <iostream>
#include <cassert>
#undef minor // hmph

template<class T> Mat<T>::Mat(unsigned int rows, unsigned int cols, bool identity) : rows(rows), cols(cols), size(rows * cols) {
	data = new T[size];
	for (unsigned int i = 0; i < size; ++i) {
		if (identity && i / cols == i % cols)
			data[i] = 1;
		else data[i] = 0;
	}
}
template<class T> Mat<T>::~Mat() { delete[] data; }

// Addition
template<class T> Mat<T>& Mat<T>::add(const Mat &m) {
	assert(rows == m.rows && cols == m.cols);
	for (unsigned int i = 0; i < size; ++i)
		data[i] += m.data[i];
	return *this;
}
template<class T> Mat<T> Mat<T>::operator+(const Mat &m) {
	return add(*this, m);
}
template<class T> Mat<T>& Mat<T>::operator+=(const Mat &m) { return add(m); }
template<class T> Mat<T> Mat<T>::add(const Mat &m1, const Mat &m2) {
	assert(m1.rows == m2.rows && m1.cols == m2.cols);
	Mat result(m1.rows, m1.cols, false);
	for (unsigned int i = 0; i < m1.size; ++i)
		result.data[i] = m1.data[i] + m2.data[i];
	return result;
}

// Subtraction
template<class T> Mat<T>& Mat<T>::sub(const Mat &m) {
	assert(rows == m.rows && cols == m.cols);
	for (unsigned int i = 0; i < size; ++i)
		data[i] -= m.data[i];
	return *this;
}
template<class T> Mat<T> Mat<T>::operator-(const Mat &m) { return sub(*this, m); }
template<class T> Mat<T>& Mat<T>::operator-=(const Mat &m) { return sub(m); }
template<class T> Mat<T> Mat<T>::sub(const Mat &m1, const Mat &m2) {
	assert(m1.rows == m2.rows && m1.cols == m2.cols);
	Mat result(m1.rows, m1.cols, false);
	for (unsigned int i = 0; i < m1.size; ++i)
		result.data[i] = m1.data[i] - m2.data[i];
	return result;
}

// Multiplication
template<class T> Mat<T>& Mat<T>::mul(const Mat &m) {
	assert(rows == m.cols && cols == m.rows);
	Mat result = mul(*this, m);
	for (unsigned int i = 0; i < size; ++i)
		data[i] = result.data[i];
	return *this;
}
template<class T> Mat<T> Mat<T>::operator*(const Mat &m) { return mul(*this, m); }
template<class T> Mat<T>& Mat<T>::operator*=(const Mat &m) { return mul(m); }
template<class T> Mat<T> Mat<T>::mul(const Mat &m1, const Mat &m2) {
	assert(m1.rows == m2.cols && m1.cols == m2.rows);
	Mat result(m1.cols, m2.rows, false);
	for (unsigned int i = 0; i < m1.size; ++i) {
		T sum = 0;
		for (unsigned int k = 0; k < m1.rows; ++k)
			sum += m1.data[(i / m1.cols) * m1.cols + k] * m2.data[k * m1.cols + (i % m1.cols)];
		result.data[i] = sum;
	}
	return result;
}
template<class T> Mat<T>& Mat<T>::mul(T k) {
	for (unsigned int i = 0; i < size; ++i)
		data[i] *= k;
	return *this;
}
template<class T> Mat<T> Mat<T>::operator*(T k) { return mul(*this, k); }
template<class T> Mat<T>& Mat<T>::operator*=(T k) { return mul(k); }
template<class T> Mat<T> Mat<T>::mul(const Mat &m, T k) {
	Mat result(m.cols, m.rows, false);
	for (unsigned int i = 0; i < m.size; ++i)
		result.data[i] = m.data[i] * k;
	return result;
}

// Operations
template<class T> Mat<T> Mat<T>::transpose(const Mat &m) {
	Mat result(m.cols, m.rows, false);
	for (unsigned int i = 0; i < m.size; ++i)
		result.data[(i % m.cols) * m.rows + i / m.cols] = m.data[i];
	return result;
}
template<class T> Mat<T> Mat<T>::cofactors(const Mat &m) {
	Mat result(m.rows, m.cols, false);
	for (unsigned int i = 0; i < m.size; ++i)
		result.data[i] = m.data[i] * ((i + (m.cols % 2 == 0 ? i / m.cols : 0)) % 2 != 0 ? -1 : 1);
	return result;
}
template<class T> Mat<T> Mat<T>::minor(const Mat &m, unsigned int row, unsigned int col) {
	assert(m.rows > 1 && m.cols > 1);
	Mat result(m.rows - 1, m.cols - 1);
	for (unsigned int i = 0; i < result.size; ++i)
		result.data[i] = m.data[(i / result.cols + (i / result.cols >= row)) * m.cols + (i % result.cols + (i % result.cols >= col))];
	return result;
}
template<class T> Mat<T> Mat<T>::minors(const Mat &m) {
	Mat result(m.rows, m.cols);
	for (unsigned int i = 0; i < m.size; ++i)
		result.data[i] = determinant(minor(m, i / m.cols, i % m.cols));
	return result;
}
template<class T> Mat<T> Mat<T>::adjugate(const Mat &m) { return transpose(cofactors(m)); }
template<class T> Mat<T> Mat<T>::inverse(const Mat &m) { return mul(adjugate(minors(m)), 1 / determinant(m)); }
template<class T> Mat<T> Mat<T>::identity(unsigned int rows, unsigned int cols) { return Mat(rows, cols); }
template<class T> T Mat<T>::determinant(const Mat &m) {
	assert(m.cols == m.rows);
	if (m.cols == 2)
		return m.data[0] * m.data[3] - m.data[1] * m.data[2];
	T det = 0;
	for (unsigned int i = 0; i < m.cols; ++i)
		det += (i % 2 == 0 ? 1 : -1) * m.data[i] * determinant(minor(m, 0, i));
	return det;
}

template<class T> T& Mat<T>::operator()(unsigned int row, unsigned int col) { return data[row * cols + col]; }
template<class T> void Mat<T>::print(const Mat &m) {
	std::cout << '[';
	for (unsigned int i = 0; i < m.size; ++i) {
		if (i % m.cols == 0) {
			if (i != 0)
				std::cout << "]\n ";
			if (i < m.size - 1)
				std::cout << '[';
		}
		std::cout << m.data[i];
		if ((i % m.cols) + 1 < m.cols)
			std::cout << ' ';
	}
	std::cout << "]]\n";
}
