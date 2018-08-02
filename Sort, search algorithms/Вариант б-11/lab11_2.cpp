#include <iostream>

struct Date
{
	short m_day;
	short m_month;
	int m_year;
};

void selectionSort(Date* _pData, const int _N)
{
	for (int i = 0; i < _N - 1; i++)
	{
		int lowIndex = i;
		for (int j = i + 1; j < _N; j++)
			if (_pData[j].m_year > _pData[lowIndex].m_year || 
			   (_pData[j].m_year == _pData[lowIndex].m_year && 
				_pData[j].m_month > _pData[lowIndex].m_month) &&
			   (_pData[j].m_year == _pData[lowIndex].m_year &&
				_pData[j].m_month == _pData[lowIndex].m_month &&
				_pData[j].m_month > _pData[lowIndex].m_day))
				lowIndex = j;

		std::swap(_pData[lowIndex], _pData[i]);
	}
}

int main()
{
	const int DATE_SIZE = 10;
	Date dates[DATE_SIZE] = {
		{ 1,1,2015 },
		{ 2,11,2013 },
		{ 21,5,2012 },
		{ 16,6,2014 },
		{ 5,7,2016 },
		{ 17,6,2017 },
		{ 2,2,2015 },
		{ 5,4,2011 },
		{ 30,3,1998 },
		{ 25,1,2000 },
	};

	selectionSort(dates, DATE_SIZE);
	for (int i = 0; i < DATE_SIZE; i++)
		std::cout << dates[i].m_day << "/" << dates[i].m_month << "/" << dates[i].m_year << std::endl;

	return 0;
}