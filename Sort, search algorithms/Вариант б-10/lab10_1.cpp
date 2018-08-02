#include <iostream>

struct CustomerVisitTime
{
	int m_startHour, m_startMinute;
	int m_finishHour, m_finishMinute;
};

void getTime(CustomerVisitTime * _time, const int _N)
{
	CustomerVisitTime currentTime, maxTime;
	int maxCustomers = 0, currentTimeCustomers;

	currentTime.m_startHour = 0;
	currentTime.m_startMinute = 0;
	currentTime.m_finishHour = 0;
	currentTime.m_finishMinute = 30;

	for (int j = 0; j < 48; j++)
	{
		currentTimeCustomers = 0;

		//сравнивание времени и если посетитель был в данное время увеличиваем счетчик
		for (int i = 0; i < _N; i++) {
			if ((_time[i].m_finishHour > currentTime.m_finishHour ||
				(_time[i].m_finishHour == currentTime.m_finishHour && _time[i].m_finishMinute >= currentTime.m_finishMinute))
				&& (_time[i].m_startHour < currentTime.m_startHour ||
				(_time[i].m_startHour == currentTime.m_startHour && _time[i].m_startMinute <= currentTime.m_startMinute)))
				currentTimeCustomers++;
		}

		//если счетчик больше максимума, то присваиваем это время и кол-во поситителей
		if (currentTimeCustomers > maxCustomers)
		{
			maxTime = currentTime;
			maxCustomers = currentTimeCustomers;
		}

		//увеличиваем время
		if (currentTime.m_finishHour <= 24)
		{
			if (currentTime.m_startMinute == 30)
			{
				currentTime.m_startHour++;
				currentTime.m_startMinute = 0;
			}
			else if (currentTime.m_startMinute == 0)
			{
				currentTime.m_startMinute += 30;
			}

			if (currentTime.m_finishMinute == 30)
			{
				currentTime.m_finishHour++;
				currentTime.m_finishMinute = 0;
			}
			else if (currentTime.m_finishMinute == 0)
			{
				currentTime.m_finishMinute += 30;
			}
		}
	}

	//выводим сначала часы
	std::cout << maxTime.m_startHour << ":";
	if (maxTime.m_startMinute == 0)
		std::cout << "00";
	else
		std::cout << maxTime.m_startMinute;

	//потом выводим минуты
	std::cout << " - " << maxTime.m_finishHour << ":";
	if (maxTime.m_finishMinute == 0)
		std::cout << "00";
	else
		std::cout << maxTime.m_finishMinute << std::endl;
}

int main()
{
	CustomerVisitTime visiters[8] = {
	{ 12,00,14,40 },
	{ 16,10,15,30 },
	{ 15,45,17,00 },
	{ 12,50,13,55 },
	{ 13,00,15,20 },
	{ 14,45,18,00 },
	{ 18,50,20,55 },
	{ 17,00,21,20 }
	};

	getTime(visiters, 8);
}
