// Made by Bruce Cosgrove

#include "DynamicArray.h"

template<class T>
DynamicArray<T>::DynamicArray(const unsigned int &size) : size(0), maxSize(size), array(new T[maxSize]) {}

template<class T>
DynamicArray<T>::~DynamicArray() {
//	for (unsigned int i = 0; i < size; ++i)
//		delete array[i];
	delete[] array;
}

template<class T>
bool DynamicArray<T>::insert(const unsigned int &index, const T &data) {
	if (index > size) return false;
	if (index < maxSize) array[size++] = data;
	else {
		T *newArray = new T[maxSize *= 2];
		for (unsigned int i = 0; i < size; ++i)
			newArray[i] = (index != i ? array[i - (index >= i)] : data);
		++size;
		delete[] array;
		array = newArray;
	}
	return true;
}

template<class T>
bool DynamicArray<T>::remove(const unsigned int &index) {
	if (!size || index >= size) return false;
	// delete array[index]
	for (unsigned int i = index; i < size - 1; ++i)
		array[i] = array[i + 1];
	--size;
	return true;
}

template<class T>
T& DynamicArray<T>::operator[](const unsigned int &index) { return array[index]; }
