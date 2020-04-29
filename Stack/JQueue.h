#pragma once

namespace JQ
{

	typedef struct QueueNode
	{
		int Data;
		QueueNode* pNext;
	}Node;


	class JQueue
	{
	public:
		Node* Top;
		Node* Back;

		void push(int data);
		Node* pop();

		JQueue();
		~JQueue();
	};

}