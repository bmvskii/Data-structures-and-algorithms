#define _CRT_SECURE_NO_WARNINGS

#include "map.hpp"
#include "integer_vector.hpp"
#include "string_vector.hpp"

#include <cassert>
#include <cstring>


struct Map
{
    StringVector m_values;
    IntegerVector m_keys;
};

Map * MapCreate ()
{
    Map * pMap = new Map;
    StringVectorInit( pMap->m_values );
    IntegerVectorInit( pMap->m_keys );
    return pMap;
}


void MapDestroy ( Map * _pMap )
{
    StringVectorDestroy( _pMap->m_values );
    IntegerVectorDestroy( _pMap->m_keys );
    delete _pMap;
}


void MapClear ( Map & _map )
{
    StringVectorClear( _map.m_values );
    IntegerVectorClear( _map.m_keys );
}


bool MapIsEmpty ( const Map & _map )
{
    return IntegerVectorIsEmpty( _map.m_keys );
}


int MapFindKeyPosition ( const Map & _map, int _key )
{
    for ( int i = 0; i < _map.m_keys.m_nUsed; i++ )
        if (_map.m_keys.m_pData[ i ] == _key )
            return i;

    return -1;
}


const char * MapGet ( const Map & _map, int _key )
{
    int keyPosition = MapFindKeyPosition( _map, _key );
	if ( keyPosition != -1 )
	    return _map.m_values.m_pData[ keyPosition ];
	else
	    return nullptr;
}

bool MapHasKey ( const Map & _map, int _key )
{
    return MapFindKeyPosition( _map, _key ) != -1;
}


void MapInsertKey ( Map & _map, int _key, const char * _value )
{
    int position = MapFindKeyPosition( _map, _key );
    if ( position == - 1 )
    {
		IntegerVectorPushBack( _map.m_keys, _key );
		StringVectorPushBack( _map.m_values, _value );
    }
	else {
		delete[] _map.m_values.m_pData[position];
		_map.m_values.m_pData[position] = new char[strlen(_value)+1];
		strcpy(_map.m_values.m_pData[position], _value);
	}
}



void MapRemoveKey ( Map & _map, int _key )
{
    int position = MapFindKeyPosition( _map, _key );
    assert( position != -1 );

    StringVectorDeleteAt( _map.m_values, position );
    IntegerVectorDeleteAt( _map.m_keys, position );
}