#include <iostream>
using namespace std;

//declaration part.
class mechanical_car;
//A class must be defined, not just declared, before we can use it as a base class
//[note] One implication of this rule is that it is impossible to derive a class from itself
class electrical_car : public mechanical_car {
public:
	//derived class contructor, we provide a base class contructor first in the initializer list
	electrical_car() : mechanical_car() { ; }
	//ensures you're actually overriding a base virtual function and catch errors early.
	int retrieve_the_motor() const override {
		return motor;
	}
};
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

int main()
{
	return 0;
}