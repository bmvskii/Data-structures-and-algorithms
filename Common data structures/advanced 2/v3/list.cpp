#include "list.hpp"
#include <cassert>

void ListInit ( List & _list )
{
    _list.m_pFirst = _list.m_pLast = nullptr;
}


void ListDestroy ( List & _list )
{
    ListClear( _list );
}


void ListClear ( List & _list )
{
    List::Node * pCurrent = _list.m_pFirst;
    while ( pCurrent )
    {
        List::Node * pTemp = pCurrent->m_pNext;
		delete[]pCurrent->m_value.m_sename;
        delete pCurrent;
        pCurrent = pTemp;
    }

    _list.m_pFirst = _list.m_pLast = nullptr;
}


bool ListIsEmpty ( const List & _list )
{
    return _list.m_pFirst == nullptr;
}


int ListSize ( const List & _list )
{
    int nElements = 0;
    const List::Node * pNode = _list.m_pFirst;
    while ( pNode )
    {
        ++ nElements;
        pNode = pNode->m_pNext;
    }

    return nElements;
}


void ListPushBack ( List & _list, Human _data )
{
    List::Node * pNewNode = new List::Node;
    pNewNode->m_value = _data;
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


void ListPushFront ( List & _list, Human _data )
{
    List::Node * pNewNode = new List::Node;
    pNewNode->m_value = _data;
    pNewNode->m_pNext = _list.m_pFirst;

    _list.m_pFirst = pNewNode;
    
    if ( ! _list.m_pLast )
        _list.m_pLast = pNewNode;
}


void ListInsertAfter ( List & _list, List::Node * _pPrevNode, Human _data )
{
    assert( ! ListIsEmpty( _list ) );

    if ( _pPrevNode == _list.m_pLast )
        ListPushBack( _list, _data );

    else
    {
        List::Node * pNewNode = new List::Node;
        pNewNode->m_value = _data;

        pNewNode->m_pNext = _pPrevNode->m_pNext;

        _pPrevNode->m_pNext = pNewNode;
    }
}


void ListInsertBefore ( List & _list, List::Node * _pNextNode, Human _data )
{
    assert( ! ListIsEmpty( _list ) );

    if ( _pNextNode == _list.m_pFirst )
        ListPushFront( _list, _data );

    else
    {
        List::Node * pCurrent = _list.m_pFirst;
        while ( pCurrent && pCurrent->m_pNext != _pNextNode )
            pCurrent = pCurrent->m_pNext;

        assert( pCurrent );

        List::Node * pNewNode = new List::Node;
        pNewNode->m_value = _data;

        pNewNode->m_pNext = _pNextNode;
        
        pCurrent->m_pNext = pNewNode;

    }
}


void ListPopFront ( List & _list )
{
    assert( ! ListIsEmpty( _list ) );

    List::Node * pFirst = _list.m_pFirst;

    if ( _list.m_pFirst == _list.m_pLast )
        _list.m_pFirst = _list.m_pLast = nullptr;

    else
        _list.m_pFirst = pFirst->m_pNext;
	
	delete[]pFirst->m_value.m_sename;
    delete pFirst;    
}


void ListPopBack ( List & _list )
{
    assert( ! ListIsEmpty( _list ) );

    List::Node * pLast = _list.m_pLast;

    if ( _list.m_pFirst == _list.m_pLast )
        _list.m_pFirst = _list.m_pLast = nullptr;

    else
    {
        List::Node * pCurrent = _list.m_pFirst;
        while ( pCurrent->m_pNext != _list.m_pLast )
            pCurrent = pCurrent->m_pNext;

        _list.m_pLast = pCurrent;
        pCurrent->m_pNext = nullptr;
    }

	delete[]pLast->m_value.m_sename;
    delete pLast;
}


void ListDeleteAfter ( List & _list, List::Node * _pPrevNode )
{
    assert( ! ListIsEmpty( _list ) );

    assert( _list.m_pLast != _pPrevNode );

    List::Node * pDyingNode = _pPrevNode->m_pNext;
    _pPrevNode->m_pNext = pDyingNode->m_pNext;

    if ( _list.m_pLast == pDyingNode )
        _list.m_pLast = _pPrevNode;
        
	delete[]pDyingNode->m_value.m_sename;
    delete pDyingNode;
}


void ListDeleteBefore ( List & _list, List::Node * _pNextNode )
{
    assert( ! ListIsEmpty( _list ) );

    assert( _list.m_pFirst != _pNextNode );

    List::Node * pPrevNode = _list.m_pFirst, * pCurrentNode = _list.m_pFirst->m_pNext;
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

		delete[]pCurrentNode->m_value.m_sename;
        delete pCurrentNode;
    }
}


void ListDeleteNode ( List & _list, List::Node * _pNode )
{
    if ( _list.m_pFirst == _pNode )
        ListPopFront( _list );

    else if ( _list.m_pLast == _pNode )
        ListPopBack( _list );

    else
        ListDeleteBefore( _list, _pNode->m_pNext );
}


void ListPrint ( const List & _list, std::ostream & _stream, int _age)
{
    const List::Node * pCurrent = _list.m_pFirst;
    while ( pCurrent )
    {
		if (pCurrent->m_value.m_age > _age)
			_stream << pCurrent->m_value.m_sename << " " << pCurrent->m_value.m_age << std::endl;
        pCurrent = pCurrent->m_pNext;
    }
}