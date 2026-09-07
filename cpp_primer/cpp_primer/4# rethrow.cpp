#include <iostream>
using namespace std;

int main()
{
	try {
		throw; // it is the first throw without no parameter then it will call the terminate exception.
	}
	catch(...){

	}

	try {
		try {
			throw string("error");
		}
		catch (string& e) {
			cout << e << endl;
			e += " from throw 1";
			throw; //it is second throw then even with no paramter it will throw the exception paramter.
		}
	}
	catch (string& e) {
		cout << e;
	}
	return 0;
}