#include "JStack.h"
#include "JQueue.h"
#include <iostream>



int main()
{
	JStack t;

	for (int i = 0; i < 10; i++)
	{
		t.push(i);
		std::cout << i;
	}
	std::cout <<std::endl;

	for (int i = 0; i < 10; i++)
	{
		StackNode* popNode = t.pop();
		std::cout << popNode->data;
		delete popNode;
	}
	std::cout << std::endl;


	JQ::JQueue q;

	for (int i = 0; i < 10; i++)
	{
		q.push(i);
		std::cout << i;
	}
	std::cout << std::endl;


	for (int i = 0; i < 10; i++)
	{
		JQ::Node* popNode = q.pop();
		std::cout << popNode->Data;
		delete popNode;
	}

	std::cout << std::endl;


	return 0;

}