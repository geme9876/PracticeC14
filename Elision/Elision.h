#pragma once
#include <iostream>
using namespace std;
class Elision
{
private:
	int data_;
	int* pdata_;
public:
	Elision() {};
	Elision(int data) : data_(data) 
	{
		cout << "�Ϲݻ�����" << endl; 
		pdata_ = new int(data);
	}
	Elision(const Elision& a) : data_(a.data_) 
	{ 
		cout << "���������" << endl; 
		if (this->pdata_)
		{
			//�̹� �������� �����͸� �Ҵ�޾� �������ִٸ� �����Ѵ�
			delete pdata_;
		}
		pdata_ = new int(*a.pdata_);
	}
	Elision(Elision&& a) {  // a�� ������ �ӽð�ü
		cout << "�̵�������" << endl;  
		data_ = a.data_; 
		pdata_ = a.pdata_;
		a.pdata_ = nullptr; // �ӽð�ü �Ҹ�ÿ� ������ ������ ���´�
	} 


	
	Elision& operator=(const Elision& rhs)
	{
		cout << "���Կ�����" << endl;

		if (this == &rhs)
		{
			return *this; //�ڱ� �ڽ��� �����ϴ� ��� �������� �ʴ´�
		}
		data_ = rhs.data_;		
		//���� ����
		pdata_ = rhs.pdata_;
		//���� ���� ������ ��쿡  src�� �����Ͱ� �����Ǹ� ���� �����͸� �Ҿ�������� ����
		return *this;
	}
	Elision& operator=(const Elision&& rhs)
	{
		cout << "�̵� ���� ������" << endl;
		if (this == &rhs)
		{
			return *this; //�ڱ� �ڽ��� �����ϴ� ��� �������� �ʴ´�
		}
		data_ = rhs.data_;
		//���� ����
		pdata_ = rhs.pdata_;
		//���� ���� ������ ��쿡  src�� �����Ͱ� �����Ǹ� ���� �����͸� �Ҿ�������� ����
		return *this;
	}



	~Elision()
	{
		if (pdata_) delete pdata_;
		//���� pdata�� nullptr�̶�� �������� �ʴ´�
		//�̵������� ȣ��� ������ ������ ����
	};
};

int main()
{
	Elision A(5);
	Elision B(A);
	Elision C;
	Elision D(std::move(A));
	//�̵� ������ ȣ�� ����  pdata �� nullptr�� �ȴ�
	Elision E;

	C = B;
	
	E = std::move(A);
	


	

	return 0;
}
