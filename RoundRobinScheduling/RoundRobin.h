#pragma once
#include <vector>
template<typename T>
class RoundRobin
{
public:
	//���� �׸� ���ڷ� �����Ѵ�
	RoundRobin(size_t numExpected = 0);
	virtual ~RoundRobin();
	
	//�����̳� ���� ���� ���� ����
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