#ifndef _INTEGER_SET_HPP_
#define _INTEGER_SET_HPP_

struct IntegerSet;

IntegerSet * IntegerSetCreate ();

void IntegerSetDestroy ( IntegerSet * _pSet );

void IntegerSetClear ( IntegerSet & _set );

bool IntegerSetIsEmpty ( const IntegerSet & _set );

bool IntegerSetHasKey ( const IntegerSet & _set, int _key );

void IntegerSetInsertKey ( IntegerSet & _set, int _key );

void IntegerSetDeleteKey ( IntegerSet & _set, int _key );

void IntegerSetUnite ( const IntegerSet & _set1,
                       const IntegerSet & _set2,
                       IntegerSet & _targetSet );

void IntegerSetIntersect ( const IntegerSet & _set1,
                           const IntegerSet & _set2,
                           IntegerSet & _targetSet );

void IntegerSetDifference ( const IntegerSet & _set1,
                            const IntegerSet & _set2,
                            IntegerSet & _targetSet );
 
bool IntegerSetIsSubset(const IntegerSet & _mainset, const IntegerSet & _subset);

bool IntegerSetIsEqual(const IntegerSet & _set1, const IntegerSet & _set2);

int IntegerSetMinKey(const IntegerSet & _set);

int IntegerSetMaxKey(const IntegerSet & _set);

#endif //  _INTEGER_SET_HPP_
