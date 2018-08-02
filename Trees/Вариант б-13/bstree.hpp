#ifndef _BSTREE_HPP_
#define _BSTREE_HPP_

////////////////////////////////////////////////////////////////////////

#include "integer_vector.hpp"

struct BSTree
{
    struct Node
    {
        IntegerVector m_key;

        Node * m_pParent;
        Node * m_pLeft;
        Node * m_pRight;
    };

    Node * m_pRoot;
};


///////////////////////////////////////////////////////////////////////


BSTree * BSTreeCreate ();


void BSTreeDestroy ( BSTree * _pTree );


void BSTreeInsertKey ( BSTree & _tree, IntegerVector & _key );


bool BSTreeHasKey ( const BSTree & _tree, const IntegerVector & _key );


IntegerVector & BSTreeMinimum ( const BSTree & _tree );


IntegerVector & BSTreeMaximum ( const BSTree & _tree );


typedef void ( * BSTreeWalkFunction ) ( const BSTree::Node & _node );
void BSTreeSymmetricWalk ( const BSTree & _tree, BSTreeWalkFunction _f );


void BSTreeDeleteKey ( BSTree & _tree, const IntegerVector & _key );


///////////////////////////////////////////////////////////////////////

#endif //  _BSTREE_HPP_
