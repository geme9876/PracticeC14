#pragma once
#include "BTNode.h"
class TaskNode : public BTNode
{
public:
	bool Run() override = 0;
	TaskNode();
	virtual ~TaskNode();
};

