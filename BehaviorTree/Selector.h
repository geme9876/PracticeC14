#pragma once
#include "CompositeNode.h"
class Selector : public CompositeNode
{
public:
	bool Run() override
	{
		for (auto& node : GetChildList())
		{
			if (node->Run())
				return true;
		}
		return false;
	};
	
	Selector();
	virtual ~Selector();
};

