#include <iostream>
using namespace std;

// ptr is created and initialized when process is called
void process(shared_ptr<int> ptr)
{
	// use ptr
} // ptr goes out of scope and is destroyed

int main()
{
	//dealing with memory directly and shared_ptr.
	int* x(new int());

	//process(x); // error: cannot convert int* to shared_ptr<int>
	process(shared_ptr<int>(x)); // legal, but the memory will be deleted!
	int j = *x; // undefined: x is a dangling pointer
	//======================================================================
	shared_ptr<int> p(new int(42));
	auto* p2 = p.get(); //if you deleted the ptr from the get then shared_ptr will be pointed to.
	{
		shared_ptr<int> p3(p2);
	}
	int foo = *p; //dangling pointer.



	return 0;
}