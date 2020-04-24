#pragma once
#include <stdexcept>
template<typename T>
class DoubleNode
{
public:
	T data;
	DoubleNode<T>* pPrev;
	DoubleNode<T>* pNext;

	DoubleNode() : pPrev(nullptr), pNext(nullptr) {};
	DoubleNode(T inData) : data(inData),pPrev(nullptr),pNext(nullptr) {};
	DoubleNode(const DoubleNode& src) = delete;
	DoubleNode(DoubleNode&& src) = delete;
	~DoubleNode() {};
};


template <typename T>
class DoubleLinkedList
{
public:
	DoubleLinkedList():Head(nullptr), Tail(nullptr) 
	{
		Tail = new DoubleNode<T>();
		Head = Tail;
	};
	DoubleLinkedList(const DoubleLinkedList& src)= delete;
	DoubleLinkedList(DoubleLinkedList&& src) = delete;
	~DoubleLinkedList() {};
public:
	void			Insert(T Data);
	void			Insert(DoubleNode<T>* pNode, T Data);
	void			Insert(int index, T Data);
	void			Remove(DoubleNode<T>* pNode);
	void			Clear();
	size_t			Size() { return size; };
	DoubleNode<T>*	Find(T data);
	DoubleNode<T>*	operator[](int index);

private:
	DoubleNode<T>* Head;
	DoubleNode<T>* Tail;
	size_t size=0;


};

template<typename T>
inline void DoubleLinkedList<T>::Insert(T Data)
{
	DoubleNode<T>* newNode = new DoubleNode<T>(Data);
	if (Head == Tail)
	{
		Head = newNode;
		Head->pNext = Tail;
		Tail->pPrev = Head;
	}
	else
	{
		newNode->pPrev = Tail->pPrev;
		newNode->pNext = Tail;
		Tail->pPrev->pNext = newNode;
		Tail->pPrev = newNode;
	}
	size++;

}

template<typename T>
inline void DoubleLinkedList<T>::Insert(DoubleNode<T>* pNode, T Data)
{
}

template<typename T>
inline void DoubleLinkedList<T>::Insert(int index, T Data)
{
	DoubleNode<T>*  FindNode = this->operator[](index);
	DoubleNode<T>*	newNode = new DoubleNode<T>(Data);
	if (FindNode != Tail)
	{
		newNode->pNext = FindNode->pNext;
		newNode->pPrev = FindNode;
		FindNode->pNext->pPrev = newNode;
		FindNode->pNext = newNode;
	}
	else
	{
		Tail->pPrev = newNode;
		Head = newNode;
		Head->pNext = Tail;
		
	}
}

template<typename T>
inline void DoubleLinkedList<T>::Remove(DoubleNode<T>* pNode)
{
	if (pNode == Head)
	{
		Head = pNode->pNext;
		Head->pPrev = nullptr;
		if (Head != Tail)
		{
			Head->pNext->pPrev = Head;
		}
	}
	else if (pNode != nullptr && pNode != Tail)
	{
		DoubleNode<T>* PrevNode = pNode->pPrev;
		DoubleNode<T>* NextNode = pNode->pNext;
		PrevNode->pNext = NextNode;
		NextNode->pPrev = PrevNode;
	}
	--size;
	delete pNode;
}

template<typename T>
inline void DoubleLinkedList<T>::Clear()
{
	while (size)
	{
		Remove(Head);
	}
}

template<typename T>
inline DoubleNode<T>* DoubleLinkedList<T>::Find(T data)
{
	DoubleNode<T>* Current = Head;
	while (Current != Tail && Current != nullptr)
	{
		if (Current->data == data)
		{
			return Current;
		}
		Current = Current->pNext;
	}
	return Current;

}

template<typename T>
inline DoubleNode<T>* DoubleLinkedList<T>::operator[](int index)
{
	if (index >= size)
	{
		throw std::out_of_range("Out of List Range");
	}
	DoubleNode<T>* Current = Head;
	while (Current != nullptr && --index >= 0)
	{
		Current = Current->pNext;
	}
	return Current;
}
