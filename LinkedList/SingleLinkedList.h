#pragma once

template<typename T>
class Node
{
public:
	T data;
	Node<T>* pNext;

	Node() {};
	~Node() {};
};


template<typename T>
class SingleLinkedList
{
public:

	Node<T>* CreateNode(T NewData);
	void DestroyNode(Node<T>* Node);
	void ApeendNode(Node<T>** Head, Node<T>* Node);
	void InsertAfter(Node<T>* Current, Node<T>* NewNode);
	void InsertHead(Node<T>** Head, Node<T>* NewHead);
	void RemoveNode(Node<T>** Head, Node<T>* Remove);
	Node<T>* GetNodeAt(Node<T>* Head, int Location);
	int Size(Node<T>* Head);


	SingleLinkedList() {};
	SingleLinkedList(const SingleLinkedList& src) = delete;
	SingleLinkedList(SingleLinkedList&& src) = delete;
	SingleLinkedList& operator=(const SingleLinkedList& src) = delete;
	SingleLinkedList& operator=(SingleLinkedList&& src) = delete;

	~SingleLinkedList() {};
};

template<typename T>
inline Node<T>* SingleLinkedList<T>::CreateNode(T NewData)
{
	Node<T>* NewNode = new Node<T>();
	NewNode->data = NewData;
	NewNode->pNext = nullptr;
	return NewNode;
}

template<typename T>
inline void SingleLinkedList<T>::DestroyNode(Node<T>* Node)
{
	delete Node;
}

template<typename T>
inline void SingleLinkedList<T>::ApeendNode(Node<T>** Head, Node<T>* newNode)
{
	if ((*Head) == nullptr)
	{
		*Head = newNode;
	}
	else
	{
		Node<T>* Tail = (*Head);
		while (Tail->pNext != nullptr)
		{
			Tail = Tail->pNext;
		}
		Tail->pNext = newNode;
	}
}

template<typename T>
inline void SingleLinkedList<T>::InsertAfter(Node<T>* Current, Node<T>* NewNode)
{
	NewNode->pNext = Current->pNext;
	Current->pNext = NewNode;
}

template<typename T>
inline void SingleLinkedList<T>::InsertHead(Node<T>** Head, Node<T>* NewHead)
{
	if (*Head == nullptr)
	{
		(*Head) = NewHead;
	}
	else
	{
		NewHead->pNext = (*Head);
		(*Head) = NewHead;
	}
}

template<typename T>
inline void SingleLinkedList<T>::RemoveNode(Node<T>** Head, Node<T>* Remove)
{
	if (*Head == Remove)
	{
		*Head = Remove->pNext;
	}
	else
	{
		Node<T>* Current = *Head;
		while (Current != nullptr && Current->pNext != Remove)
		{
			Current = Current->pNext;
		}
		if (Current != nullptr)
			Current->pNext = Remove->pNext;

	}
}

template<typename T>
inline Node<T>* SingleLinkedList<T>::GetNodeAt(Node<T>* Head, int Location)
{
	Node<T>* Current = Head;
	while (Current != nullptr && (--Location) >= 0)
	{
		Current = Current->pNext;
	}
	return Current;
}

template<typename T>
inline int SingleLinkedList<T>::Size(Node<T>* Head)
{
	int Count(0); 
	Node<T>* Current = Head;
	while (Current != nullptr)
	{
		Current = Current->pNext;
		Count++;
	}
	return Count;
}
