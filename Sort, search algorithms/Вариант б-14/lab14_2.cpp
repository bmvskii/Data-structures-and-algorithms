#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>

struct PersonName
{
	char * m_lastName;
	char m_initials[2];
};

void selectionSort(PersonName* _pData, const int _N);
void addPerson(PersonName & _p, const char * _lastName, const char * _initials);

int main()
{
	const int SIZE = 10;
	PersonName persons[SIZE];

	addPerson(persons[0], "Rogovoy", "EA");
	addPerson(persons[1], "Smith", "BA");
	addPerson(persons[2], "Cole", "JR");
	addPerson(persons[3], "Lamar", "KW");
	addPerson(persons[4], "Houston", "GR");
	addPerson(persons[5], "Jolie", "AF");
	addPerson(persons[6], "Aston", "MK");
	addPerson(persons[7], "Jordan", "ML");
	addPerson(persons[8], "Aston", "AR");
	addPerson(persons[9], "Woodley", "TD");

	selectionSort(persons, SIZE);

	for (int i = 0; i < SIZE; i++)
		std::cout << persons[i].m_lastName << " " << persons[i].m_initials << std::endl;

	for (int i = 0; i < SIZE; i++)
		delete[]persons[i].m_lastName;
	return 0;
}

void selectionSort(PersonName* _pData, const int _N)
{
	for (int i = 0; i < _N - 1; i++)
	{
		int lowIndex = i;
		for (int j = i + 1; j < _N; j++)
			if (_stricmp(_pData[j].m_lastName, _pData[lowIndex].m_lastName) < 0 || 
			   (!_stricmp(_pData[j].m_lastName, _pData[lowIndex].m_lastName) &&
				_stricmp(_pData[j].m_initials, _pData[lowIndex].m_initials) < 0))
				lowIndex = j;

		std::swap(_pData[lowIndex], _pData[i]);
	}
}

void addPerson(PersonName & _p, const char * _lastName, const char * _initials)
{
	_p.m_lastName = new char[strlen(_lastName) + 1];

	strcpy(_p.m_initials, _initials);
	strcpy(_p.m_lastName, _lastName);
}