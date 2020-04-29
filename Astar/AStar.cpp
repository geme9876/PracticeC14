#include "AStar.h"


Position AStar::FindPath(Position & src, Position & target)
{
	Node * current = nullptr;
	std::set<Node*> openSet, closeSet;

	openSet.insert(new Node(src));

	while (!openSet.empty())
	{
		current = *openSet.begin();
		for (auto node : openSet)
		{
			if (node->GetScore() <= current->GetScore())
			{
				current = node;
			}
		}

	}

}

AStar::AStar()
{
	mDirection = {
		Position(0, 1) ,
		Position(1, 0) ,
		Position(0, -1) ,
		Position(-1, 0) ,
		Position(-1, -1) ,
		Position(1, 1) ,
		Position(-1, 1) ,
		Position(1, -1) ,
	};

	SetHuris(&Heuristic::manhattan);
	SetDiaMovement(true);
}


AStar::~AStar()
{
}

Position Heuristic::getDelta(Position & source, Position & target)
{
	return { abs(source.x - target.x), abs(source.y - target.y) };
}

uint Heuristic::manhattan(Position & source, Position & target)
{
	return uint();
}

uint Heuristic::euclidean(Position & source, Position & target)
{
	return uint();
}

uint Heuristic::octagonal(Position & source, Position & target)
{
	return uint();
}
