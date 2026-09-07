#include <iostream>
class Base {
public:
	//Executing delete on a pointer to base that points to a derived object has
	//	undefined behavior if the base’s destructor is not virtual.
	virtual ~Base() = default;
};

class Derived : public Base {
public:

	virtual ~Derived() override = default;
};

int main()
{

	return 0;

}