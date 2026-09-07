#include <iostream>

int main()
{
	//top-level and low-level const.
	int val = 0;
	int const cval = 0;
	const int* const ptr1 = &cval; //top level is always in the right but low is on the left
	const int* const ptr2 = &val;
	//[top-level]
	//Copying an object doesn’t change the copied object. As a result, it is immaterial whether the object copied from or copied into is const

	//[low-level]
	//in the other hand low level is forbidden the low-level const should match
	const int ci = 0;
	const int* ptr1 = &ci;
	//int* ptr2 = ptr; //wrong cuz low-level dont match
	//int& ref1 = ci; // cannot bind int reference to const int.
	const int& ref2 = ci; 
	return 0;
}