#define _CRT_SECURE_NO_WARNINGS

#include "string_double_map.hpp"
#include "double_vector.hpp"
#include "string_vector.hpp"

#include <cassert>
#include <cstring>


struct String2DoubleMap
{
    StringVector m_keys;
    DoubleVector m_values;
};

String2DoubleMap * String2DoubleMapCreate ()
{
    String2DoubleMap * pMap = new String2DoubleMap;
    StringVectorInit( pMap->m_keys );
    DoubleVectorInit( pMap->m_values );
    return pMap;
}


void String2DoubleMapDestroy ( String2DoubleMap * _pMap )
{
    StringVectorDestroy( _pMap->m_keys );
    DoubleVectorDestroy( _pMap->m_values );
    delete _pMap;
}


void String2DoubleMapClear ( String2DoubleMap & _map )
{
    StringVectorClear( _map.m_keys );
    DoubleVectorClear( _map.m_values );
}


bool String2DoubleMapIsEmpty ( const String2DoubleMap & _map )
{
    return StringVectorIsEmpty( _map.m_keys );
}


int String2DoubleMapFindKeyPosition ( const String2DoubleMap & _map, const char * _key )
{
    for ( int i = 0; i < _map.m_keys.m_nUsed; i++ )
        if (!strcmp( _map.m_keys.m_pData[ i ],_key) )
            return i;

    return -1;
}


double String2DoubleMapGet ( const String2DoubleMap & _map, const char * _key )
{
    int keyPosition = String2DoubleMapFindKeyPosition( _map, _key );
	if ( keyPosition != -1 )
	    return _map.m_values.m_pData[ keyPosition ];
	else
	    return -1;
}

bool String2DoubleMapHasKey ( const String2DoubleMap & _map, const char * _key )
{
    return String2DoubleMapFindKeyPosition( _map, _key ) != -1;
}


void String2DoubleMapInsertKey ( String2DoubleMap & _map, const char * _key, double _value )
{
    int position = String2DoubleMapFindKeyPosition( _map, _key );
    if ( position == - 1 )
    {
        StringVectorPushBack( _map.m_keys, _key );
        DoubleVectorPushBack( _map.m_values, _value );
    }
    else
        _map.m_values.m_pData[ position ] = _value;
}



void String2DoubleMapRemoveKey ( String2DoubleMap & _map, const char * _key )
{
    int position = String2DoubleMapFindKeyPosition( _map, _key );
    assert( position != -1 );

    StringVectorDeleteAt( _map.m_keys, position );
    DoubleVectorDeleteAt( _map.m_values, position );
}