#pragma once
#include <list>
#include <functional>
#include <algorithm>
template <class T> class Delegate;


//가변인자 템플릿 리턴값이 R이고 인자가 여러개
template<class R, class ... ARGS>
class Delegate<R(ARGS...)>
{
protected:
	std::list<std::function<R(ARGS...)>> funcs;
public:
	typedef typename std::list<std::function<R(ARGS...)>>::iterator iterator;

	void bind_unique(std::function<R(ARGS...)> const& arg)
	{
		//리스트 중복 처리시 function 템플릿의 ==연산자가 없기때문에 직접 function의 함수포인터를 받아 비교한다
		R(*const* arg_ptr)(ARGS...) = arg.template target<R(*)(ARGS...)>();
		bool check = 0;
		iterator it = std::find_if(funcs.begin(),funcs.end(),
			[&](std::function<R(ARGS...)>& elem)->bool
		{
			R(*const* ptr)(ARGS...) = elem.template target<R(*)(ARGS...)>();

			return *ptr == *arg_ptr;
		});

		if(it == funcs.end())
		{ 
			bind(arg);
		}
	}

	void bind(std::function<R(ARGS...)> const& arg)
	{
		//단순 list push_back 래핑 함수
		funcs.push_back(arg);
	}


	R excute(const ARGS... args)
	{
		//바인딩된 함수들 호출
		R result;
		for (auto& func : funcs)
		{
			result = func(args...);
		}
		return result;
	}
};




//가변인자 템플릿 리턴값 void
template<class... ARGS>
class Delegate <void(ARGS...)>
{
	std::list<std::function<void(ARGS...)>> funcs;
public:
	typedef typename std::list<std::function<void(ARGS...)>>::iterator iterator;
	void excute(const ARGS...args)
	{
		for (auto& func : funcs)
		{
			func(args...);
		}
	}
	void  bind_unique(std::function<void(ARGS...)> const& arg)
	{
		void(*const* arg_ptr)(ARGS...) = arg.template target<void(*)(ARGS...)>();
		iterator it = std::find_if(funcs.begin(), funcs.end(),
			[&](std::function<void(ARGS...)>& elem)
		{
			void(*const* ptr)(ARGS...) = elem.template target<void(*)(ARGS...)>();
			return ptr == arg_ptr;
		});
		if (it == funcs.end())
		{
			bind(arg);
		}
	}
	void bind(std::function<void(ARGS...)> const& arg)
	{
		funcs.push_back(arg);
	}

};