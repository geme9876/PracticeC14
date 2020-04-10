//#include <stdexcept>
//#include <iostream>
//
//using namespace std;
//void g() { throw invalid_argument("Some exception"); }
//void f()
//{
//	try {
//		g();
//	}
//	catch (const invalid_argument& e)
//	{
//		cout << "Caught in f : " << e.what() << endl;
//		throw;
//	}
//}
//int main()
//{
//	try {
//		f();
//
//	}
//	catch (const invalid_argument& e)
//	{
//		cout << "Caught in main    :" << e.what() << endl;
//	}
//	return 0;
//}