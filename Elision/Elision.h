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
		cout << "일반생성자" << endl; 
		pdata_ = new int(data);
	}
	Elision(const Elision& a) : data_(a.data_) 
	{ 
		cout << "복사생성자" << endl; 
		if (this->pdata_)
		{
			//이미 동적으로 데이터를 할당받아 가지고있다면 해제한다
			delete pdata_;
		}
		pdata_ = new int(*a.pdata_);
	}
	Elision(Elision&& a) {  // a는 좌측값 임시객체
		cout << "이동생성자" << endl;  
		data_ = a.data_; 
		pdata_ = a.pdata_;
		a.pdata_ = nullptr; // 임시객체 소멸시에 포인터 해제를 막는다
	} 


	
	Elision& operator=(const Elision& rhs)
	{
		cout << "대입연산자" << endl;

		if (this == &rhs)
		{
			return *this; //자기 자신을 대입하는 경우 복제하지 않는다
		}
		data_ = rhs.data_;		
		//얕은 복사
		pdata_ = rhs.pdata_;
		//얕은 복사 대입의 경우에  src의 포인터가 삭제되면 같이 포인터를 잃어버림으로 주의
		return *this;
	}
	Elision& operator=(const Elision&& rhs)
	{
		cout << "이동 대입 연산자" << endl;
		if (this == &rhs)
		{
			return *this; //자기 자신을 대입하는 경우 복제하지 않는다
		}
		data_ = rhs.data_;
		//얕은 복사
		pdata_ = rhs.pdata_;
		//얕은 복사 대입의 경우에  src의 포인터가 삭제되면 같이 포인터를 잃어버림으로 주의
		return *this;
	}



	~Elision()
	{
		if (pdata_) delete pdata_;
		//만약 pdata가 nullptr이라면 삭제하지 않는다
		//이동생성자 호출시 포인터 삭제를 방지
	};
};

int main()
{
	Elision A(5);
	Elision B(A);
	Elision C;
	Elision D(std::move(A));
	//이동 생성자 호출 이후  pdata 는 nullptr이 된다
	Elision E;

	C = B;
	
	E = std::move(A);
	


	

	return 0;
}
