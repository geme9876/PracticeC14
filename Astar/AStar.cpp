#include "AStar.h"
#include <algorithm>
#include <iostream>
namespace PathFinding
{
	bool AStar::DetectCollision(const Pos & pos)
	{
		if (pos.x < 0 || pos.x >= mWorldSize.x
			|| pos.y < 0 || pos.y >= mWorldSize.y
			|| (*World)[pos.x][pos.y] ==  1 )
		{
			return true;
		}
		return false;

	}
	std::vector<Pos>& AStar::FindPath(const Pos& src, const Pos& dest)
	{
		Node* current = nullptr;
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
			if (current->pos == dest)
			{
				break;
			}
			closeSet.insert(current);
			openSet.erase(openSet.find(current));
			
			for (int i = 0; i < mDiagonalMovement; ++i)
			{
				Pos NewPos(current->pos + mDirection[i]);
				if (DetectCollision(NewPos)) 
				{ 
					continue; 
				}
				auto checkClose = std::find_if(closeSet.begin(), closeSet.end(),
					[&](const Node* node)->bool { return NewPos == node->pos; });
				if (checkClose != closeSet.end())
				{
					continue;
				}

				Node* newNode = nullptr;
				int TotalCost = current->G + (mDiagonalMovement < 4 ? 10 : 14);

				auto checkOpen = std::find_if(openSet.begin(), openSet.end(),
					[&](const Node* node)->bool { return NewPos == node->pos; });
				if (checkOpen == openSet.end())
				{
					newNode = new Node(NewPos, current);
					newNode->G = TotalCost;
					newNode->H = mHeuris(newNode->pos, dest);
					openSet.insert(newNode);
				}
				else if (TotalCost < (*checkOpen)->G)
				{
					(*checkOpen)->Parent = current;
					(*checkOpen)->G = TotalCost;
				}
			}

		}


		std::vector<Pos> path;
		while (current != nullptr)
		{
			path.push_back(current->pos);
			current = current->Parent;
		}

		for (auto& node : openSet)
		{
			delete node;
		}
		openSet.clear();

		for (auto& node : closeSet)
		{
			delete node;
		}
		closeSet.clear();


		for (int i=0; i<World->size(); i++)
		{
			for(int j =0; j< (*World)[i].size();j++)
			{
				auto  iter = std::find(path.begin(), path.end(), Pos(i, j));
				if (iter != path.end())
				{
					std::cout << "£ª" ;
				}
				else if ((*World)[i][j] == 0)
				{
					std::cout << "¡Û";
				}
				else if ((*World)[i][j] == 1)
				{
					std::cout << "¡á" ;
				}

			}
			std::cout << std::endl;
		}

		return path;
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
		SetDiagonalMovement(true);
		SetHeurisFunc(&Heuristic::manhattan);
	}


	AStar::~AStar()
	{
	}




	Position::Position() : x(0), y(0)
	{
	}

	Position::Position(const Position & src) : x(src.x), y(src.y)
	{
	}

	Position::Position(Position && src) : x(src.x), y(src.y)
	{
	}

	Position & Position::operator=(const Position & src)
	{
		if (this == &src)
		{
			return *this;
		}
		x = src.x;
		y = src.y;
		return *this;
	}

	Position & Position::operator=(Position && src)
	{
		if (this == &src)
		{
			return *this;
		}
		x = src.x;
		y = src.y;
		return *this;
	}

	bool Position::operator==(const Position & src)
	{
		return (x == src.x) && (y == src.y);
	}

	bool Position::operator!=(const Position & src)
	{
		return !(*this == src);
	}

	Position Position::operator+(const Position & lhs)
	{
		return Pos(x + lhs.x, y + lhs.y);
	}

	Pos Heuristic::GetDelta(const Pos & src, const Pos & dest)
	{
		return Pos(abs(src.x - dest.x), abs(src.y - dest.y));
	}

	int Heuristic::manhattan(const Pos & src, const Pos & dest)
	{
		auto delta = GetDelta(src, dest);
		return 10 * (delta.x + delta.y);
	}

	int Heuristic::euclidean(const Pos & src, const Pos & dest)
	{
		Pos&& delta = std::move(GetDelta(src, dest));
		return 10 * sqrt(pow(delta.x,2)+pow(delta.y,2));
	}

	int Heuristic::octagonal(const Pos & src, const Pos & dest)
	{
		auto delta = std::move(GetDelta(src, dest));
		return 10 * (delta.x+delta.y) + (-6) * __min(delta.x,delta.y);
	}

	int Heuristic::chebyshev(const Pos & src, const Pos & dest)
	{
		auto delta = std::move(GetDelta(src, dest));
		return __max(delta.x, delta.y);
	}

}