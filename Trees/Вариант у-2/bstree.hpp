#ifndef _BSTREE_HPP_
#define _BSTREE_HPP_

////////////////////////////////////////////////////////////////////////

#include <iostream>

struct Student
{
	char * m_lastName;
	int m_mark;
};

struct BSTree
{
    struct Node
    {
		Student m_key;

        Node * m_pParent;
        Node * m_pLeft;
        Node * m_pRight;
    };

    Node * m_pRoot;
};


///////////////////////////////////////////////////////////////////////


BSTree * BSTreeCreate();


void BSTreeDestroy ( BSTree * _pTree );


void BSTreeInsertKey ( BSTree & _tree, Student _key );


bool BSTreeHasKey ( const BSTree & _tree, Student _key );


Student BSTreeMinimum ( const BSTree & _tree );


Student BSTreeMaximum ( const BSTree & _tree );


typedef void ( * BSTreeWalkFunction ) ( const BSTree::Node & _node, std::ostream & _stream);
void BSTreeSymmetricWalk ( const BSTree & _tree, BSTreeWalkFunction _f,std::ostream & _stream);


void BSTreeDeleteKey ( BSTree & _tree, Student _key );


///////////////////////////////////////////////////////////////////////

#endif //  _BSTREE_HPP_
