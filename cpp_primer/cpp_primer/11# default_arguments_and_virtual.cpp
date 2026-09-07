#include <iostream>

class base_class {
public:
	virtual void print(int x = 1) {
		std::cout << "base class " << x;
	}
};
class derived_class :  public base_class {
public:
	 virtual void print(int x = 2) override {
		std::cout << "derived class " << x;
	}
};
int main()
{
	base_class* p = new derived_class();

	p->print(); //will not print 2.

	return 0;
}