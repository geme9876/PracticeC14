#pragma once
template <typename T>
T& JTemplate<T>::foo(int x, int y)
{
	return mContainer[x][y];
}
template <typename T>
template <typename E>
JTemplate<T>::JTemplate(const JTemplate<E>& src)
{
	//템플릿 대입연산자는 컴파일러에서 생성된 기본 대입연산자를 사용하기에 자기 대입 예외처리 필요없음
}
template <typename T>
template <typename E>
JTemplate<T>& JTemplate<T>::operator=(const JTemplate<E>& rhs)
{
	//템플릿 대입연산자는 컴파일러에서 생성된 기본 대입연산자를 사용하기에 자기 대입 예외처리 필요없음
};

