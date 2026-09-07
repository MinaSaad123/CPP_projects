#include <iostream>
using namespace std;

int main()
{
	//if new fail then it throws a bad_alloc exception
	int* ptr = new int(); //if new fail bad_alloc will be throw
	//to omit it

	int* ptr2 = new (nothrow) int(); //it will return a null ptr.

	return 0;
}