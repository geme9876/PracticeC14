#include"RoundRobin.h"
template<typename T>
RoundRobin<T>::RoundRobin(size_t numExpected)
{
	mElems.reserve(numExpected);
	mCurElem = end(mElems);
}

template<typename T>
RoundRobin<T>::~RoundRobin()
{
}

template<typename T>
void RoundRobin<T>::add(const T & elem)
{
	int pos = (mCurElem == end(mElems) ? -1 : mCurElem - begin(mElems));
	mElems.push_back(elem);
	mCurElem = (pos == -1 ? end(mElems) : begin(mElems) + pos);
}

template<typename T>
void RoundRobin<T>::remove(const T & elem)
{
	for (auto it = begin(mElems); it != end(mElems); ++it)
	{
		if (*it == elem)
		{
			int newPos;
			if(mCurElem <= it)
			{
				newPos = mCurElem - begin(mElems);
			}
			else
			{
				newPos = mCurElem - begin(mElems) - 1;
			}
			mElems.erase(it);
			mCurElem = begin(mElems) + newPos;
			return;
		}
	}

}

template<typename T>
T & RoundRobin<T>::getNext()
{
	if (mElems.empty())
	{
		throw std::out_of_range("No Elem");
	}
	if (mCurElem == end(mElems))
	{
		mCurElem = begin(mElems);
	}
	else
	{
		++mCurElem;
		if (mCurElem == end(mElems))
		{
			mCurElem = begin(mElems);
		}
	}
	return *mCurElem;
}
