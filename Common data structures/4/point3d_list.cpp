#include "point3d_list.hpp"
#include <cassert>

void Point3DListInit ( Point3DList & _list )
{
    _list.m_pFirst = _list.m_pLast = nullptr;
}


void Point3DListDestroy ( Point3DList & _list )
{
    Point3DListClear( _list );
}


void Point3DListClear ( Point3DList & _list )
{
    Point3DList::Node * pCurrent = _list.m_pFirst;
    while ( pCurrent )
    {
        Point3DList::Node * pTemp = pCurrent->m_pNext;
        delete pCurrent;
        pCurrent = pTemp;
    }

    _list.m_pFirst = _list.m_pLast = nullptr;
}


bool Point3DListIsEmpty ( const Point3DList & _list )
{
    return _list.m_pFirst == nullptr;
}


int Point3DListSize ( const Point3DList & _list )
{
    int nElements = 0;
    const Point3DList::Node * pNode = _list.m_pFirst;
    while ( pNode )
    {
        ++ nElements;
        pNode = pNode->m_pNext;
    }

    return nElements;
}


void Point3DListPushBack ( Point3DList & _list, Point3D _data )
{
    Point3DList::Node * pNewNode = new Point3DList::Node;
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


void Point3DListPushFront ( Point3DList & _list, Point3D _data )
{
    Point3DList::Node * pNewNode = new Point3DList::Node;
    pNewNode->m_value = _data;
    pNewNode->m_pNext = _list.m_pFirst;

    _list.m_pFirst = pNewNode;
    
    if ( ! _list.m_pLast )
        _list.m_pLast = pNewNode;
}


void Point3DListInsertAfter ( Point3DList & _list, Point3DList::Node * _pPrevNode, Point3D _data )
{
    assert( ! Point3DListIsEmpty( _list ) );

    if ( _pPrevNode == _list.m_pLast )
        Point3DListPushBack( _list, _data );

    else
    {
        Point3DList::Node * pNewNode = new Point3DList::Node;
        pNewNode->m_value = _data;

        pNewNode->m_pNext = _pPrevNode->m_pNext;

        _pPrevNode->m_pNext = pNewNode;
    }
}


void Point3DListInsertBefore ( Point3DList & _list, Point3DList::Node * _pNextNode, Point3D _data )
{
    assert( ! Point3DListIsEmpty( _list ) );

    if ( _pNextNode == _list.m_pFirst )
        Point3DListPushFront( _list, _data );

    else
    {
        Point3DList::Node * pCurrent = _list.m_pFirst;
        while ( pCurrent && pCurrent->m_pNext != _pNextNode )
            pCurrent = pCurrent->m_pNext;

        assert( pCurrent );

        Point3DList::Node * pNewNode = new Point3DList::Node;
        pNewNode->m_value = _data;

        pNewNode->m_pNext = _pNextNode;
        
        pCurrent->m_pNext = pNewNode;

    }
}


void Point3DListPopFront ( Point3DList & _list )
{
    assert( ! Point3DListIsEmpty( _list ) );

    Point3DList::Node * pFirst = _list.m_pFirst;

    if ( _list.m_pFirst == _list.m_pLast )
        _list.m_pFirst = _list.m_pLast = nullptr;

    else
        _list.m_pFirst = pFirst->m_pNext;

    delete pFirst;    
}


void Point3DListPopBack ( Point3DList & _list )
{
    assert( ! Point3DListIsEmpty( _list ) );

    Point3DList::Node * pLast = _list.m_pLast;

    if ( _list.m_pFirst == _list.m_pLast )
        _list.m_pFirst = _list.m_pLast = nullptr;

    else
    {
        Point3DList::Node * pCurrent = _list.m_pFirst;
        while ( pCurrent->m_pNext != _list.m_pLast )
            pCurrent = pCurrent->m_pNext;

        _list.m_pLast = pCurrent;
        pCurrent->m_pNext = nullptr;
    }

    delete pLast;
}


void Point3DListDeleteAfter ( Point3DList & _list, Point3DList::Node * _pPrevNode )
{
    assert( ! Point3DListIsEmpty( _list ) );

    assert( _list.m_pLast != _pPrevNode );

    Point3DList::Node * pDyingNode = _pPrevNode->m_pNext;
    _pPrevNode->m_pNext = pDyingNode->m_pNext;

    if ( _list.m_pLast == pDyingNode )
        _list.m_pLast = _pPrevNode;
        
    delete pDyingNode;
}


void Point3DListDeleteBefore ( Point3DList & _list, Point3DList::Node * _pNextNode )
{
    assert( ! Point3DListIsEmpty( _list ) );

    assert( _list.m_pFirst != _pNextNode );

    Point3DList::Node * pPrevNode = _list.m_pFirst, * pCurrentNode = _list.m_pFirst->m_pNext;
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
        delete pCurrentNode;
    }
}


void Point3DListDeleteNode ( Point3DList & _list, Point3DList::Node * _pNode )
{
    if ( _list.m_pFirst == _pNode )
        Point3DListPopFront( _list );

    else if ( _list.m_pLast == _pNode )
        Point3DListPopBack( _list );

    else
        Point3DListDeleteBefore( _list, _pNode->m_pNext );
}

