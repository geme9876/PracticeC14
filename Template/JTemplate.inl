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
	//���ø� ���Կ����ڴ� �����Ϸ����� ������ �⺻ ���Կ����ڸ� ����ϱ⿡ �ڱ� ���� ����ó�� �ʿ����
}
template <typename T>
template <typename E>
JTemplate<T>& JTemplate<T>::operator=(const JTemplate<E>& rhs)
{
	//���ø� ���Կ����ڴ� �����Ϸ����� ������ �⺻ ���Կ����ڸ� ����ϱ⿡ �ڱ� ���� ����ó�� �ʿ����
};

