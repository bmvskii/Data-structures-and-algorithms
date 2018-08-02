#ifndef _BSTREE_HPP_
#define _BSTREE_HPP_

////////////////////////////////////////////////////////////////////////


struct BSTree
{
    struct Node
    {
        char * m_key;
		int m_value;
        Node * m_pParent;
        Node * m_pLeft;
        Node * m_pRight;
    };

    Node * m_pRoot;
};


///////////////////////////////////////////////////////////////////////


BSTree * BSTreeCreate ();


void BSTreeDestroy ( BSTree * _pTree );


void BSTreeInsertKey ( BSTree & _tree, const char * _key, int _value);


bool BSTreeHasKey ( const BSTree & _tree, const char * _key );


BSTree::Node const * BSTreeMinimum ( const BSTree & _tree );


BSTree::Node const * BSTreeMaximum ( const BSTree & _tree );

int BSTreeGetValue(const BSTree & _tree, const char * _key);

typedef void ( * BSTreeWalkFunction ) ( const BSTree::Node & _node );
void BSTreeSymmetricWalk ( const BSTree & _tree, BSTreeWalkFunction _f );


void BSTreeDeleteKey ( BSTree & _tree, const char * _key );


///////////////////////////////////////////////////////////////////////

#endif //  _BSTREE_HPP_
