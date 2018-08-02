#include "sort_algorithms.hpp"

#include <algorithm>
#include <memory.h>
#include <stdlib.h>
#include <iostream>

void bubbleSort(int* _pData, int _N)
{
	for (int i = 0; i < _N - 1; i++)
		for (int j = _N - 1; j > i; j--)
			if (_pData[j - 1] > _pData[j])
				std::swap(_pData[j], _pData[j - 1]);
}

void insertionSort(int* _pData, const int _N)
{
	for (int i = 1; i < _N; i++)
	{
		int j = i;
		while (j && (_pData[j] < _pData[j - 1]))
		{
			std::swap(_pData[j], _pData[j - 1]);
			--j;
		}
	}
}

void selectionSort(int* _pData, const int _N)
{
	for (int i = 0; i < _N - 1; i++)
	{
		int lowIndex = i;
		for (int j = i + 1; j < _N; j++)
		if (_pData[j] < _pData[lowIndex])
			lowIndex = j;

		std::swap(_pData[lowIndex], _pData[i]);
	}
}

void mergeSorted(const int * _pFirst, int _firstSize,
				 const int * _pSecond, int _secondSize,
				 int * _pTarget)
{
	int firstIndex = 0, secondIndex = 0, targetIndex = 0;
	while (firstIndex < _firstSize && secondIndex < _secondSize)
	{
		if (_pFirst[firstIndex] <= _pSecond[secondIndex])
		{
			_pTarget[targetIndex] = _pFirst[firstIndex];
			++firstIndex;
		}

		else
		{
			_pTarget[targetIndex] = _pSecond[secondIndex];
			++secondIndex;
		}

		++targetIndex;
	}

	if (firstIndex < _firstSize)
		memcpy(_pTarget + targetIndex,
		_pFirst + firstIndex,
		sizeof(int)* (_firstSize - firstIndex)
		);

	else if (secondIndex < _secondSize)
		memcpy(_pTarget + targetIndex,
		_pSecond + secondIndex,
		sizeof(int)* (_secondSize - secondIndex)
		);
}

void mergeSort(int * _pData, int _N, ElementarySorter _f)
{	
	if (_N < 10 && _f){
		_f(_pData, _N);
	}
	else if (_N > 1){
		int halfSize = _N / 2;
		int otherHalfSize = _N - halfSize;

		int * pFirstHalf = new int[halfSize];
		memcpy(pFirstHalf, _pData, sizeof(int)* halfSize);

		int * pSecondHalf = new int[otherHalfSize];
		memcpy(pSecondHalf, _pData + halfSize, sizeof(int)* otherHalfSize);

		mergeSort(pFirstHalf, halfSize, _f);
		mergeSort(pSecondHalf, otherHalfSize, _f);

		mergeSorted(pFirstHalf, halfSize, pSecondHalf, otherHalfSize, _pData);

		delete[] pFirstHalf;
		delete[] pSecondHalf;
	}
}