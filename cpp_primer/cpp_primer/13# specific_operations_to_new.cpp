#include <iostream>

int main()
{
	//make new acts like a malloc using ::operator
	void* str = ::operator new(1024);

	//allocate at specific part of memory.
	//int* p = new (/*memory*/) int(42);  // construct an int inside this memory


	return 0;
}