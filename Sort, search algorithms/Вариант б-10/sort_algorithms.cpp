#define _CRT_SECURE_NO_WARNINGS

#include "sort_algorithms.hpp"

#include <algorithm>
#include <memory.h>
#include <stdlib.h>
#include <cstring>

void insertionSort(char** _pData, const int _N)
{
	for (int i = 1; i < _N; i++)
	{
		int j = i;
		while (j && ((_stricmp(_pData[j], _pData[j-1]) < 0)))
		{
			std::swap(_pData[j], _pData[j - 1]);
			--j;
		}
	}
}


void mergeSorted ( char ** _pFirst,  int _firstSize,
                   char ** _pSecond, int _secondSize,
                   char ** _pTarget )
{
    int firstIndex = 0, secondIndex = 0, targetIndex = 0;
    while ( firstIndex < _firstSize && secondIndex < _secondSize )
    {
        if (_stricmp( _pFirst[ firstIndex ] , _pSecond[ secondIndex ] ) <= 0 )
        {
			delete[]_pTarget[targetIndex];
			_pTarget[targetIndex] = new char[strlen(_pFirst[firstIndex]) + 1];
            strcpy(_pTarget[ targetIndex ], _pFirst[ firstIndex ]);
            ++ firstIndex;
        }

        else
        {
			delete[]_pTarget[targetIndex];
			_pTarget[targetIndex] = new char[strlen(_pSecond[secondIndex]) + 1];
            strcpy(_pTarget[ targetIndex ], _pSecond[ secondIndex ]);
			++ secondIndex;
        }

        ++ targetIndex;
    }

    if ( firstIndex < _firstSize )
        memcpy( _pTarget + targetIndex,
                _pFirst + firstIndex, 
                sizeof( char * ) * ( _firstSize - firstIndex ) 
        );

    else if ( secondIndex < _secondSize )
        memcpy( _pTarget + targetIndex,
                _pSecond + secondIndex, 
                sizeof( char * ) * ( _secondSize - secondIndex ) 
        );
}


void mergeSort ( char ** _pData, int _N )
{
    if ( _N < 10 )
        insertionSort( _pData, _N );

    else
    {
        int halfSize = _N / 2;
        int otherHalfSize = _N - halfSize;
		
        char ** pFirstHalf = new char*[ halfSize ];
		for (int i = 0; i < halfSize; i++)
		{
			pFirstHalf[i] = new char[strlen(_pData[i]) + 1];
			strcpy(pFirstHalf[i], _pData[i]);
		}
		
        char ** pSecondHalf = new char*[ otherHalfSize ];
		for (int i = halfSize, j = 0; i < otherHalfSize+halfSize; i++, j++)
		{
			pSecondHalf[j] = new char[strlen(_pData[i]) + 1];
			strcpy(pSecondHalf[j], _pData[i]);
		}

        mergeSort( pFirstHalf,  halfSize );
        mergeSort( pSecondHalf, otherHalfSize );

        mergeSorted( pFirstHalf, halfSize, pSecondHalf, otherHalfSize, _pData );

		delete[] pFirstHalf;
		delete[] pSecondHalf;
    }
}