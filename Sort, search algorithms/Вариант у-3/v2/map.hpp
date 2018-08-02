#ifndef _MAP_HPP_
#define _MAP_HPP_

struct Map;
struct Date;

Map * MapCreate();

void MapDestroy(Map * _pMap);

void MapInsertKey(Map & _map, Date _key, double _value);

double MapGetAverage(const Map & _map, Date _key);

double MapFind(const Map & _map, Date _key);

void MapParseData(Map & _map, char * _str);

#endif //  _MAP_HPP_