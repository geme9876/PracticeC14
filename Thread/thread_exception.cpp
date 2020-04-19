#include <thread>
#include <iostream>
#include <exception>
#include <stdexcept>
#include <atomic>
#include <chrono>


using namespace std;





void doSomeWork()
{
	for (int i = 0; i < 5; ++i)
	{
		cout << i << endl;
	}
	cout << "Thread throwing a runtime error" << endl;
	throw runtime_error("Exception from thread");
	//실제 스레드 작업에서 throw를 생성한다
}

void threadFunc(exception_ptr& err)
{
	try {
		doSomeWork();
	}
	catch (...)
	{
		cout << "thread caught exception,returning exception" << endl;
		err = current_exception();
		// (exception_ptr 현재 처리중인 익셉션 또는 최근 처리된 익셉션의 복제본)
		//current_exception 함수는 throw받은 익셉션을 exception_ptr로 반환한다
		
	}
}

void doWorkInThread()
{
	exception_ptr error;
	thread t{ threadFunc,ref(error) };
	t.join();
	if (error)
	{
		//재발생된 익셉션이 있는지 확인한다
		cout << "Main thread received exception, rethrowing it..." << endl;
		rethrow_exception(error);
		//rethrow_exception 
		//except ptr이 가리키는 익셉션을 재발생시켜 다른 스레드에서도 익셉션 처리가 가능하도록 만든다
	}
	else
	{
		cout << "Main thread did not receive any exception" << endl;
	}
}


int main()
{
	try {
		for(int i=0; i<5 ;i++)
		doWorkInThread();
	}
	catch(const exception& e){
		cout << "Main function caught : " << e.what() << "" << endl;
	}

	return 0;
}