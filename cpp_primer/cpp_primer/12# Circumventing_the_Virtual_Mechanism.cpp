#include <iostream>

class base_class {
public:
	virtual void print(int x = 1) {
		std::cout << "base class " << x;
	}
};
class derived_class : public base_class {
public:
	virtual void print(int x = 2) override {
		std::cout << "derived class " << x;
	}
};
int main()
{
	base_class* p = new derived_class();

	//we want to prevent dynamic binding of a call to a virtual function; we
	//want to force the call to use a particular version of that virtual
	p->base_class::print(); //will not print 2.

	return 0;
}