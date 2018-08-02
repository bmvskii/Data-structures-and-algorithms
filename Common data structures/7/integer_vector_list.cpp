#include "integer_vector_list.hpp"
#include <cassert>

void IntegerVectorListInit ( IntegerVectorList & _list )
{
    _list.m_pFirst = _list.m_pLast = nullptr;
}


void IntegerVectorListDestroy ( IntegerVectorList & _list )
{
    IntegerVectorListClear( _list );
}


void IntegerVectorListClear ( IntegerVectorList & _list )
{
    IntegerVectorList::Node * pCurrent = _list.m_pFirst;
    while ( pCurrent )
    {
        IntegerVectorList::Node * pTemp = pCurrent->m_pNext;
		IntegerVectorDestroy(pCurrent->m_value);
        delete pCurrent;
        pCurrent = pTemp;
    }

    _list.m_pFirst = _list.m_pLast = nullptr;
}


bool IntegerVectorListIsEmpty ( const IntegerVectorList & _list )
{
    return _list.m_pFirst == nullptr;
}


int IntegerVectorListSize ( const IntegerVectorList & _list )
{
    int nElements = 0;
    const IntegerVectorList::Node * pNode = _list.m_pFirst;
    while ( pNode )
    {
        ++ nElements;
        pNode = pNode->m_pNext;
    }

    return nElements;
}


void IntegerVectorListPushBack ( IntegerVectorList & _list, IntegerVector _data )
{
    IntegerVectorList::Node * pNewNode = new IntegerVectorList::Node;
	IntegerVectorInit(pNewNode->m_value);

	//копируем элементы из входного вектора в созданный
	for (int i = 0; i < _data.m_nUsed; i++)
		IntegerVectorPushBack(pNewNode->m_value, _data.m_pData[i]);

    pNewNode->m_pNext = nullptr;

    if ( ! _list.m_pFirst )
    {
        assert( ! _list.m_pLast );
        _list.m_pFirst = pNewNode;
    }
    else
        _list.m_pLast->m_pNext = pNewNode;

    _list.m_pLast = pNewNode;
}


void IntegerVectorListPushFront ( IntegerVectorList & _list, IntegerVector _data )
{
    IntegerVectorList::Node * pNewNode = new IntegerVectorList::Node;
	IntegerVectorInit(pNewNode->m_value);

	//копируем элементы из входного вектора в созданный
	for (int i = 0; i < _data.m_nUsed; i++)
		IntegerVectorPushBack(pNewNode->m_value, _data.m_pData[i]);

    pNewNode->m_pNext = _list.m_pFirst;

    _list.m_pFirst = pNewNode;
    
    if ( ! _list.m_pLast )
        _list.m_pLast = pNewNode;
}


void IntegerVectorListInsertAfter ( IntegerVectorList & _list, IntegerVectorList::Node * _pPrevNode, IntegerVector _data )
{
    assert( ! IntegerVectorListIsEmpty( _list ) );

    if ( _pPrevNode == _list.m_pLast )
        IntegerVectorListPushBack( _list, _data );

    else
    {
        IntegerVectorList::Node * pNewNode = new IntegerVectorList::Node;
		IntegerVectorInit(pNewNode->m_value); 

		//копируем элементы из входного вектора в созданный
		for (int i = 0; i < _data.m_nUsed; i++)
			IntegerVectorPushBack(pNewNode->m_value, _data.m_pData[i]);


        pNewNode->m_pNext = _pPrevNode->m_pNext;

        _pPrevNode->m_pNext = pNewNode;
    }
}


