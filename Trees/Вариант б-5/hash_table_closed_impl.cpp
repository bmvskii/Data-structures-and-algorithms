#define _CRT_SECURE_NO_WARNINGS

#include "hash_table.hpp"

#include <cassert>
#include <cstring>

struct HashTable
{
    struct Element
    {
        unsigned int m_key;
        char * m_value;
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

void HashTableDoubleSize(HashTable & _ht);

void HashTableDestroy ( HashTable* _pHT )
{
	for (int i = 0; i < _pHT->m_tableSize; i++)
		if (_pHT->m_pData[i].m_status == HashTable::Element::OCCUPIED)
			delete[] _pHT->m_pData[i].m_value;

    delete[] _pHT->m_pData;
    delete _pHT;
}

void HashTableClear ( HashTable & _ht )
{
    _ht.m_numOccupied   = 0;
	for (int i = 0; i < _ht.m_tableSize; i++)\
	{
		if (_ht.m_pData[i].m_status == HashTable::Element::OCCUPIED)
		{
			if (_ht.m_pData[i].m_value)
				delete[]_ht.m_pData[i].m_value;
			_ht.m_pData[i].m_status = HashTable::Element::NOT_OCCUPIED;
		}
	}
}

int HashTableNumElements ( const HashTable & _ht )
{
    return _ht.m_numOccupied;
}

unsigned int HashCode ( char * _key )
{
	//хэш-функция
	unsigned int hashCode = 0;
	for (; *_key; ++_key)
	{
		char c = *_key;
		hashCode = (hashCode << 5) + c;
	}
	return hashCode;
}

bool HashTableTryInsertElement ( HashTable & _ht, int _bucketNr, unsigned int _key, char * _value )
{
    if ( _ht.m_pData[ _bucketNr ].m_status != HashTable::Element::OCCUPIED )
    {
        _ht.m_pData[ _bucketNr ].m_status = HashTable::Element::OCCUPIED;
        _ht.m_pData[ _bucketNr ].m_key      = _key;

		//выделяем память под строку и копируем
        _ht.m_pData[ _bucketNr ].m_value  = new char[strlen(_value)+1];
		strcpy(_ht.m_pData[_bucketNr].m_value, _value);

        _ht.m_numOccupied++;
        return true;
    }
    else
        return false;
}

//внутренняя функция для увеличения размера
void insert(HashTable & _ht, unsigned int _key, char * _value)
{
	if ((_ht.m_numOccupied << 1) >= _ht.m_tableSize)
		HashTableDoubleSize(_ht);

	unsigned int hashCode = _key;
	int bucketNr = hashCode % _ht.m_tableSize;

	for (int i = bucketNr; i < _ht.m_tableSize; i++)
		if (HashTableTryInsertElement(_ht, i, _key, _value))
			return;

	for (int i = 0; i < bucketNr; i++)
		if (HashTableTryInsertElement(_ht, i, _key, _value))
			return;
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
		if (oldData[i].m_status == HashTable::Element::OCCUPIED){
			if ((_ht.m_numOccupied << 1) >= _ht.m_tableSize)
				HashTableDoubleSize(_ht);

			unsigned int hashCode = oldData[i].m_key;
			int bucketNr = hashCode % _ht.m_tableSize;

			for (int i = bucketNr; i < _ht.m_tableSize; i++)
				if (HashTableTryInsertElement(_ht, i, oldData[i].m_key, oldData[i].m_value))
					return;

			for (int i = 0; i < bucketNr; i++)
				if (HashTableTryInsertElement(_ht, i, oldData[i].m_key, oldData[i].m_value))
					return;

			insert(_ht, oldData[i].m_key, oldData[i].m_value);
		}

	for (int i = 0; i < oldSize; i++)
		if (oldData[i].m_status == HashTable::Element::OCCUPIED)
			delete[] oldData[i].m_value;
    delete[] oldData;
}

void HashTableInsert ( HashTable & _ht, char * _key, char * _value )
{
    if ( ( _ht.m_numOccupied << 1 ) >= _ht.m_tableSize )
        HashTableDoubleSize( _ht );

    unsigned int hashCode = HashCode( _key );
    int bucketNr = hashCode % _ht.m_tableSize;

    for ( int i = bucketNr; i < _ht.m_tableSize; i++ )
        if ( HashTableTryInsertElement( _ht, i, HashCode(_key), _value ) )
            return;

    for ( int i = 0; i < bucketNr; i++ )
        if ( HashTableTryInsertElement( _ht, i, HashCode(_key), _value ) )
            return;
}

const char * HashTableValue ( const HashTable & _ht, char * _key, char * _value)
{
    unsigned int hashCode = HashCode( _key );
    int bucketNr = hashCode % _ht.m_tableSize;

    for ( int i = bucketNr; i < _ht.m_tableSize; i++ )
        if ( _ht.m_pData[ i ].m_status == HashTable::Element::NOT_OCCUPIED )
            break;
        else if ( _ht.m_pData[ i ].m_status == HashTable::Element::OCCUPIED &&
				  _ht.m_pData[i].m_key == HashCode(_key) && !strcmp(_ht.m_pData[i].m_value,_value))
            return _ht.m_pData[ i ].m_value;

    for ( int i = 0; i < bucketNr; i++ )
        if ( _ht.m_pData[ i ].m_status == HashTable::Element::NOT_OCCUPIED )
            break;
        else if ( _ht.m_pData[ i ].m_status == HashTable::Element::OCCUPIED &&
                  _ht.m_pData[ i ].m_key == HashCode(_key) && !strcmp(_ht.m_pData[i].m_value, _value))
            return _ht.m_pData[ i ].m_value;

    return nullptr;
}

void HashTableRemoveKey ( HashTable & _ht, char * _key )
{
    unsigned int hashCode = HashCode( _key );
    int bucketNr = hashCode % _ht.m_tableSize;

    for ( int i = bucketNr; i < _ht.m_tableSize; i++ )
        if (_ht.m_pData[i].m_key == HashCode(_key))
        {
			delete[]_ht.m_pData[i].m_value;
            _ht.m_pData[ i ].m_status = HashTable::Element::DELETED;
            --_ht.m_numOccupied;
            return;
        }

    for ( int i = 0; i < bucketNr; i++ )
        if (_ht.m_pData[i].m_key == HashCode(_key))
        {
			delete[]_ht.m_pData[i].m_value;
            _ht.m_pData[ i ].m_status = HashTable::Element::DELETED;
            --_ht.m_numOccupied;
            return;
        }
}

