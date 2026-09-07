#include <iostream>


struct mini_class
{
	int mem1;
	mini_class() = default;

	//member function is implicity inline.
	int fcn() const
	{
		//this is const pointer refer to the object.
		return this->mem1; /*const is to this which mean the object it binds to is const*/
	}
};

int main()
{
	//Objects that are const, and references or pointers to const objects, may call only const member functions.
	const mini_class c1;
	c1.fcn();

	mini_class c2;
	//c1.fcn(); //wrong

	return 0;
}