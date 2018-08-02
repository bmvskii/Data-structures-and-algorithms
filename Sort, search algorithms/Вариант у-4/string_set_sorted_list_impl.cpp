#define _CRT_SECURE_NO_WARNINGS

#include "string_set.hpp"
#include "string_list.hpp"

#include <cassert>
#include <cstring>

struct StringSet
{
    StringList m_data;
};


StringSet * StringSetCreate ()
{
    StringSet * pSet = new StringSet;
    StringListInit( pSet->m_data );
    return pSet;
}


void StringSetDestroy ( StringSet * _pSet )
{
    StringListDestroy( _pSet->m_data );
    delete _pSet;
}


void StringSetClear ( StringSet & _set )
{
    StringListClear( _set.m_data );
}


bool StringSetIsEmpty ( const StringSet & _set )
{
    return StringListIsEmpty( _set.m_data );
}


int StringSetSize ( const StringSet & _set )
{
    return StringListSize( _set.m_data );
}


bool StringSetHasKey ( const StringSet & _set, const char * _key )
{
    StringList::Node * pNode = _set.m_data.m_pFirst;
    while ( pNode )
    {
        if ( !strcmp(pNode->m_value, _key) )
            return true;
        else if ( strcmp(pNode->m_value,_key) > 0 )
            return false;
        pNode = pNode->m_pNext;
    }
    return false;
}


void StringSetInsertKey ( StringSet & _set, const char * _key )
{
    if ( StringListIsEmpty( _set.m_data ) )
        StringListPushBack( _set.m_data, _key );

    else
    {
        StringList::Node * pNode = _set.m_data.m_pFirst;
        if (strcmp(_key, pNode->m_value) < 0 )
            StringListPushFront( _set.m_data, _key );

        else
        {
            StringList::Node * pPrevNode = nullptr;
            while ( pNode )
            {
                if ( !strcmp(pNode->m_value,_key ))
                    return;

                else if ( ! pNode->m_pNext  )
                {
                    StringListPushBack( _set.m_data, _key );
                    return;
                }

                else if ( strcmp(pNode->m_pNext->m_value, _key) > 0 )
                {
                    StringListInsertAfter( _set.m_data, pNode, _key );
                    return;
                }

                else
                    pNode = pNode->m_pNext;
            }

            assert( ! "We should never get here" );
        }
    }
}


void StringSetDeleteKey ( StringSet & _set, const char * _key )
{
    StringList::Node * pNode = _set.m_data.m_pFirst;
    while ( pNode )
    {
        if (!strcmp(pNode->m_value, _key ))
        {
            StringListDeleteNode( _set.m_data, pNode );
            return;
        }
        else if (strcmp(pNode->m_value, _key) > 0 )
            break;

        pNode = pNode->m_pNext;
    }

    assert( !"Key is unavailble!" );
}


void StringSetInsertAllKeys ( const StringSet & _sourceSet, StringSet & _targetSet )
{
    StringList::Node * pNode = _sourceSet.m_data.m_pFirst;
    while ( pNode )
    {
        StringSetInsertKey( _targetSet, pNode->m_value );
        pNode = pNode->m_pNext;
    }
}


void StringSetUnite ( const StringSet & _set1,
                       const StringSet & _set2,
                       StringSet & _targetSet )
{
    StringSetClear( _targetSet );

    StringList::Node * pNode1 = _set1.m_data.m_pFirst;
    StringList::Node * pNode2 = _set2.m_data.m_pFirst;
    while ( pNode1 || pNode2 )
    {
        if ( pNode1 && pNode2 )
        {
            if (strcmp(pNode1->m_value , pNode2->m_value) < 0 )
            {
                StringListPushBack( _targetSet.m_data, pNode1->m_value );
                pNode1 = pNode1->m_pNext;
            }
            else if ( strcmp(pNode1->m_value, pNode2->m_value )>0)
            {
                StringListPushBack( _targetSet.m_data, pNode2->m_value );
                pNode2 = pNode2->m_pNext;
            }
            else
            {
                StringListPushBack( _targetSet.m_data, pNode1->m_value );
                pNode1 = pNode1->m_pNext;
                pNode2 = pNode2->m_pNext;
            }
        }
        else if ( pNode1 )
        {
            StringListPushBack( _targetSet.m_data, pNode1->m_value );
            pNode1 = pNode1->m_pNext;
        }
        else
        {
            StringListPushBack( _targetSet.m_data, pNode2->m_value );
            pNode2 = pNode2->m_pNext;
        }
    }
}


void StringSetIntersect ( const StringSet & _set1,
                           const StringSet & _set2,
                           StringSet & _targetSet )
{
    StringSetClear( _targetSet );

    StringList::Node * pNode1 = _set1.m_data.m_pFirst;
    StringList::Node * pNode2 = _set2.m_data.m_pFirst;
    while ( pNode1 && pNode2 )
    {
        if ( !strcmp(pNode1->m_value , pNode2->m_value))
		{
            StringListPushBack( _targetSet.m_data, pNode1->m_value );
			pNode1 = pNode1->m_pNext;
			pNode2 = pNode2->m_pNext;
		}

        else if ( strcmp(pNode1->m_value , pNode2->m_value) < 0 )
            pNode1 = pNode1->m_pNext;

        else
            pNode2 = pNode2->m_pNext;
    }
}


void StringSetDifference ( const StringSet & _set1,
                            const StringSet & _set2,
                            StringSet & _targetSet )
{
    StringSetClear( _targetSet );

    StringList::Node * pNode1 = _set1.m_data.m_pFirst;
    StringList::Node * pNode2 = _set2.m_data.m_pFirst;
    while ( pNode1 )
    {
        if ( pNode2 )
        {
            if (!strcmp( pNode1->m_value, pNode2->m_value) )
            {
                pNode1 = pNode1->m_pNext;
                pNode2 = pNode2->m_pNext;
            }
            else if ( strcmp(pNode1->m_value ,pNode2->m_value) < 0 )
            {
                StringListPushBack( _targetSet.m_data, pNode1->m_value );
                pNode1 = pNode1->m_pNext;
            }
            else
                pNode2 = pNode2->m_pNext;
        }
        else
        {
            StringListPushBack( _targetSet.m_data, pNode1->m_value );
            pNode1 = pNode1->m_pNext;
        }
    }
}

