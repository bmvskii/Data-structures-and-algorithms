#include "date_vector.hpp"

#include <cstring>
#include <iostream>
#include <cassert>


void DateVectorInit ( DateVector & _vector, int _allocatedSize )
{
    _vector.m_pData      = new Date[ _allocatedSize ];
    _vector.m_nAllocated =  _allocatedSize;
    _vector.m_nUsed      = 0;
}


void DateVectorDestroy ( DateVector & _vector )
{
    delete[] _vector.m_pData;
}


void DateVectorClear ( DateVector & _vector )
{
    _vector.m_nUsed = 0;
}


bool DateVectorIsEmpty ( const DateVector & _vector )
{
    return _vector.m_nUsed == 0;
}


void DateVectorGrow ( DateVector & _vector )
{
    int nAllocatedNew = _vector.m_nAllocated * 2;
    Date * pNewData = new Date[ nAllocatedNew ];

    memcpy( pNewData, _vector.m_pData, sizeof(Date) * _vector.m_nAllocated );

    delete[] _vector.m_pData;
    _vector.m_pData = pNewData;

    _vector.m_nAllocated = nAllocatedNew;
}


void DateVectorPushBack ( DateVector & _vector, Date _data, int & _pos)
{
    if ( _vector.m_nUsed == _vector.m_nAllocated )
        DateVectorGrow( _vector );
	
	if (DateVectorIsEmpty(_vector))
		_vector.m_pData[_vector.m_nUsed++] = _data;
	else
	{
		for (int i = 0; i < _vector.m_nUsed; i++)
			if (_vector.m_pData[i].m_year > _data.m_year ||
				(_vector.m_pData[i].m_year == _data.m_year &&
					_vector.m_pData[i].m_month > _data.m_month) ||
					(_vector.m_pData[i].m_year == _data.m_year &&
						_vector.m_pData[i].m_month == _data.m_month &&
						_vector.m_pData[i].m_day > _data.m_day))
			{
				_pos = i;
				break;
			}

		DateVectorInsertAt(_vector, _pos, _data);
	}
}



void DateVectorPopBack ( DateVector & _vector )
{
    assert( ! DateVectorIsEmpty( _vector ) );

    -- _vector.m_nUsed;
}

void DateVectorInsertAt ( DateVector & _vector, int _position, Date _data )
{
    int newUsed = _vector.m_nUsed + 1;
    if ( newUsed > _vector.m_nAllocated )
        DateVectorGrow( _vector );

    for ( int i = _vector.m_nUsed; i > _position; i-- )
        _vector.m_pData[ i ] = _vector.m_pData[ i - 1];

    _vector.m_pData[ _position ] = _data;

    _vector.m_nUsed = newUsed;
}


void DateVectorDeleteAt ( DateVector & _vector, int _position )
{
    assert( _position >= 0 && _position < _vector.m_nUsed );

    for ( int i = _position + 1; i < _vector.m_nUsed; i++ )
        _vector.m_pData[ i - 1 ] = _vector.m_pData[ i ];

    -- _vector.m_nUsed;
}
