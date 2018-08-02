#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
#include <fstream>

#include "sort_algorithms.hpp"

int main()
{
	char ** stringArray = new char*[50];
	char buffer[80];
	int currentIndex = 0;
	std::ifstream file("strings.txt");
	
	while (!file.eof()) {
		file.getline(buffer, sizeof(buffer));
		stringArray[currentIndex] = new char[strlen(buffer) + 1];
		strcpy(stringArray[currentIndex++], buffer);
	}

	quickSort(stringArray, currentIndex);

	for (int i = 0; i < currentIndex; i++)
		std::cout << stringArray[i] << std::endl;

	for (int i = 0; i < currentIndex; i++)
		delete[]stringArray[i];
	delete[]stringArray;
	
	return 0;
}