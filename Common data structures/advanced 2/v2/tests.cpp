#define _CRT_SECURE_NO_WARNINGS

#include "tests.hpp"
#include "data_vector.hpp"

#include <fstream>
#include <cstring>

void runTests(int _argc, char ** _argv, std::ostream & _s)
{
	_s << "1."; testHasPassedArguments(_s, _argc); _s << " PASSED SUCCESSFULLY " << std::endl;
	_s << "2."; testHasPassedFilePath(_s,_argc); _s << " PASSED SUCCESFULLY " << std::endl;
	_s << "3."; testHasPassedFixedAge(_s, _argc); _s << " PASSED SUCCESSFULLY " << std::endl;
	_s << "4."; testFixedAgeConvert(_s, _argv); _s << " PASSED SUCCESSFULLY " << std::endl;
	_s << "5."; testFixedAgeIsPositive(_s, _argv); _s << " PASSED SUCCESFULLY " << std::endl;
	_s << "6."; testOpenFile(_s, _argv[1]); _s << " PASSED SUCCESFULLY " << std::endl;
	_s << "7."; testAgeFromFile(_s,_argv[1],atoi(_argv[2]));
}

void testHasPassedArguments(std::ostream & _s, int _argc)
{
	_s << " TEST : HAS COMMAND LINE ARGUMENT ";
	assert(_argc >= 1);
}

void testHasPassedFilePath(std::ostream & _s, int _argc)
{
	_s << " TEST : HAS FILE PATH ";
	assert(_argc >= 2);
}

void testHasPassedFixedAge(std::ostream & _s, int _argc)
{
	_s << " TEST : HAS COMMAND FIXED AGE ";
	assert(_argc == 3);
}

void testFixedAgeConvert(std::ostream & _s, char ** _argv)
{
	_s << " TEST : CONVERT THE FIXED AGE ";
	assert(atoi(_argv[2]));
}

void testFixedAgeIsPositive(std::ostream & _s, char ** _argv)
{
	_s << " TEST : FIXED AGE IS POSITIVE ";
	assert(atoi(_argv[2]) > 0);
}

void testOpenFile(std::ostream & _s, char * _path)
{
	std::ifstream file(_path);

	_s << " TEST : FILE OPENING ";
	assert(file.is_open());
}

void testAgeFromFile(std::ostream & _s, char * _path, int _fixedAge)
{
	_s << " TEST : TRUE DATA IN FILE  ";

	//������� ������ � �������������� ���
	DataVector * pVector = new DataVector();
	DataVectorInit(*pVector);

	//������ ��� ����� �� �����
	char temp[1024];

	std::ifstream in(_path);
	//���� �� ��������� ����� �����
	while (!in.eof())
	{
		//��������� ������ � �����
		in.getline(temp, sizeof(temp));

		//������� ���������, ������� ����� ���������
		Data person;

		//���������� ������� strtok , ����� ��������� ���� ������ �� �������
		char * p = strtok(temp, " ");

		//�������� ������ ��� ���� ������� � �������� ����������
		person.m_personSecondName = new char[strlen(p) + 1];
		strcpy(person.m_personSecondName, p);

		//�������� �������
		p = strtok(NULL, " ");

		//���� �� ��������� ������������� ��� ������� ( ������ ������ )
		//������� ������ � ��������� ���������
		assert(atoi(p));
		
		//����������� ������� � ��������� ��������� � ������
		person.m_personAge = atoi(p);
		DataVectorPushBack(*pVector, person);
	}
	_s << " PASSED SUCCESFULLY " << std::endl << std::endl;;

	//������� ���� ���������, ��� ������� ������ ���������
	DataVectorPrintFixed(*pVector, std::cout, _fixedAge);

	//������� ������
	DataVectorDestroy(*pVector);
}