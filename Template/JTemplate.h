#pragma once
#include <vector>
//������ �����ε��� ���� ���漱��
template <typename T> class JTemplate; 

template <typename T>
JTemplate<T> operator +(const JTemplate<T>& lhs, const JTemplate<T>& rhs) { return JTemplate<T>(1, 2); };

template <typename T>
class JTemplate
{
public:
	T& foo(int a, int b);
	friend JTemplate<T> operator+ <T>(const JTemplate<T>& lhs, const JTemplate<T>& rhs);
	std::vector<std::vector<T>> mContainer;

	

	JTemplate(int a, int b) {
	
		mContainer.resize(a);
		for (int i = 0; i < a; i++)
		{
			mContainer[i].resize(b);
		}
		for (int i = 0; i < a; i++)
		{
			for (int j = 0; j < mContainer[i].size(); j++)
			{
				mContainer[i][j] = i*10 + j;
			}
		}
	
	};

	template<typename E>
	JTemplate(const JTemplate<E>& src); //��������� 

	template<typename E>
	JTemplate<T>& operator =(const JTemplate<E>& rhs); // ���Կ�����
	virtual ~JTemplate() {};
};
template <>
class JTemplate<double>
{
public:
	double foo(int a, int b) { return static_cast<double>(a) + static_cast<double>(b); };
	double tou(double a, double b) { return a + b; }
	explicit JTemplate(double a, double b) {}; // ������ ������ �Ͻ��� ����ȯ ��Ȱ��ȭ, 
	//���ø� Ư��ȭ ���� ���ø����� �̸��� �����ϰ� �ٸ� Ŭ������� �����ϸ�ɵ�
};

template <typename T1,typename T2>
auto myFunc(const T1& t1, const T2& t2)
{
	return t1 + t2;  //C++14 ���� �ڵ� ����Ÿ�� ���� ��� ���� 
}

template<typename T>
size_t Find(T& value, T* arr, size_t size)
{
	for (size_t i = 0; i < size; i++)
	{
		if (arr[i] == value)
		{
			return i;
		}
	}
	return -1;
}

template<typename T,size_t S>
size_t Find(T& value, T(&arr)[S])
{
	return Find(value, arr, S); //�����Ϸ��� �迭�� ũ�⸦ �˰��ִٸ� (���ù迭) �̸� �̿��Ѵ� 
}


#include "JTemplate.inl"


