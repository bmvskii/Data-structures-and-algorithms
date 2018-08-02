#include "integer_map.hpp"
#include "integer_vector.hpp"

#include <cassert>


struct IntegerMap
{
	IntegerVector m_Data;
};

IntegerMap * IntegerMapCreate()
{
	IntegerMap * pMap = new IntegerMap;
	IntegerVectorInit(pMap->m_Data);
	return pMap;
}


void IntegerMapDestroy(IntegerMap * _pMap)
{
	IntegerVectorDestroy(_pMap->m_Data);
	delete _pMap;
}


void IntegerMapClear(IntegerMap & _map)
{
	IntegerVectorClear(_map.m_Data);
}


bool IntegerMapIsEmpty(const IntegerMap & _map)
{
	return IntegerVectorIsEmpty(_map.m_Data);
}


int IntegerMapFindKeyPosition(const IntegerMap & _map, int _key)
{
	for (int i = 0; i < _map.m_Data.m_nUsed; i++)
	if (_map.m_Data.m_pData[i].m_key == _key)
		return i;

	return -1;
}


int IntegerMapGet(const IntegerMap & _map, int _key)
{
	int keyPosition = IntegerMapFindKeyPosition(_map, _key);
	if (keyPosition != -1)
		return _map.m_Data.m_pData[keyPosition].m_value;
	else
		return -1;
}

bool IntegerMapHasKey(const IntegerMap & _map, int _key)
{
	return IntegerMapFindKeyPosition(_map, _key) != -1;
}

void IntegerMapInsertKey(IntegerMap & _map, int _key, int _value)
{
	int position = IntegerMapFindKeyPosition(_map, _key);
	if (position == -1)
	{
		IntegerVectorPushBack(_map.m_Data, _key, _value);
	}
	else{
		_map.m_Data.m_pData[_map.m_Data.m_nUsed].m_key = _key;
		_map.m_Data.m_pData[_map.m_Data.m_nUsed].m_value = _value;
	}
}

void IntegerMapRemoveKey(IntegerMap & _map, int _key)
{
	int position = IntegerMapFindKeyPosition(_map, _key);
	assert(position != -1);

	IntegerVectorDeleteAt(_map.m_Data, position);
}

void IntegerMapShow(const IntegerMap & _map)
{
	for (int i = 0; i < _map.m_Data.m_nUsed; i++)
		std::cout << _map.m_Data.m_pData[i].m_key << " " << _map.m_Data.m_pData[i].m_value << std::endl;;
}
