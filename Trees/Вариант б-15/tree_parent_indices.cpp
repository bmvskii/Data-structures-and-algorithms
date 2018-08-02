#include "tree_static.hpp"
#include <cassert>
#include <cstring>


struct Tree
{
    int m_nNodes;
    
    char * m_pNodeLabels;
    //родительские индексы
    int * m_pParentIndices;
	//список дочерных элементов
	struct ChildIndexElement
	{
		int m_childIndex;
		ChildIndexElement * m_pNext;
	};

	ChildIndexElement ** m_pHeader;
};



Tree * TreeCreate ( int _nNodes )
{
    assert( _nNodes > 0 );

    Tree * pTree = new Tree;
    pTree->m_nNodes = _nNodes;
    
    pTree->m_pNodeLabels = new char[ _nNodes ];
    memset( pTree->m_pNodeLabels, 0, _nNodes );

	//инициализируем родительские индексы
    pTree->m_pParentIndices = new int[ _nNodes ];
    memset( pTree->m_pParentIndices, 0, _nNodes * sizeof( int ) );
    pTree->m_pParentIndices[ 0 ] = -1;
	
	//инициализируем дочерные элементы
	pTree->m_pHeader = new Tree::ChildIndexElement *[_nNodes];
	memset(pTree->m_pHeader, 0, sizeof(Tree::ChildIndexElement *) * _nNodes);

    return pTree;
}


void TreeDestroy ( Tree * _pTree )
{
    delete[] _pTree->m_pNodeLabels;
    //удаление родительских индексов
	delete[] _pTree->m_pParentIndices;

	//удаление дочерных элементов
	for (int i = 0; i < _pTree->m_nNodes; i++)
	{
		Tree::ChildIndexElement * pCurrent = _pTree->m_pHeader[i];
		while (pCurrent)
		{
			Tree::ChildIndexElement * pTemp = pCurrent->m_pNext;
			delete pCurrent;
			pCurrent = pTemp;
		}
	}
	delete[] _pTree->m_pHeader;
    delete _pTree;
}


int TreeGetRootIndex ( const Tree & )
{
    return 0;
}


TreeNodeLabel TreeGetLabel ( const Tree & _tree, int _nodeIndex )
{
    assert( _nodeIndex < _tree.m_nNodes );
    return _tree.m_pNodeLabels[ _nodeIndex ];
}

void TreeSetLabel ( Tree & _tree, int _nodeIndex, TreeNodeLabel _label )
{
    assert( _nodeIndex < _tree.m_nNodes );
    _tree.m_pNodeLabels[ _nodeIndex ] = _label;
}


int TreeGetParentIndex ( const Tree & _tree, int _nodeIndex )
{
    assert( _nodeIndex < _tree.m_nNodes );
    return _tree.m_pParentIndices[ _nodeIndex ];
}


void TreeSetParentIndex ( Tree & _tree, int _nodeIndex, int _parentIndex )
{
    assert( _nodeIndex < _tree.m_nNodes );
    assert( _parentIndex < _nodeIndex );

	//доюавляем родительский индекс
	_tree.m_pParentIndices[_nodeIndex] = _parentIndex;
	
	//создаем дочерний элемент
	Tree::ChildIndexElement * pNewElement = new Tree::ChildIndexElement;
	
	//присваиваем индек
	pNewElement->m_childIndex = _nodeIndex;
	pNewElement->m_pNext = nullptr;

	//присваиваем родителю дочерний элемент
	Tree::ChildIndexElement * pCurrent = _tree.m_pHeader[_parentIndex];
	
	if (!pCurrent)
	{
		_tree.m_pHeader[_parentIndex] = pNewElement;
		return;
	}


	while (pCurrent->m_pNext)
		pCurrent = pCurrent->m_pNext;

	pCurrent->m_pNext = pNewElement;
}



int TreeGetLeftmostChildIndex(const Tree & _tree, int _nodeIndex)//работает быстрее 
{
	assert(_nodeIndex < _tree.m_nNodes);

	//берем самый левый узел
	Tree::ChildIndexElement * pCurrent = _tree.m_pHeader[_nodeIndex];
	return pCurrent ? pCurrent->m_childIndex : -1;
}


int TreeGetRightSiblingIndex ( const Tree & _tree, int _nodeIndex )
{
    assert( _nodeIndex < _tree.m_nNodes );

    int parentIndex = TreeGetParentIndex( _tree, _nodeIndex );

	//берем правый соседний узел
    for ( int i = _nodeIndex + 1; i < _tree.m_nNodes; i++ )
        if ( _tree.m_pParentIndices[ i ] == parentIndex ) 
            return i;
    
    return -1;
}


void TreeDirectWalk ( const Tree & _tree, int _nodeIndex, TreeNodeVisitFunction _f )
{
    ( *_f )( _tree, _nodeIndex );

    int childIndex = TreeGetLeftmostChildIndex( _tree, _nodeIndex );
    while ( childIndex != -1 )
    {
        TreeDirectWalk( _tree, childIndex, _f );
        childIndex = TreeGetRightSiblingIndex( _tree, childIndex );
    }
}

void TreeReverseWalk ( const Tree & _tree, int _nodeIndex, TreeNodeVisitFunction _f )
{
    int childIndex = TreeGetLeftmostChildIndex( _tree, _nodeIndex );
    while ( childIndex != -1 )
    {
        TreeReverseWalk( _tree, childIndex, _f );
        childIndex = TreeGetRightSiblingIndex( _tree, childIndex );
    }

    ( *_f )( _tree, _nodeIndex );
}


void TreeSymmetricWalk ( const Tree & _tree, int _nodeIndex, TreeNodeVisitFunction _f )
{
    int childIndex = TreeGetLeftmostChildIndex( _tree, _nodeIndex );
    if ( childIndex != -1 )
        TreeSymmetricWalk( _tree, childIndex, _f );

    ( *_f )( _tree, _nodeIndex );

    if ( childIndex == -1 )
        return;

    while ( true )
    {
        childIndex = TreeGetRightSiblingIndex( _tree, childIndex );
        if ( childIndex == -1 )
            break;

        TreeSymmetricWalk( _tree, childIndex, _f );
    }
}


void TreeDirectWalk ( const Tree & _tree, TreeNodeVisitFunction _f )
{
    TreeDirectWalk( _tree, TreeGetRootIndex( _tree ), _f );
}


void TreeReverseWalk ( const Tree & _tree, TreeNodeVisitFunction _f )
{
    TreeReverseWalk( _tree, TreeGetRootIndex( _tree ), _f );
}

void TreeSymmetricWalk ( const Tree & _tree, TreeNodeVisitFunction _f )
{
    TreeSymmetricWalk( _tree, TreeGetRootIndex( _tree ), _f );
}