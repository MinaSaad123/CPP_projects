#include <iostream>
struct mini_class
{
	int mem1;

	//member function is implicity inline.
	int fcn() const
	{
		//this is const pointer refer to the object.
		return this->mem1; /*const is to this which mean the object it binds to is const*/
	}
};

int main()
{


	return 0;
}