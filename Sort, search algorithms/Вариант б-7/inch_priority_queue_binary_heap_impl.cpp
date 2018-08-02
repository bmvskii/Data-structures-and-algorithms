#include "inch_priority_queue.hpp"
#include "inch_vector.hpp"

#include <cassert>
#include <iostream>


struct InchPriorityQueue
{
	InchVector m_heapItems;
};


InchPriorityQueue * InchPriorityQueueCreate()
{
	InchPriorityQueue * pPQ = new InchPriorityQueue;
	InchVectorInit(pPQ->m_heapItems);
	InchVectorPushBack(pPQ->m_heapItems, { -1,-1 }); // reserved cell
	return pPQ;
}


void InchPriorityQueueDestroy(InchPriorityQueue * _pPQ)
{
	InchVectorDestroy(_pPQ->m_heapItems);
	delete _pPQ;
}



void InchPriorityQueueClear(InchPriorityQueue & _pq)
{
	_pq.m_heapItems.m_nUsed = 1;
}


bool InchPriorityQueueIsEmpty(const InchPriorityQueue & _pq)
{
	return _pq.m_heapItems.m_nUsed == 1;
}


void InchPriorityQueueSwim(InchPriorityQueue & _pq, int _pos)
{
	EnglishLengthUnit * pData = _pq.m_heapItems.m_pData;

	while (_pos > 1 && (pData[_pos / 2].m_feet < pData[_pos].m_feet ||
		 (pData[_pos/2].m_feet == pData[_pos].m_feet && pData[_pos/2].m_inches < pData[_pos].m_inches)))
	{
		std::swap(pData[_pos / 2], pData[_pos]);
		_pos = _pos / 2;
	}
}


void InchPriorityQueueSink(InchPriorityQueue & _pq, int _pos)
{
	int maxPosition = _pq.m_heapItems.m_nUsed - 1;
	while (2 * _pos <= maxPosition)
	{
		int childPos = 2 * _pos;
		if (childPos < maxPosition && (_pq.m_heapItems.m_pData[childPos].m_feet < _pq.m_heapItems.m_pData[childPos+1].m_feet ||
			(_pq.m_heapItems.m_pData[childPos].m_feet == _pq.m_heapItems.m_pData[childPos+1].m_feet &&
				_pq.m_heapItems.m_pData[childPos].m_inches < _pq.m_heapItems.m_pData[childPos+1].m_inches)))
			++childPos;

		if (_pq.m_heapItems.m_pData[_pos].m_feet > _pq.m_heapItems.m_pData[childPos].m_feet ||
		   (_pq.m_heapItems.m_pData[_pos].m_feet == _pq.m_heapItems.m_pData[childPos].m_feet &&
			_pq.m_heapItems.m_pData[_pos].m_inches > _pq.m_heapItems.m_pData[childPos].m_inches))
			break;

		std::swap(_pq.m_heapItems.m_pData[_pos], _pq.m_heapItems.m_pData[childPos]);
		_pos = childPos;
	}
}

void SliceEnglishLength(EnglishLengthUnit & _key)
{
	while (_key.m_inches >= 12)
	{
		_key.m_inches-=12;
		_key.m_feet++;
	}
}


void InchPriorityQueueInsert(InchPriorityQueue & _pq, EnglishLengthUnit _key)
{
	SliceEnglishLength(_key);
	InchVectorPushBack(_pq.m_heapItems, _key);
	InchPriorityQueueSwim(_pq, _pq.m_heapItems.m_nUsed - 1);
}


EnglishLengthUnit InchPriorityQueueMin(const InchPriorityQueue & _pq)
{
	assert(!InchPriorityQueueIsEmpty(_pq));
	return _pq.m_heapItems.m_pData[1];
}


void InchPriorityQueueDeleteMin(InchPriorityQueue & _pq)
{
	assert(!InchPriorityQueueIsEmpty(_pq));
	std::swap(_pq.m_heapItems.m_pData[1], _pq.m_heapItems.m_pData[_pq.m_heapItems.m_nUsed - 1]);
	InchVectorPopBack(_pq.m_heapItems);
	InchPriorityQueueSink(_pq, 1);
}

void selectionSort(EnglishLengthUnit * _pData, const int _N)
{
	for (int i = 0; i < _N - 1; i++)
	{
		int lowIndex = i;
		for (int j = i + 1; j < _N; j++)
			if (_pData[j].m_feet > _pData[lowIndex].m_feet ||
				(_pData[j].m_feet == _pData[lowIndex].m_feet &&
					_pData[j].m_inches > _pData[lowIndex].m_inches))
				lowIndex = j;

		std::swap(_pData[lowIndex], _pData[i]);
	}
}

void sink(EnglishLengthUnit * _pData, int _pos, int N)
{
	// Пока обработка не дошла до середины кучи
	while (2 * _pos <= N)
	{
		// Выясняем какой из дочерних элементов больше
		int childPos = 2 * _pos;
		if (childPos < N && (_pData[childPos].m_feet < _pData[childPos + 1].m_feet ||
			(_pData[childPos].m_feet == _pData[childPos + 1].m_feet &&
			_pData[childPos].m_inches < _pData[childPos + 1].m_inches)))
			++childPos;

		// Если родительский элемент больше наибольшего из дочерних, узел на месте
		if (!(_pData[_pos].m_feet > _pData[childPos].m_feet ||
			(_pData[_pos].m_feet == _pData[childPos].m_feet &&
			 _pData[_pos].m_inches > _pData[childPos].m_inches)))
			break;

		// Меняем местами родительский и дочерний узел
		std::swap(_pData[_pos], _pData[childPos]);

		// Продолжаем утопление с позиции дочернего элемента
		_pos = childPos;
	}
}

void heapSort(EnglishLengthUnit * _pData, int _N)
{
	for (int k = _N / 2; k >= 1; k--)
		sink(_pData - 1, k, _N);

	while (_N > 1)
	{
		std::swap(_pData[0], _pData[_N - 1]);
		sink(_pData - 1, 1, --_N);
	}
}

void InchPriorityQueuePrint(const InchPriorityQueue & _pq)
{
	EnglishLengthUnit * pBuffer = new EnglishLengthUnit[_pq.m_heapItems.m_nUsed];
	memcpy(pBuffer, _pq.m_heapItems.m_pData, _pq.m_heapItems.m_nUsed * sizeof(EnglishLengthUnit));
	selectionSort(pBuffer, _pq.m_heapItems.m_nUsed);

	if (_pq.m_heapItems.m_nUsed > 6)
		for (int i = 0; i < 5; i++)
			std::cout << pBuffer[i].m_feet << "," << pBuffer[i].m_inches << std::ends;
	else
	{
		if (InchPriorityQueueIsEmpty(_pq)) return;

		for (int i = 0; i < _pq.m_heapItems.m_nUsed-1; i++)
			std::cout << pBuffer[i].m_feet << "," << pBuffer[i].m_inches << std::ends;
	}

	delete[]pBuffer;
}