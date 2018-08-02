#ifndef _POINT3D_LIST_HPP_
#define _POINT3D_LIST_HPP_

#include <iostream>

struct Point3D
{
	float x, y, z;
};

struct Point3DList
{
    struct Node
    {
        Point3D m_value;
        Node * m_pNext;
    };

    Node * m_pFirst, * m_pLast;
};


void Point3DListInit ( Point3DList & _list );

void Point3DListDestroy ( Point3DList & _list );

bool Point3DListIsEmpty ( const Point3DList & _list );

int Point3DListSize ( const Point3DList & _list );

void Point3DListClear ( Point3DList & _list );

void Point3DListPushBack ( Point3DList & _list, Point3D _data );

void Point3DListPushFront ( Point3DList & _list, Point3D _data );

void Point3DListInsertAfter ( Point3DList & _list, Point3DList::Node * _pPrevNode, Point3D _data );

void Point3DListInsertBefore ( Point3DList & _list, Point3DList::Node * _pNextNode, Point3D _data );

void Point3DListPopBack ( Point3DList & _list );

void Point3DListPopFront ( Point3DList & _list );

void Point3DListDeleteAfter ( Point3DList & _list, Point3DList::Node * _pPrevNode );

void Point3DListDeleteBefore ( Point3DList & _list, Point3DList::Node * _pNextNode );

void Point3DListDeleteNode ( Point3DList & _list, Point3DList::Node * _pNode );

#endif //  _POINT3D_FORWARD_LIST_HPP_