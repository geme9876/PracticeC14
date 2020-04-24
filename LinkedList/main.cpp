#include "SingleLinkedList.h"
#include "DoubleLinkedList.h"
#include <iostream>



int main()
{
	SingleLinkedList<int> LinkedList;


	Node<int>* List = nullptr;

	for (int i = 0; i < 5; i++)
	{
		LinkedList.ApeendNode(&List, LinkedList.CreateNode(i));
	}
	int size = LinkedList.Size(List);

	for (int i = 0; i < size; i++)
	{
		Node<int>* Current = LinkedList.GetNodeAt(List, 0);
		if (Current != nullptr)
		{
			std::cout << Current->data << std::endl;
			LinkedList.RemoveNode(&List, Current);
			LinkedList.DestroyNode(Current);
		}
	}

	DoubleLinkedList<int> DoubleLinked;
	DoubleLinked.Insert(0, 100);
	for (int i = 0; i < 10; i++)
	{
		DoubleLinked.Insert(i);
	}
	std::cout << DoubleLinked[2]->data << std::endl;

	DoubleLinked.Remove(DoubleLinked[2]);
	DoubleLinked.Clear();


	return 0;

}