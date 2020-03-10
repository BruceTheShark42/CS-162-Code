// Made by Bruce Cosgrove

#ifndef MAT_H
#define MAT_H

template<class T>
struct Mat {
	Mat(unsigned int rows, unsigned int cols, bool identity = true);
	~Mat();
	
	// Addition
	Mat& add(const Mat &m);
	Mat operator+(const Mat &m);
	Mat& operator+=(const Mat &m);
	
	// Subtraction
	Mat& sub(const Mat &m);
	Mat operator-(const Mat &m);
	Mat& operator-=(const Mat4&m);
	
	// Multiplication
	Mat& mul(const Mat &m);
	Mat operator*(const Mat &m);
	Mat& operator*=(const Mat &m);
	
	// Operations
	Mat& transpose();
	Mat& cofactors();
	Mat& adjugate();
	Mat& inverse();
	Mat& identity();
	T determinant();
	
	T& operator()(unsigned int row, unsigned int col);
private:
	T *data;
	unsigned int rows, cols, size;
};

template class Mat<float>;
typename Mat<float> Matf;

#endif
