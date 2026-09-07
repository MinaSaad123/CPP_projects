#include <iostream>
using namespace std;

int main()
{
	allocator<std::string> alloc;
	//1- allocation
	auto const p = alloc.allocate(10);
	//2- construction
	auto q = p; //q will always point to one past the last constructed element.
	alloc.construct(q++);
	alloc.construct(q++, 10, 'c'); // the rest of elements is argument for constructor
	alloc.construct(q++, "hi");

	cout << *p << endl; // ok: uses the string output operator
	//cout << *q << endl; // disaster: q points to unconstructed memory!	
	
	//3- destruction
	while (q != p) //remember p is pointing to the start of the chunk of address.
		alloc.destroy(--q);

	//4- dealloction
	alloc.deallocate(p, 10);
	return 0;
}