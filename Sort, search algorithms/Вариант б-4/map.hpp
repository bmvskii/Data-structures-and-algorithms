#ifndef _MAP_HPP_
#define _MAP_HPP_

struct Map;

Map * MapCreate ();

void MapDestroy ( Map * _pMap );

void MapClear ( Map & _map );

bool MapIsEmpty ( const Map & _map );

bool MapHasKey ( const Map & _map, const char * _key );

int  MapFindKeyPosition ( const Map & _map, const char * _key );

int  MapGet ( const Map & _map, const char * _key );

void MapInsertKey ( Map & _map, const char * _key, int _value );

void MapRemoveKey ( Map & _map, const char * _key );
 

#endif //  _MAP_HPP_
