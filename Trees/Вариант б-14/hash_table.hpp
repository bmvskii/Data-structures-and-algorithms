#ifndef _HASH_TABLE_HPP_
#define _HASH_TABLE_HPP_

struct IntegerVector;

struct HashTable;

HashTable* HashTableCreate ( int _initialSize = 100 );

void HashTableDestroy ( HashTable* _pHT );

void HashTableClear ( HashTable & _ht );

int HashTableNumElements ( const HashTable & _ht );

void HashTableInsert ( HashTable & _ht, IntegerVector & _key);

bool HashTableHasKey ( const HashTable & _ht, IntegerVector & _key );

void HashTableRemoveKey ( HashTable & _ht, IntegerVector & _key );


#endif //  _HASH_TABLE_HPP_

