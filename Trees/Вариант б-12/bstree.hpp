#define _CRT_SECURE_NO_WARNINGS

#ifndef _BSTREE_HPP_
#define _BSTREE_HPP_

////////////////////////////////////////////////////////////////////////


struct BSTree
{
    struct Node
    {
        double m_key;
		char * m_value;

        Node * m_pParent;
        Node * m_pLeft;
        Node * m_pRight;
    };

    Node * m_pRoot;
};


///////////////////////////////////////////////////////////////////////


BSTree * BSTreeCreate ();


void BSTreeDestroy ( BSTree * _pTree );


void BSTreeInsertKey ( BSTree & _tree, double _key, const char * _value);


bool BSTreeHasKey ( const BSTree & _tree, double _key );

const char * BSTreeGetValue(const BSTree & _tree, double _key);

double BSTreeMinimum ( const BSTree & _tree );


double BSTreeMaximum ( const BSTree & _tree );


typedef void ( * BSTreeWalkFunction ) ( const BSTree::Node & _node );
void BSTreeSymmetricWalk ( const BSTree & _tree, BSTreeWalkFunction _f );


void BSTreeDeleteKey ( BSTree & _tree, double _key );


///////////////////////////////////////////////////////////////////////

#endif //  _BSTREE_HPP_
