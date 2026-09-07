#include <iostream>
using namespace std;

std::string mechanical_car::energy_source = "petrol";
class mechanical_car {
public:
	// default constructor
	mechanical_car() = default;
	explicit
		mechanical_car(int x) : motor(x) {
		//do anything
	}
	virtual int retrieve_the_motor() const {
		return motor;
	}
	//Base classes ordinarily should define a virtual destructor.Virtual destructors
	//	are needed even if they do no work.
	virtual ~mechanical_car() = default;
	static void print_public() { std::cout << "i'm in the class" << std::endl; }
private:
	static std::string energy_source;
	static void print() { std::cout << mechanical_car::energy_source << std::endl; }
protected:
	int motor;
};
std::string mechanical_car::energy_source = "petrol";
//inheritance
class electrical_car : public mechanical_car {
public:
	//derived class contructor, we provide a base class contructor first in the initializer list
	electrical_car() : mechanical_car() { ; }
	//ensures you're actually overriding a base virtual function and catch errors early.
	int retrieve_the_motor() const override {
		return motor;
	}
};
int main()
{
	//static members obey normal access control.If the member is private in the base
	//	class, then derived classes have no access to it.Assuming the member is accessible,
	//	we can use a static member through either the base or derived :

	//static member cannot be virtual.
	mechanical_car::print_public();
	electrical_car::print_public();
	//if we are in the member function we can write like this:
	//print_public(); //this is implicity added.
	//this->print_public();
	return 0;
}