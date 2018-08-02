#define _CRT_SECURE_NO_WARNINGS

#include "sort_algorithms.hpp"

#include <iostream>
#include <fstream>
#include <cstring>

int main()
{
	std::ifstream in("words.txt");
	
	char ** stringDictionary = new char*[50];
	char buffer[256];
	int  currentWordsNumber = 0;
	
	while (!in.eof())
	{
		in.getline(buffer, sizeof(buffer));
		stringDictionary[currentWordsNumber] = new char[strlen(buffer) + 1];
		strcpy(stringDictionary[currentWordsNumber++], buffer);
	}

	mergeSort(stringDictionary, currentWordsNumber);

	for (int i = 0; i < currentWordsNumber; i++)
		std::cout << stringDictionary[i] << std::endl;
	
	for (int i = 0; i < currentWordsNumber; i++)
		delete[] stringDictionary[i];
	delete[] stringDictionary;
	return 0;
}