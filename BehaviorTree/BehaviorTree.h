#pragma once
#include <list>
#include "Selector.h"
#include "Sequence.h"
class BehaviorTree
{
private:
	CompositeNode* Root;
public:
	inline bool BTRun() { Root->Run(); }
	


	BehaviorTree();
	~BehaviorTree();
};

