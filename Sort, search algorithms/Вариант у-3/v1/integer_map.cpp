#include "integer_map.hpp"
#include "template_vector.hpp"

#include <cassert>

struct IntegerMap
{
	Vector<int> m_keys;
	Vector<double> m_values;
};

IntegerMap * IntegerMapCreate()
{
	IntegerMap * pMap = new IntegerMap;
	VectorInit(pMap->m_keys);
	VectorInit(pMap->m_values);
	return pMap;
}

void  IntegerMapDestroy(IntegerMap * _pMap)
{
	VectorDestroy(_pMap->m_keys);
	VectorDestroy(_pMap->m_values);
	delete _pMap;
}

void  IntegerMapInsertKey(IntegerMap & _map, int _key, double _value)
{
	int currentPosition = _map.m_keys.m_nUsed;
	VectorSortPushBack(_map.m_keys, _key, currentPosition);
	VectorInsertAt(_map.m_values, currentPosition, _value);
}

float IntegerMapFindAverageValue(const IntegerMap & _map, int _key)
{
	int left = 0, right = _map.m_keys.m_nUsed, mid;
	bool isHigher = false;

	while (true)
	{
		mid = left + (right - left) / 2;
		if (mid == _map.m_keys.m_nUsed) return 0;
		if (mid == -1) return 0;
		if (_key < _map.m_keys.m_pData[mid])
			if (_key > _map.m_keys.m_pData[mid - 1]) break;
		else 
			right = mid - 1;
		else if (_key > _map.m_keys.m_pData[mid]) 
			if (_key < _map.m_keys.m_pData[mid + 1]) 
			{
				isHigher = true;
				break;
			}
			else 
				left = mid + 1;
		}

	return isHigher ? 
		(_map.m_values.m_pData[mid] + _map.m_values.m_pData[mid + 1]) / 2 :
		(_map.m_values.m_pData[mid] + _map.m_values.m_pData[mid - 1]) / 2;
}

void  IntegerMapShow(const IntegerMap & _map)
{
	for (int i = 0; i < _map.m_keys.m_nUsed; i++)
		std::cout << _map.m_keys.m_pData[i] << " " << _map.m_values.m_pData[i] << std::endl;
}

float IntegerMapBinaryFind(const IntegerMap& _map, int _key)
{
	int left = 0, right = _map.m_keys.m_nUsed, mid;
	while (left <= right)
	{
		mid = left + (right - left) / 2;
		if (_key < _map.m_keys.m_pData[mid]) right = mid - 1;
		else if (_key > _map.m_keys.m_pData[mid]) left = mid + 1;
		else return _map.m_values.m_pData[mid];
	}
	return -1;
}
 