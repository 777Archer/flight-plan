/*David Archer
Flight Plan*/

#ifndef STACK_INTERFACE
#define STACK_INTERFACE

#include <iostream>
#include <string>

template <class ItemType>
class StackInterface 
{
	virtual bool isEmpty() const = 0;
	virtual bool push(const ItemType& newEntry) = 0;
	virtual bool pop() = 0;
	virtual ItemType peek() const = 0;
}; 
#endif
