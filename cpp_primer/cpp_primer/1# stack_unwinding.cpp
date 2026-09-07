#include <iostream>
using namespace std;

//During stack unwinding, destructors are run on local objects of class type.
//Because destructors are run automatically, they should not throw.If, during
//stack unwinding, a destructor throws an exception that it does not also catch,
//the program will be terminated

//correct way 1
struct temp1 {
	int* ptr = nullptr;

	~temp1() {
		try {
			throw 1;
		}
		catch(...){

		}
	}
};

struct temp2 {
	int* ptr = nullptr;

	~temp2() noexcept {
		//do anything.
	}
};

int main() {


	return 0;
}