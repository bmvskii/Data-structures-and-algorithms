#define _CRT_SECURE_NO_WARNINGS

#include "bstree.hpp"
#include "testing.hpp"

#include <iostream>
#include <fstream>
#include <cstring>
#include <clocale>

//функция печати значений узла
void printNode(const BSTree::Node & _node, std::ostream & _stream)
{
	_stream << _node.m_key.m_lastName << " " << _node.m_key.m_mark << std::endl;
}

void parseRow(BSTree ** _t, char * _buffer, Student _m, int _N)
{
	//считываем числа
	int index = 0;
	//пока есть , что считывать и куда
	while (_buffer && index != _N)
	{
		_buffer = strtok(NULL, " ");
		_m.m_mark = atoi(_buffer);
		BSTreeInsertKey(*_t[index++], _m);
	}

	//если еще остались оценки, но файлов недостаточно
	if (strtok(NULL, " "))
		std::cout << "Недостаточно файлов." << std::endl;
}

int main(int argc, char ** argv)
{
	setlocale(LC_ALL, "rus");
	
	//запускаем тесті
	fileOpeningTest(argv[1]);
	treeFunctionalTest();

	//число оценок
	const int MARKS_SIZE = 4;
	char buffer[80];

	//открываем входной файл и создаем массив для выходных файлов
	std::ifstream in(argv[1]);	
	std::ofstream out[MARKS_SIZE];
	
	//создаем массив деревьев
	BSTree * subject[MARKS_SIZE];
	//инициализируем их
	for (int i = 0; i < MARKS_SIZE; i++) subject[i] = BSTreeCreate();

	//пока не достигнут конец файла
	while (!in.eof())
	{
		//построчно считываем
		in.getline(buffer, sizeof(buffer));

		Student student;
		//отделяем первую лексему ( фамилию )
		char * curr = strtok(buffer, " ");

		//выделяем место и копируем из буфера
		student.m_lastName = new char[strlen(curr) + 1];
		strcpy(student.m_lastName, curr);

		//далее вызываем функцию обработки оценок
		parseRow(subject, curr, student, MARKS_SIZE);
		
		//удаляем временную память
		delete[]student.m_lastName;
	}

	//получаем количество выходных файлов
	int fileSize = (argc - 2) >= MARKS_SIZE ? MARKS_SIZE : argc - 2;

	//выводим считанную информацию из деревьев в файлы
	for (int i = 0; i < fileSize; i++)
	{
		out[i].open(argv[i + 2]);
		BSTreeSymmetricWalk(*subject[i], printNode, out[i]);
	}

	//удаляем деревья
	for (int i = 0; i < MARKS_SIZE; i++) BSTreeDestroy(subject[i]);
	return 0;
}

