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
	static Mat add(const Mat &m1, const Mat &m2);
	
	// Subtraction
	Mat& sub(const Mat &m);
	Mat operator-(const Mat &m);
	Mat& operator-=(const Mat &m);
	static Mat sub(const Mat &m1, const Mat &m2);
	
	// Multiplication
	Mat& mul(const Mat &m);
	Mat operator*(const Mat &m);
	Mat& operator*=(const Mat &m);
	static Mat mul(const Mat &m1, const Mat &m2);
	Mat& mul(T k);
	Mat operator*(T k);
	Mat& operator*=(T k);
	static Mat mul(const Mat &m, T k);
	
	// Operations
	static Mat transpose(const Mat &m);
	static Mat cofactors(const Mat &m);
	static Mat minor(const Mat &m, unsigned int rows, unsigned int cols);
	static Mat minors(const Mat &m);
	static Mat adjugate(const Mat &m);
	static Mat inverse(const Mat &m);
	static Mat identity(unsigned int rows, unsigned int cols);
	static T determinant(const Mat &m);
	
	T& operator()(unsigned int row, unsigned int col);
	static void print(const Mat &m);
private:
	T *data;
	unsigned int rows, cols, size;
};

template class Mat<float>;
typedef Mat<float> Matf;

#endif
