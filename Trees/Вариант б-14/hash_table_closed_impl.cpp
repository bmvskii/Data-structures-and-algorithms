#include "hash_table.hpp"
#include "integer_vector.hpp"
#include <cassert>

struct HashTable
{
    struct Element
    {
        IntegerVector m_key;
        enum { NOT_OCCUPIED, OCCUPIED, DELETED } m_status;
    };

    int m_tableSize;
    int m_numOccupied;
    Element* m_pData;
};


HashTable* HashTableCreate ( int _initialSize )
{
    HashTable * pNewHT = new HashTable;
        
    pNewHT->m_tableSize = _initialSize;
    pNewHT->m_pData     = new HashTable::Element[ pNewHT->m_tableSize ];

    HashTableClear( * pNewHT );

    return pNewHT;
}


void HashTableDestroy ( HashTable* _pHT )
{
	for (int i = 0; i < _pHT->m_tableSize; i++)
		if (_pHT->m_pData[i].m_status == HashTable::Element::OCCUPIED)
			IntegerVectorDestroy(_pHT->m_pData[i].m_key);

    delete[] _pHT->m_pData;
    delete _pHT;
}


void HashTableClear ( HashTable & _ht )
{
    _ht.m_numOccupied   = 0;
	for (int i = 0; i < _ht.m_tableSize; i++)
	{
		IntegerVectorClear(_ht.m_pData[i].m_key);
		_ht.m_pData[i].m_status = HashTable::Element::NOT_OCCUPIED;
	}
}


int HashTableNumElements ( const HashTable & _ht )
{
    return _ht.m_numOccupied;
}

unsigned int hash_combine(unsigned int prevHash, unsigned int newValueHash)
{
	return prevHash ^
		(newValueHash + 0x9e3779b9 + (prevHash << 6) + (prevHash >> 2));
}

unsigned int HashCode ( IntegerVector & _key )
{	
    unsigned int hashCode = 0;
	for (int i = 0; i < _key.m_nUsed; i++)
		hashCode += hash_combine(hashCode, _key.m_pData[i]);
    return hashCode;
}

void insertionSort(int* _pData, const int _N)
{
	for (int i = 1; i < _N; i++)
	{
		int j = i;
		while (j && (_pData[j] < _pData[j - 1]))
		{
			std::swap(_pData[j], _pData[j - 1]);
			--j;
		}
	}
}

bool HashTableTryInsertElement ( HashTable & _ht, int _bucketNr, IntegerVector & _key)
{
    if ( _ht.m_pData[ _bucketNr ].m_status != HashTable::Element::OCCUPIED )
    {
        _ht.m_pData[ _bucketNr ].m_status = HashTable::Element::OCCUPIED;
		IntegerVectorInit(_ht.m_pData[_bucketNr].m_key, _key.m_nAllocated);
		for (int i = 0; i < _key.m_nUsed; i++)
			IntegerVectorPushBack(_ht.m_pData[_bucketNr].m_key, _key.m_pData[i]);
        _ht.m_numOccupied++;
        return true;
    }
    else if ( IntegerVectorEquality(_ht.m_pData[ _bucketNr ].m_key, _key) )
		return true;
    else
        return false;
}


void HashTableDoubleSize ( HashTable & _ht )
{
    int oldSize = _ht.m_tableSize;
    _ht.m_tableSize <<= 1;

    HashTable::Element* oldData = _ht.m_pData;
    _ht.m_pData = new HashTable::Element[ _ht.m_tableSize ];
    for ( int i = 0; i < _ht.m_tableSize; i++ )
        _ht.m_pData[ i ].m_status = HashTable::Element::NOT_OCCUPIED;
    _ht.m_numOccupied = 0;

    for ( int i = 0; i < oldSize; i++ )
        if (  oldData[ i ].m_status == HashTable::Element::OCCUPIED  )
            HashTableInsert( _ht, oldData[ i ].m_key);

	for (int i = 0; i < oldSize; i++)
		if (oldData[i].m_status == HashTable::Element::OCCUPIED)
			IntegerVectorDestroy(oldData[i].m_key);
    delete[] oldData;
}


void HashTableInsert ( HashTable & _ht, IntegerVector & _key)
{
	insertionSort(_key.m_pData, _key.m_nUsed);
    
	if ( ( _ht.m_numOccupied << 1 ) >= _ht.m_tableSize )
        HashTableDoubleSize( _ht );

    unsigned int hashCode = HashCode( _key );
    int bucketNr = hashCode % _ht.m_tableSize;

    for ( int i = bucketNr; i < _ht.m_tableSize; i++ )
        if ( HashTableTryInsertElement( _ht, i, _key ))
            return;

    for ( int i = 0; i < bucketNr; i++ )
        if ( HashTableTryInsertElement( _ht, i, _key))
            return;
}


bool HashTableHasKey ( const HashTable & _ht, IntegerVector & _key )
{
    unsigned int hashCode = HashCode( _key );
    int bucketNr = hashCode % _ht.m_tableSize;

    for ( int i = bucketNr; i < _ht.m_tableSize; i++ )
        if ( _ht.m_pData[ i ].m_status == HashTable::Element::NOT_OCCUPIED )
            break;
        else if ( _ht.m_pData[ i ].m_status == HashTable::Element::OCCUPIED &&
				IntegerVectorEquality(_ht.m_pData[i].m_key, _key))
            return true;

	for (int i = 0; i < bucketNr; i++)
		if (_ht.m_pData[i].m_status == HashTable::Element::NOT_OCCUPIED)
			break;
		else if (_ht.m_pData[i].m_status == HashTable::Element::OCCUPIED &&
			IntegerVectorEquality(_ht.m_pData[i].m_key, _key))
			return true;

    return false;
}


void HashTableRemoveKey ( HashTable & _ht, IntegerVector & _key )
{
    unsigned int hashCode = HashCode( _key );
    int bucketNr = hashCode % _ht.m_tableSize;

    for ( int i = bucketNr; i < _ht.m_tableSize; i++ )
        if (IntegerVectorEquality(_ht.m_pData[i].m_key, _key))
        {
            _ht.m_pData[ i ].m_status = HashTable::Element::DELETED;
			IntegerVectorDestroy(_ht.m_pData[i].m_key);
            --_ht.m_numOccupied;
            return;
        }

    for ( int i = 0; i < bucketNr; i++ )
        if (IntegerVectorEquality(_ht.m_pData[i].m_key, _key))
        {
            _ht.m_pData[ i ].m_status = HashTable::Element::DELETED;
			IntegerVectorDestroy(_ht.m_pData[i].m_key);
            --_ht.m_numOccupied;
            return;
        }

 }

