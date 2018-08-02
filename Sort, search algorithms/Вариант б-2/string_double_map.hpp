#ifndef _STRING_DOUBLE_MAP_HPP_
#define _STRING_DOUBLE_MAP_HPP_

struct String2DoubleMap;

String2DoubleMap * String2DoubleMapCreate ();

void String2DoubleMapDestroy ( String2DoubleMap * _pMap );

void String2DoubleMapClear ( String2DoubleMap & _map );

bool String2DoubleMapIsEmpty ( const String2DoubleMap & _map );

bool String2DoubleMapHasKey ( const String2DoubleMap & _map, const char * _key );

int String2DoubleMapFindKeyPosition ( const String2DoubleMap & _map, const char * _key );

double String2DoubleMapGet ( const String2DoubleMap & _map, const char * _key );

void String2DoubleMapInsertKey ( String2DoubleMap & _map, const char * _key, double _value );

void String2DoubleMapRemoveKey ( String2DoubleMap & _map, const char * _key );
 

#endif //  _STRING_DOUBLE_MAP_HPP_
