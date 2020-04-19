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
	//���� ������ �۾����� throw�� �����Ѵ�
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
		// (exception_ptr ���� ó������ �ͼ��� �Ǵ� �ֱ� ó���� �ͼ����� ������)
		//current_exception �Լ��� throw���� �ͼ����� exception_ptr�� ��ȯ�Ѵ�
		
	}
}

void doWorkInThread()
{
	exception_ptr error;
	thread t{ threadFunc,ref(error) };
	t.join();
	if (error)
	{
		//��߻��� �ͼ����� �ִ��� Ȯ���Ѵ�
		cout << "Main thread received exception, rethrowing it..." << endl;
		rethrow_exception(error);
		//rethrow_exception 
		//except ptr�� ����Ű�� �ͼ����� ��߻����� �ٸ� �����忡���� �ͼ��� ó���� �����ϵ��� �����
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