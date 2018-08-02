#define _CRT_SECURE_NO_WARNINGS

#include "bstree.hpp"
#include "testing.hpp"

#include <iostream>
#include <fstream>
#include <cstring>
#include <clocale>

//������� ������ �������� ����
void printNode(const BSTree::Node & _node, std::ostream & _stream)
{
	_stream << _node.m_key.m_lastName << " " << _node.m_key.m_mark << std::endl;
}

void parseRow(BSTree ** _t, char * _buffer, Student _m, int _N)
{
	//��������� �����
	int index = 0;
	//���� ���� , ��� ��������� � ����
	while (_buffer && index != _N)
	{
		_buffer = strtok(NULL, " ");
		_m.m_mark = atoi(_buffer);
		BSTreeInsertKey(*_t[index++], _m);
	}

	//���� ��� �������� ������, �� ������ ������������
	if (strtok(NULL, " "))
		std::cout << "������������ ������." << std::endl;
}

int main(int argc, char ** argv)
{
	setlocale(LC_ALL, "rus");
	
	//��������� ����
	fileOpeningTest(argv[1]);
	treeFunctionalTest();

	//����� ������
	const int MARKS_SIZE = 4;
	char buffer[80];

	//��������� ������� ���� � ������� ������ ��� �������� ������
	std::ifstream in(argv[1]);	
	std::ofstream out[MARKS_SIZE];
	
	//������� ������ ��������
	BSTree * subject[MARKS_SIZE];
	//�������������� ��
	for (int i = 0; i < MARKS_SIZE; i++) subject[i] = BSTreeCreate();

	//���� �� ��������� ����� �����
	while (!in.eof())
	{
		//��������� ���������
		in.getline(buffer, sizeof(buffer));

		Student student;
		//�������� ������ ������� ( ������� )
		char * curr = strtok(buffer, " ");

		//�������� ����� � �������� �� ������
		student.m_lastName = new char[strlen(curr) + 1];
		strcpy(student.m_lastName, curr);

		//����� �������� ������� ��������� ������
		parseRow(subject, curr, student, MARKS_SIZE);
		
		//������� ��������� ������
		delete[]student.m_lastName;
	}

	//�������� ���������� �������� ������
	int fileSize = (argc - 2) >= MARKS_SIZE ? MARKS_SIZE : argc - 2;

	//������� ��������� ���������� �� �������� � �����
	for (int i = 0; i < fileSize; i++)
	{
		out[i].open(argv[i + 2]);
		BSTreeSymmetricWalk(*subject[i], printNode, out[i]);
	}

	//������� �������
	for (int i = 0; i < MARKS_SIZE; i++) BSTreeDestroy(subject[i]);
	return 0;
}

