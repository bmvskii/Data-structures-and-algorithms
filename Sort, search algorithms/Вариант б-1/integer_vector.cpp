#include "integer_vector.hpp"

#include <cstring>
#include <iostream>
#include <cassert>


void IntegerVectorInit(IntegerVector & _vector, int _allocatedSize)
{
	_vector.m_pData = new IntegerVector::Cell[_allocatedSize];
	_vector.m_nAllocated = _allocatedSize;
	_vector.m_nUsed = 0;
}


void IntegerVectorDestroy(IntegerVector & _vector)
{
	delete[] _vector.m_pData;
}


void IntegerVectorClear(IntegerVector & _vector)
{
	_vector.m_nUsed = 0;
}


bool IntegerVectorIsEmpty(const IntegerVector & _vector)
{
	return _vector.m_nUsed == 0;
}


void IntegerVectorGrow(IntegerVector & _vector)
{
	int nAllocatedNew = _vector.m_nAllocated * 2;
	IntegerVector::Cell * pNewData = new IntegerVector::Cell[nAllocatedNew];

	memcpy(pNewData, _vector.m_pData, sizeof(IntegerVector::Cell)* _vector.m_nAllocated);

	delete[] _vector.m_pData;
	_vector.m_pData = pNewData;

	_vector.m_nAllocated = nAllocatedNew;
}


void IntegerVectorPushBack(IntegerVector & _vector, int _key, int _value)
{
	if (_vector.m_nUsed == _vector.m_nAllocated)
		IntegerVectorGrow(_vector);

	_vector.m_pData[_vector.m_nUsed].m_key = _key;
	_vector.m_pData[_vector.m_nUsed++].m_value = _value;
}

void IntegerVectorPopBack(IntegerVector & _vector)
{
	assert(!IntegerVectorIsEmpty(_vector));

	--_vector.m_nUsed;
}

void IntegerVectorInsertAt(IntegerVector & _vector, int _position, int _key, int _value)
{
	assert(_position >= 0 && _position < _vector.m_nUsed);

	int newUsed = _vector.m_nUsed + 1;
	if (newUsed > _vector.m_nAllocated)
		IntegerVectorGrow(_vector);

	for (int i = _vector.m_nUsed; i > _position; i--)
		_vector.m_pData[i] = _vector.m_pData[i - 1];

	_vector.m_pData[_position].m_key = _key;
	_vector.m_pData[_position].m_value = _value;

	_vector.m_nUsed = newUsed;
}


void IntegerVectorDeleteAt(IntegerVector & _vector, int _position)
{
	assert(_position >= 0 && _position < _vector.m_nUsed);

	for (int i = _position + 1; i < _vector.m_nUsed; i++)
		_vector.m_pData[i - 1] = _vector.m_pData[i];

	--_vector.m_nUsed;
}