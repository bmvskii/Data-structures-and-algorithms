#define _CRT_SECURE_NO_WARNINGS

#include "map.hpp"
#include "double_vector.hpp"
#include "date_vector.hpp"
#include "test.hpp"

#include <cassert>

struct Map
{
	DateVector m_keys;
	DoubleVector m_values;
};

Map * MapCreate()
{
	Map * pMap = new Map;
	DateVectorInit(pMap->m_keys);
	DoubleVectorInit(pMap->m_values);
	return pMap;
}

void  MapDestroy(Map * _pMap)
{
	DateVectorDestroy(_pMap->m_keys);
	DoubleVectorDestroy(_pMap->m_values);
	delete _pMap;
}

void  MapInsertKey(Map & _map, Date _key, double _value)
{
	int curr = _map.m_keys.m_nUsed;

	DateVectorPushBack(_map.m_keys, _key, curr);
	if (curr == 0)
		DoubleVectorPushBack(_map.m_values, _value);
	else
		DoubleVectorInsertAt(_map.m_values, curr, _value);
}

double MapGetAverage(const Map & _map, Date _key)
{
	int max = -1;
	//производим поиск большего ключа и запоминаем его индекс
	for (int i = 0; i < _map.m_keys.m_nUsed; i++){
		if (_map.m_keys.m_pData[i].m_year > _key.m_year ||
			(_map.m_keys.m_pData[i].m_year == _key.m_year &&
				_map.m_keys.m_pData[i].m_month > _key.m_month) ||
				(_map.m_keys.m_pData[i].m_year == _key.m_year &&
					_map.m_keys.m_pData[i].m_month == _key.m_month &&
					_map.m_keys.m_pData[i].m_day > _key.m_day)) {
			max = i;
			break;
		}
	}
	//если ничего не нашло, либо у нас только 1 элемент
	//то возвращаем -1 - ничего не найдено
	if (max == 0 || max == -1) 
		return -1;

	//если нашли больший элемент , то возвращаем их среднее значение
 	return (_map.m_values.m_pData[max] + _map.m_values.m_pData[max - 1]) / 2;
}

double MapFind(const Map& _map, Date _key)
{
	int l = 0, r = _map.m_keys.m_nUsed, m;
	
	while (l <= r)
	{
		m = l + (r - l) / 2;

		if (_map.m_keys.m_pData[m].m_year > _key.m_year ||
			(_map.m_keys.m_pData[m].m_year == _key.m_year &&
				_map.m_keys.m_pData[m].m_month > _key.m_month) ||
				(_map.m_keys.m_pData[m].m_year == _key.m_year &&
					_map.m_keys.m_pData[m].m_month == _key.m_month &&
					_map.m_keys.m_pData[m].m_day > _key.m_day))
			r = m - 1;
		else if (_map.m_keys.m_pData[m].m_year < _key.m_year ||
			(_map.m_keys.m_pData[m].m_year == _key.m_year &&
				_map.m_keys.m_pData[m].m_month < _key.m_month) ||
				(_map.m_keys.m_pData[m].m_year == _key.m_year &&
					_map.m_keys.m_pData[m].m_month == _key.m_month &&
					_map.m_keys.m_pData[m].m_day < _key.m_day))
			l = m + 1;
		else 
			return _map.m_values.m_pData[m];
	}
	return -1;
}

void MapParseData(Map & _map, char * _str)
{
	Date key;
	double value = 0;
	
	trueDataInDate(_str);
	sscanf(_str, "%2d/%2d/%4d", &key.m_day, &key.m_month, &key.m_year);
	isDateRangeTrue(key.m_day, key.m_month, key.m_year);

	char * tempBuffer = strtok(_str, " ");
	tempBuffer = strtok(NULL, " ");
	convertingCurse(tempBuffer);
	value = atof(tempBuffer);
	isPositiveCurse(value);

	MapInsertKey(_map, key, value);
}