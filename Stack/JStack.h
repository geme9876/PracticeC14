#pragma once


typedef struct StackNode
{
	int data;
	StackNode* pNext;
	StackNode(int InData) : data(InData) {};
}Node;


class JStack
{
public:
	StackNode* Top;

	void push(int data);
	StackNode*  pop();


	JStack() {};
	~JStack() {};
};

