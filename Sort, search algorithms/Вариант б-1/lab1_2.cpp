#include <iostream>
#include "sort_algorithms.hpp"
#include <ctime>
#include <cstdlib>

void InitArray(int *, const int);
void showTimeElementarySorter(int *, const int, ElementarySorter);

int main()
{
	const int SIZE = 500000;
	srand((unsigned)time(nullptr));
	int * intarray = new int[SIZE];

	showTimeElementarySorter(intarray, SIZE, nullptr);
	showTimeElementarySorter(intarray, SIZE, bubbleSort);
	showTimeElementarySorter(intarray, SIZE, selectionSort);
	showTimeElementarySorter(intarray, SIZE, insertionSort);

	delete[]intarray;
	return 0;
}

void InitArray(int * _array, const int _N)
{
	for (int i = 0; i < _N; i++)
		_array[i] = rand();
}

void showTimeElementarySorter(int * _intarray, const int _N, ElementarySorter _f)
{
	InitArray(_intarray, _N);
	clock_t startTick = clock();
	mergeSort(_intarray, _N,_f);
	clock_t finalTick = clock();

	std::cout << (double)(finalTick - startTick) / (double)CLOCKS_PER_SEC << std::endl;
}