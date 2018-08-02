#ifndef _INTEGER_MAP_HPP_
#define _INTEGER_MAP_HPP_

struct IntegerMap;

IntegerMap * IntegerMapCreate();

void IntegerMapDestroy(IntegerMap * _pMap);

void IntegerMapInsertKey(IntegerMap & _map, int _key, double _value);

float IntegerMapFindAverageValue(const IntegerMap & _map, int _key);

void IntegerMapShow(const IntegerMap & _map);

float IntegerMapBinaryFind(const IntegerMap & _map, int _key);

#endif //  _INTEGER_MAP_HPP_