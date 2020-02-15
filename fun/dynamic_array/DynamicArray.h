// Made by Bruce Cosgrove

#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

#include <ostream>

template<class T>
class DynamicArray {
public:
	DynamicArray(const unsigned int &size = 1);
	~DynamicArray();
public:
	bool insert(const unsigned int &index, const T &data);
	bool remove(const unsigned int &index);
	T& operator[](const unsigned int &index);
	friend std::ostream& operator<<(std::ostream &ostr, DynamicArray &da) {
		ostr << "[ ";
		for (unsigned int i = 0; i < da.size; ++i)
			ostr << da.array[i] << ' ';
		return ostr << ']';
	}
private:
	unsigned int size, maxSize;
	T *array;
};

template class DynamicArray<float>;

#endif
