#include <iostream>
#include <cassert>

#include "integer_vector.hpp"

void insertionSort(int * _pData, int _N);

int main()
{
	IntegerVector * v = new IntegerVector();
	IntegerVectorInit(*v);

	IntegerVectorReadTillZero(*v, std::cin);

	assert(!IntegerVectorIsEmpty(*v));
	insertionSort(v->m_pData, v->m_nUsed);

	IntegerVectorIsArith(*v);

	IntegerVectorDestroy(*v);
	return 0;
}

void insertionSort(int * _pData, int _N)
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

