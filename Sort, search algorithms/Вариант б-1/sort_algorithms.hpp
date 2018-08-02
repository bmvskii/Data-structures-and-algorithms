#ifndef _SORT_ALGORITHMS_HPP_
#define _SORT_ALGORITHMS_HPP_

typedef void (*ElementarySorter) (int *, int);

void bubbleSort(int * _pData, int _N);

void insertionSort(int * _pData, int _N);

void selectionSort(int * _pData, int _N);

void mergeSort(int * _pData, int _N, ElementarySorter _f);

#endif // _SORT_ALGORITHMS_HPP_