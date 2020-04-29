#include "JQueue.h"


namespace JQ
{
	void JQueue::push(int data)
	{
		Node* newNode = new Node();
		newNode->Data = data;

		if (Top == nullptr)
		{
			Top = newNode;
		}
		else
		{

			Node* curr = Top;
			while (curr->pNext != nullptr)
			{
				curr = curr->pNext;
			}
			curr->pNext = newNode;
		}
	}
	Node * JQueue::pop()
	{
		Node* retNode = Top;

		Top = Top->pNext;

		return retNode;
	}
	JQueue::JQueue()
	{
		Top = nullptr;
	}


	JQueue::~JQueue()
	{
	}
}
