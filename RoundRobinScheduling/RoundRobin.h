#pragma once
#include <vector>
template<typename T>
class RoundRobin
{
public:
	//예상 항목 숫자로 생성한다
	RoundRobin(size_t numExpected = 0);
	virtual ~RoundRobin();
	
	//대입이나 값에 의한 전달 방지
	RoundRobin(const RoundRobin& src) = delete;
	RoundRobin& operator=(const RoundRobin& rhs) = delete;

	void add(const T& elem);
	void remove(const T& elem);
	T& getNext();

private:
	std::vector<T> mElems;
	typename  std::vector<T>::iterator mCurElem;
};
#include "RoundRobin.inl"