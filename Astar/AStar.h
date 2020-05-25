#pragma once
#include <set>
#include <functional>
#include <vector>
#include <array>
namespace PathFinding
{
	typedef struct Position
	{
		int x, y;

		Position();
		Position(int x, int y) : x(x), y(y) {}
		Position(const Position& src);
		Position(Position&& src);
		Position& operator=(const Position& src);
		Position& operator=(Position&& src);

		bool operator==(const Position& src);
		bool operator!=(const Position& src);
		Position operator+(const Position& lhs);
	}Pos;


	typedef struct AStarNode
	{
		Pos pos;
		// G = 시작점부터 현재 Pos까지의 비용
		// H = 현재 Pos에서 목적지까지의 비용
		int G, H;
		AStarNode* Parent;
		int GetScore() { return G + H; }
		AStarNode(const Pos& newPos, AStarNode* parent = nullptr):pos(newPos),Parent(parent),G(0),H(0) {};
		AStarNode(const AStarNode& src) = delete;
		AStarNode(AStarNode&& src) = delete;
	}Node;

	class AStar
	{
		using HeurisFunc = std::function<int(const Pos&, const Pos&)>;
	private:

		std::vector<std::vector<int>>* World;
		HeurisFunc mHeuris;
		Pos mWorldSize;
		std::array<Pos,8> mDirection;
		int mDiagonalMovement;
	public:
		void SetWorldSize(int x, int y) { mWorldSize = Pos(x, y); }
		void SetWorldSize(Pos& size) { mWorldSize = size; }
		void SetHeurisFunc(HeurisFunc func) { mHeuris = func; }
		void SetDiagonalMovement(bool bEnable) { mDiagonalMovement = bEnable ? 8 : 4; }
		void SetWorld(std::vector<std::vector<int>>* newWorld)
		{
			if (newWorld->size() == 0)
				throw std::invalid_argument("Unuseable Map data");
			else
			{
				World = newWorld;
				mWorldSize = Pos(World->size(), (*World->begin()).size());
			}
		}
		bool DetectCollision(const Pos& pos);

		std::vector<Pos>& FindPath(const Pos& src, const Pos& dest);
		AStar();
		~AStar();
	};

	class Heuristic
	{
		static Pos GetDelta(const Pos& src, const Pos& dest);
	public:
		static int manhattan(const Pos& src, const Pos& dest);
		static int euclidean(const Pos& src, const Pos& dest);
		static int octagonal(const Pos& src, const Pos& dest);
		static int chebyshev(const Pos& src, const Pos& dest);
	};
}


