// Made by Bruce Cosgrove

#include "Mat.h"
#include <cassert>

template<class T> Mat<T>::Mat(unsigned int rows, unsigned int cols, bool identity) : rows(rows), cols(cols), size(rows * cols) {
	data = new T[size];
	for (unsigned int i = 0; i < size; ++i) {
		if (!identity && i / cols == i % cols)
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
	assert(rows == m.rows && cols == m.cols);
	Mat result(rows, cols, false);
	for (unsigned int i = 0; i < size; ++i)
		result.data[i] = data[i] + m.data[i];
	return result;

template<class T> Mat<T>& Mat<T>::operator+=(const Mat &m) { return add(m); }

// Subtraction
template<class T> Mat<T>& Mat<T>::sub(const Mat &m) {
	assert(rows == m.rows && cols == m.cols);
	for (unsigned int i = 0; i < size; ++i)
		data[i] -= m.data[i];
	return *this;
}
template<class T> Mat<T> Mat<T>::operator-(const Mat &m) {
	assert(rows == m.rows && cols == m.cols);
	Mat result(rows, cols, false);
	for (unsigned int i = 0; i < size; ++i)
		result.data[i] = data[i] - m.data[i];
	return result;
}
template<class T> Mat<T>& Mat<T>::operator-=(const Mat &m) { return sub(m); }

// Multiplication
template<class T> Mat<T>& Mat<T>::mul(const Mat &m) {
	assert(rows == m.cols && cols == m.rows);
	Mat result(cols, m.rows);
	for (unsigned int i = 0; i < result.size; ++i) {
		T sum = 0;
		for (unsigned int k = 0; k < result.rows; ++k)
			sum += data[(i / result.cols) * result.cols + k] * m.data[k * result.cols + (i % result.cols)];
		result.data[i] = sum;
	}
	for (unsigned int i = 0; i < size; ++i)
		data[i] = result[i];
	return *this;
}
template<class T> Mat<T> Mat<T>::operator*(const Mat &m) {
	assert(rows == m.cols && cols == m.rows);
	Mat result(cols, m.rows);
	for (unsigned int i = 0; i < result.size; ++i) {
		T sum = 0;
		for (unsigned int k = 0; k < result.rows; ++k)
			sum += data[(i / result.cols) * result.cols + k] * m.data[k * result.cols + (i % result.cols)];
		result.data[i] = sum;
	}
	return result;
}
template<class T> Mat<T>& Mat<T>::operator*=(const Mat &m) { return mul(m); }

// Operations
template<class T> Mat<T> Mat<T>::transpose() {
	Mat result(cols, rows);
	for (unsigned int i = 0; i < size; ++i)
		result.data[(i % cols) * rows + i / cols] = data[i];
	return result;
}
template<class T> Mat<T> Mat<T>::cofactors() {
	Mat result(rows, cols, false);
	for (unsigned int i = 0; i < size; ++i)
		result.data[i] = data[i] * ((i + (cols % 2 == 0 ? i / cols : 0)) % 2 != 0 ? -1 : 1);
	return result;
}
template<class T> Mat<T> Mat<T>::minor(unsigned int col, unsigned int row) {
	Mat result(rows - 1, cols - 1);
	for (unsigned int i = 0; i < size; ++i)
		result.data[i] = data[(i / cols + (i / cols < row ? 0 : 1)) * cols + (i % cols + (i % cols < col ? 0 : 1))];
	return result;
}
template<class T> Mat<T> Mat<T>::minors();
template<class T> Mat<T> Mat<T>::adjugate();
template<class T> Mat<T> Mat<T>::inverse();
template<class T> Mat<T> Mat<T>::identity() {
	return Mat(rows, cols);
}
template<class T> T Mat<T>::determinant();

template<class T> T& Mat<T>::operator()(unsigned int row, unsigned int col) { return data[row * cols + col]; }
