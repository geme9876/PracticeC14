#pragma once
#include "CompositeNode.h"
class Sequence : public CompositeNode
{
public:
	bool Run() override
	{
		for (auto& node : GetChildList())
		{
			if (!node->Run())
				return false;
		}
		return true;
	};


	Sequence();
	virtual ~Sequence();
};

