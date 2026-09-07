#include <iostream>
using namespace std;

unique_ptr<int> clone(int p)
{
	// ok: explicitly create a unique_ptr<int> from int*
	return unique_ptr<int>(new int(p));
}

int main()
{
	//release() function, the return from it is the pointer it pointes to it.
	std::unique_ptr<int> ptr1(new int()), ptr2;

	unique_ptr<int[]> up(new int[10]); //unique_ptr provides special deleter for dynamic array.

	ptr2.reset(ptr1.release()); //this is how we use release to reset unique_ptr from another unique_ptr.

	//ptr1 = ptr2 //is wrong cuz the unique_ptr forbidden the copy constructor and assign constructor.
	//[note] there is a one exception to rule that cannot copy a unique_ptr:
	//we can copy or assign a unique_ptr that is about to destroyed.
	ptr2.release(); //is return from release is leaked memory.
	ptr2.reset(clone(2).release());
	

	return 0;
}