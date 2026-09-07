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

int main() {
	//Because a base object might or might not be part of a derived object, there is no
	//	automatic conversion from the base class to its derived class(s) :
	
	mechanical_car car;
	//electrical_car& carRef = car; //error cannot convert the base class to derived class.
	electrical_car car2;
	mechanical_car& car3 = car2; //can convert from derived class to base class.

	return 0;
}