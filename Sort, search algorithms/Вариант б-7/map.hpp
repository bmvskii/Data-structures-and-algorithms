#ifndef _MAP_HPP_
#define _MAP_HPP_

struct Map;

Map * MapCreate ();

void MapDestroy ( Map * _pMap );

void MapClear ( Map & _map );

bool MapIsEmpty ( const Map & _map );

bool MapHasKey ( const Map & _map, int _key );

int MapFindKeyPosition ( const Map & _map, int _key );

const char * MapGet ( const Map & _map, int _key );

void MapInsertKey ( Map & _map, int _key, const char * _value );

void MapRemoveKey ( Map & _map, int _key );
 

#endif //  _MAP_HPP_