void IntegerVectorListInsertBefore ( IntegerVectorList & _list, IntegerVectorList::Node * _pNextNode, IntegerVector _data )
{
    assert( ! IntegerVectorListIsEmpty( _list ) );

    if ( _pNextNode == _list.m_pFirst )
        IntegerVectorListPushFront( _list, _data );

    else
    {
        IntegerVectorList::Node * pCurrent = _list.m_pFirst;
        while ( pCurrent && pCurrent->m_pNext != _pNextNode )
            pCurrent = pCurrent->m_pNext;

        assert( pCurrent );

        IntegerVectorList::Node * pNewNode = new IntegerVectorList::Node;
		IntegerVectorInit(pNewNode->m_value); 

		//копируем элементы из входного вектора в созданный
		for (int i = 0; i < _data.m_nUsed; i++)
			IntegerVectorPushBack(pNewNode->m_value, _data.m_pData[i]);


        pNewNode->m_pNext = _pNextNode;
        
        pCurrent->m_pNext = pNewNode;

    }
}


void IntegerVectorListPopFront ( IntegerVectorList & _list )
{
    assert( ! IntegerVectorListIsEmpty( _list ) );

    IntegerVectorList::Node * pFirst = _list.m_pFirst;

    if ( _list.m_pFirst == _list.m_pLast )
        _list.m_pFirst = _list.m_pLast = nullptr;

    else
        _list.m_pFirst = pFirst->m_pNext;

	//удаляем корректно вектор в узле
	IntegerVectorDestroy(pFirst->m_value);
    delete pFirst;    
}


void IntegerVectorListPopBack ( IntegerVectorList & _list )
{
    assert( ! IntegerVectorListIsEmpty( _list ) );

    IntegerVectorList::Node * pLast = _list.m_pLast;

    if ( _list.m_pFirst == _list.m_pLast )
        _list.m_pFirst = _list.m_pLast = nullptr;

    else
    {
        IntegerVectorList::Node * pCurrent = _list.m_pFirst;
        while ( pCurrent->m_pNext != _list.m_pLast )
            pCurrent = pCurrent->m_pNext;

        _list.m_pLast = pCurrent;
        pCurrent->m_pNext = nullptr;
    }

	//удаляем корректно вектор в узле
	IntegerVectorDestroy(pLast->m_value);
    delete pLast;
}


void IntegerVectorListDeleteAfter ( IntegerVectorList & _list, IntegerVectorList::Node * _pPrevNode )
{
    assert( ! IntegerVectorListIsEmpty( _list ) );

    assert( _list.m_pLast != _pPrevNode );

    IntegerVectorList::Node * pDyingNode = _pPrevNode->m_pNext;
    _pPrevNode->m_pNext = pDyingNode->m_pNext;

    if ( _list.m_pLast == pDyingNode )
        _list.m_pLast = _pPrevNode;

	//удаляем корректно вектор в узле
	IntegerVectorDestroy(pDyingNode->m_value);
    delete pDyingNode;
}


void IntegerVectorListDeleteBefore ( IntegerVectorList & _list, IntegerVectorList::Node * _pNextNode )
{
    assert( ! IntegerVectorListIsEmpty( _list ) );

    assert( _list.m_pFirst != _pNextNode );

    IntegerVectorList::Node * pPrevNode = _list.m_pFirst, * pCurrentNode = _list.m_pFirst->m_pNext;
    if ( pCurrentNode == _pNextNode )
    {
        delete _list.m_pFirst;
        _list.m_pFirst = _pNextNode;
    }

    else
    {
        while ( pCurrentNode->m_pNext != _pNextNode )
        {
            pPrevNode = pCurrentNode;
            pCurrentNode = pCurrentNode->m_pNext;
        }

        pPrevNode->m_pNext = _pNextNode;

		//удаляем корректно вектор в узле
		IntegerVectorDestroy(pCurrentNode->m_value);
        delete pCurrentNode;
    }
}


void IntegerVectorListDeleteNode ( IntegerVectorList & _list, IntegerVectorList::Node * _pNode )
{
    if ( _list.m_pFirst == _pNode )
        IntegerVectorListPopFront( _list );

    else if ( _list.m_pLast == _pNode )
        IntegerVectorListPopBack( _list );

    else
        IntegerVectorListDeleteBefore( _list, _pNode->m_pNext );
}

