#pragma once
#include "BTNode.h"
#include <list>
class CompositeNode : public BTNode
{
private:
	std::list<BTNode*> ChildList;
protected:
	std::list<BTNode*>& GetChildList() { return ChildList; }
public:
	void AddChild(BTNode* node)
	{
		ChildList.push_back(node);
	}
	virtual bool Run() override = 0 ;


	CompositeNode();
	virtual ~CompositeNode();
};

