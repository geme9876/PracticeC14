#pragma once
#include <list>
#include <functional>
#include <algorithm>
template <class T> class Delegate;


//�������� ���ø� ���ϰ��� R�̰� ���ڰ� ������
template<class R, class ... ARGS>
class Delegate<R(ARGS...)>
{
protected:
	std::list<std::function<R(ARGS...)>> funcs;
public:
	typedef typename std::list<std::function<R(ARGS...)>>::iterator iterator;

	void bind_unique(std::function<R(ARGS...)> const& arg)
	{
		//����Ʈ �ߺ� ó���� function ���ø��� ==�����ڰ� ���⶧���� ���� function�� �Լ������͸� �޾� ���Ѵ�
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
		//�ܼ� list push_back ���� �Լ�
		funcs.push_back(arg);
	}


	R excute(const ARGS... args)
	{
		//���ε��� �Լ��� ȣ��
		R result;
		for (auto& func : funcs)
		{
			result = func(args...);
		}
		return result;
	}
};




//�������� ���ø� ���ϰ� void
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