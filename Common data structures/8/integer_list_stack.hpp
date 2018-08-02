#ifndef _INTEGER_STACK_HPP_
#define _INTEGER_STACK_HPP_

#include <iostream>

struct IntegerList;
struct IntegerListStack;

IntegerListStack * IntegerListStackCreate(int _fixedSize = 10);

void IntegerListStackDestroy(IntegerListStack * _pStack);

void IntegerListStackPush(IntegerListStack & _stack, IntegerList _value);

void IntegerListStackPop(IntegerListStack & _stack);

void IntegerListStackClear(IntegerListStack & _stack);

bool IntegerListStackIsFull(const IntegerListStack & _stack);

bool IntegerListStackIsEmpty(const IntegerListStack & _stack);

IntegerList IntegerListStackTop(const IntegerListStack & _stack);

#endif //  _INTEGER_STACK_HPP_