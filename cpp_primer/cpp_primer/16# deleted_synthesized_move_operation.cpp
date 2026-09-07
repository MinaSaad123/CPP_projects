#include <iostream>

int main()
{
	//[note] move constructor and move assignment operator is deleted when
	//1- there is a const or reference member (like copy)
	//2- if destructor is deleted same as(copy)
	//3- if member's move constructor/assignment is deleted or inaccessible, same as (copy).
	//4- if any member has copy constructor/assignment then it won't implicity generated.
	//5- if you are using a class which has no move constructor.

	return 0;
}