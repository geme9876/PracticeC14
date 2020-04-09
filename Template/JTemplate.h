#pragma once
#include <vector>
//연산자 오버로딩을 위한 전방선언
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
	JTemplate(const JTemplate<E>& src); //복사생성자 

	template<typename E>
	JTemplate<T>& operator =(const JTemplate<E>& rhs); // 대입연산자
	virtual ~JTemplate() {};
};
template <>
class JTemplate<double>
{
public:
	double foo(int a, int b) { return static_cast<double>(a) + static_cast<double>(b); };
	double tou(double a, double b) { return a + b; }
	explicit JTemplate(double a, double b) {}; // 생성자 인자의 암시적 형변환 비활성화, 
	//템플릿 특수화 위의 템플릿과는 이름만 공유하고 다른 클래스라고 생각하면될듯
};

template <typename T1,typename T2>
auto myFunc(const T1& t1, const T2& t2)
{
	return t1 + t2;  //C++14 부터 자동 리턴타입 연역 기능 지원 
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
	return Find(value, arr, S); //컴파일러가 배열의 크기를 알고있다면 (스택배열) 이를 이용한다 
}


#include "JTemplate.inl"


