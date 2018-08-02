#ifndef _VECTOR_HPP_
#define _VECTOR_HPP_

#include <iostream>
#include <cstring>

template<typename T>
struct Vector
{
	T * m_pData;
	int m_nUsed;
	int m_nAllocated;
};

template <typename T>
void VectorInit(Vector<T> & _vector, int _allocatedSize = 10)
{
	_vector.m_pData = new T[_allocatedSize];
	_vector.m_nAllocated = _allocatedSize;
	_vector.m_nUsed = 0;
}

template <typename T>
void VectorDestroy(Vector<T> & _vector)
{
	delete[] _vector.m_pData;
}

template <typename T>
void VectorGrow(Vector<T> & _vector)
{
	int nAllocatedNew = _vector.m_nAllocated * 2;
	T * pNewData = new T[nAllocatedNew];

	memcpy(pNewData, _vector.m_pData, sizeof(T)* _vector.m_nAllocated);

	delete[] _vector.m_pData;
	_vector.m_pData = pNewData;

	_vector.m_nAllocated = nAllocatedNew;
}

template <typename T>
void VectorInsertAt(Vector<T> & _vector, int _position, T _data)
{
	if (_vector.m_nUsed == _vector.m_nAllocated)
		VectorGrow(_vector);

	int newUsed = _vector.m_nUsed + 1;

	for (int i = _vector.m_nUsed; i > _position; i--)
		_vector.m_pData[i] = _vector.m_pData[i - 1];

	_vector.m_pData[_position] = _data;
	_vector.m_nUsed = newUsed;
}

template <typename T>
void VectorSortPushBack(Vector<T> & _vector, T _data, int & _pos)
{
	for (int i = 0; i < _vector.m_nUsed; i++)
		if (_vector.m_pData[i] > _data) {
			_pos = i; 
			break; 
		}
	VectorInsertAt(_vector, _pos, _data);
}

#endif //  _VECTOR_HPP_