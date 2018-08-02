#ifndef _STRING_STACK_HPP_
#define _STRING_STACK_HPP_

#include <iostream>

struct StringStack;

StringStack * StringStackCreate();

StringStack * StringStackCreate(int _fixedSize);

void StringStackDestroy(StringStack * _pStack);

void StringStackClear(StringStack & _stack);

bool StringStackIsEmpty(const StringStack & _stack);

bool StringStackIsFull(const StringStack & _stack);

void StringStackPush(StringStack & _stack, const char * _value);

void StringStackPop(StringStack & _stack);

const char * StringStackTop(const StringStack & _stack);


#endif //  _STRING_STACK_HPP_