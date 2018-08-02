#ifndef _INTEGER_SET_HPP_
#define _INTEGER_SET_HPP_

struct StringSet;


StringSet * StringSetCreate ();

void StringSetDestroy ( StringSet * _pSet );

void StringSetClear ( StringSet & _set );

bool StringSetIsEmpty ( const StringSet & _set );

bool StringSetHasKey ( const StringSet & _set, const char * _key );

void StringSetInsertKey ( StringSet & _set, const char * _key );

void StringSetDeleteKey ( StringSet & _set, const char * _key );

void StringSetUnite ( const StringSet & _set1,
                       const StringSet & _set2,
                       StringSet & _targetSet );

void StringSetIntersect ( const StringSet & _set1,
                           const StringSet & _set2,
                           StringSet & _targetSet );

void StringSetDifference ( const StringSet & _set1,
                            const StringSet & _set2,
                            StringSet & _targetSet );
 

#endif //  _INTEGER_SET_HPP_
