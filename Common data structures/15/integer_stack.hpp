#ifndef _INTEGER_STACK_HPP_
#define _INTEGER_STACK_HPP_

#include <iostream>

struct IntegerDroppingStack;

IntegerDroppingStack * IntegerDroppingStackCreate ();

IntegerDroppingStack * IntegerDroppingStackCreate ( int _fixedSize );

void IntegerDroppingStackDestroy ( IntegerDroppingStack * _pStack );

void IntegerDroppingStackClear ( IntegerDroppingStack & _stack );

bool IntegerDroppingStackIsEmpty ( const IntegerDroppingStack & _stack );

bool IntegerDroppingStackIsFull ( const IntegerDroppingStack & _stack );

void IntegerDroppingStackPush ( IntegerDroppingStack & _stack, int _value );

void IntegerDroppingStackPop ( IntegerDroppingStack & _stack );

int IntegerDroppingStackTop ( const IntegerDroppingStack & _stack );


#endif //  _INTEGER_STACK_HPP_