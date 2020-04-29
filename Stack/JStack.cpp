#include "JStack.h"

void JStack::push(int data)
{
	StackNode* newNode = new StackNode(data);
	
	newNode->pNext = Top;
	Top = newNode;
}

StackNode* JStack::pop()
{
	StackNode* retNode = Top;
	Top = Top->pNext;

	return retNode;
}
