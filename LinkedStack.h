/*David Archer
Flight Plan*/

#ifndef LINKED_STACK
#define LINKED_INTERFACE

#include "Node.h"
#include "StackInterface.h"

template<class ItemType>
class LinkedStack : public StackInterface<ItemType> 
{
private:
    Node<ItemType>* topPtr;

public:
    LinkedStack();
    LinkedStack(const LinkedStack<ItemType>& aStack);
    virtual ~LinkedStack();

    bool isEmpty() const;
    bool push(const ItemType& newItem);
    bool pop();
    ItemType peek() const;
};
#endif

template < class ItemType>
LinkedStack<ItemType>::LinkedStack() : topPtr(nullptr) {}

template<class ItemType>
LinkedStack<ItemType>::LinkedStack(const LinkedStack<ItemType>& aStack) 
{
    Node<ItemType>* origChainPtr = aStack.topPtr;

    if (origChainPtr == nullptr)
        topPtr = nullptr;
    else {
        topPtr = new Node<ItemType>();
        topPtr->setItem(origChainPtr->getItem());

        Node<ItemType>* newChainPtr = topPtr;

        while (origChainPtr != nullptr) 
        {
            origChainPtr = origChainPtr->getNext();
            ItemType nextItem = origChainPtr->getItem();

            Node<ItemType>* newNodePtr = new Node<ItemType>(nextItem);

            newChainPtr->setNext(newNodePtr);
            newChainPtr = newChainPtr->getNext();
        }
        newChainPtr->setNext(nullptr);
    }
}

template<class ItemType>
LinkedStack<ItemType>::~LinkedStack() 
{
    while (!isEmpty())
        pop();
}

template<class ItemType>
bool LinkedStack <ItemType>::isEmpty() const
{
    return topPtr == nullptr;
}

template<class ItemType>
bool LinkedStack<ItemType>::push(const ItemType& newItem) 
{
    Node<ItemType>* newNodePtr = new Node<ItemType>(newItem, topPtr);
    topPtr = newNodePtr;
    newNodePtr = nullptr;

    return true;
}

template<class ItemType>
bool LinkedStack<ItemType>::pop() 
{
    bool result = false;
    if (!isEmpty()) 
    {
        Node<ItemType>* nodeToDeletePtr = topPtr;
        topPtr = topPtr->getNext();

        nodeToDeletePtr->setNext(nullptr);
        delete nodeToDeletePtr;
        nodeToDeletePtr = nullptr;

        result = true;
    }

    return result;
}

template<class ItemType>
ItemType LinkedStack<ItemType>::peek() const 
{
    return topPtr->getItem();
}