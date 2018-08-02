#include "integer_vector.hpp"

#include <cstring>
#include <iostream>
#include <cassert>


void IntegerVectorInit ( IntegerVector & _vector, int _allocatedSize )
{
    _vector.m_pData      = new int[ _allocatedSize ];
    _vector.m_nAllocated =  _allocatedSize;
    _vector.m_nUsed      = 0;
}


void IntegerVectorDestroy ( IntegerVector & _vector )
{
    delete[] _vector.m_pData;
}


void IntegerVectorClear ( IntegerVector & _vector )
{
    _vector.m_nUsed = 0;
}


bool IntegerVectorIsEmpty ( const IntegerVector & _vector )
{
    return _vector.m_nUsed == 0;
}


void IntegerVectorGrow ( IntegerVector & _vector )
{
    int nAllocatedNew = _vector.m_nAllocated * 2;
    int * pNewData = new int[ nAllocatedNew ];

    memcpy( pNewData, _vector.m_pData, sizeof( int ) * _vector.m_nAllocated );

    delete[] _vector.m_pData;
    _vector.m_pData = pNewData;

    _vector.m_nAllocated = nAllocatedNew;
}


void IntegerVectorPushBack ( IntegerVector & _vector, int _data )
{
    if ( _vector.m_nUsed == _vector.m_nAllocated )
        IntegerVectorGrow( _vector );

    _vector.m_pData[ _vector.m_nUsed++ ] = _data;
}



void IntegerVectorPopBack ( IntegerVector & _vector )
{
    assert( ! IntegerVectorIsEmpty( _vector ) );

    -- _vector.m_nUsed;
}


void IntegerVectorRead ( IntegerVector & _vector, std::istream & _stream )
{
    while ( true )
    {
        int temp;
        _stream >> temp;
        if ( _stream )
            IntegerVectorPushBack( _vector, temp );
        else
            break;
    }    
}


void IntegerVectorReadTillZero ( IntegerVector & _vector, std::istream & _stream )
{
    while ( true )
    {
        int temp;
        _stream >> temp;
        if ( _stream && temp > 0 )
            IntegerVectorPushBack( _vector, temp );
        else
            break;
    }
}


void IntegerVectorPrint ( const IntegerVector & _vector, std::ostream & _stream, char _sep )
{
    for ( int i = 0; i < _vector.m_nUsed; i++ )
        _stream << _vector.m_pData[ i ] << _sep;
}


void IntegerVectorInsertAt ( IntegerVector & _vector, int _position, int _data )
{
    assert( _position >= 0 && _position < _vector.m_nUsed );

    int newUsed = _vector.m_nUsed + 1;
    if ( newUsed > _vector.m_nAllocated )
        IntegerVectorGrow( _vector );

    for ( int i = _vector.m_nUsed; i > _position; i-- )
        _vector.m_pData[ i ] = _vector.m_pData[ i - 1];

    _vector.m_pData[ _position ] = _data;

    _vector.m_nUsed = newUsed;
}


void IntegerVectorDeleteAt ( IntegerVector & _vector, int _position )
{
    assert( _position >= 0 && _position < _vector.m_nUsed );

    for ( int i = _position + 1; i < _vector.m_nUsed; i++ )
        _vector.m_pData[ i - 1 ] = _vector.m_pData[ i ];

    -- _vector.m_nUsed;
}

void IntegerVectorPrintSequences(const IntegerVector & _vector, std::ostream & _stream)
{
	//текущая позиция
	int pos = 0;
	
	//счетчик наших упорядоченных чисел
	int k = 0;

	for (int i = 0; i < _vector.m_nUsed-1; i++)
	{
		//если текующее число, больше следующего
		if (_vector.m_pData[i] > _vector.m_pData[i + 1])
		{
			//если это первый заход, то запоминаем текущую позицию
			//и увеличиваем счетчик
			if (k == 0) pos = i;
			k++;
		}
		//в противном случае - обнуляем
		else
			k = 0;
		
		//если у нас уже есть 3 элемента, то
		if (k == 2)
		{
			//выводим их
			k++;
			for (int j = pos; j < pos + k; j++)
				_stream << _vector.m_pData[j] << std::ends;
				
			//изменяем текущую позицию
			pos += k;
			
			//ищем еще упорядоченные элементы
			for (int j = pos-1; j < _vector.m_nUsed-1; j++)
			{
				//если текущее больше следующего, то выводим его
				if (_vector.m_pData[j] > _vector.m_pData[j + 1])
					_stream << _vector.m_pData[j+1] << std::ends;
				//в противном случае: выводим последний элемент последовательности,
				//запоминаем нашу текущую позицию, присваиваем i значение j (текущая позиция)
				//и выходим из цикла
				else
				{
					_stream << std::endl;
					k = 0;
					pos = j;
					i = j;
					break;
				}
			}
		}
	}
}