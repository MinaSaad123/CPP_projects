#include <iostream>
using namespace std;

int main()
{
	std::shared_ptr<int> sp;
	std::weak_ptr<int> wp(sp); //weak_ptr should pass to it a shared_ptr.

	//1- expired() function if the use_cout returned zero then the return from expired is false otherwise false.
	//2- lock() function return null if expired is false otherwise return shared_ptr to the object.

	if (shared_ptr<int> np = wp.lock()) 
	{	
		// true if np is not null
		// inside the if, np shares its object with p
	}
	return 0;
}