#define _CRT_SECURE_NO_WARNINGS

#include "map.hpp"
#include "integer_vector.hpp"
#include "string_vector.hpp"

#include <cassert>
#include <cstring>

struct Map
{
    StringVector m_keys;
    IntegerVector m_values;
};

Map * MapCreate ()
{
    Map * pMap = new Map;
    StringVectorInit( pMap->m_keys );
    IntegerVectorInit( pMap->m_values );
    return pMap;
}


void MapDestroy ( Map * _pMap )
{
    StringVectorDestroy( _pMap->m_keys );
    IntegerVectorDestroy( _pMap->m_values );
    delete _pMap;
}


void MapClear ( Map & _map )
{
    StringVectorClear( _map.m_keys );
    IntegerVectorClear( _map.m_values );
}


bool MapIsEmpty ( const Map & _map )
{
    return StringVectorIsEmpty( _map.m_keys );
}


int MapFindKeyPosition ( const Map & _map, const char * _key )
{
    for ( int i = 0; i < _map.m_keys.m_nUsed; i++ )
        if (!strcmp( _map.m_keys.m_pData[ i ] , _key) )
            return i;

    return -1;
}


int MapGet ( const Map & _map, const char * _key )
{
    int keyPosition = MapFindKeyPosition( _map, _key );
	if ( keyPosition != -1 )
	    return _map.m_values.m_pData[ keyPosition ];
	else
	    return -1;
}

bool MapHasKey ( const Map & _map, const char * _key )
{
    return MapFindKeyPosition( _map, _key ) != -1;
}


void MapInsertKey ( Map & _map, const char * _key, int _value )
{
    int position = MapFindKeyPosition( _map, _key );
    if ( position == - 1 )
    {
        StringVectorPushBack( _map.m_keys, _key );
        IntegerVectorPushBack( _map.m_values, _value );
    }
    else
        _map.m_values.m_pData[ position ] = _value;
}



void MapRemoveKey ( Map & _map, const char * _key )
{
    int position = MapFindKeyPosition( _map, _key );
    assert( position != -1 );

    StringVectorDeleteAt( _map.m_keys, position );
    IntegerVectorDeleteAt( _map.m_values, position );
}