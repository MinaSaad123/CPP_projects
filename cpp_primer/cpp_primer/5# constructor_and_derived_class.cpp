#include <iostream>
using namespace std;

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
private:
	std::string energy_source = "petrol";

protected:
	int motor;
};
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
	//The fact that a derived object contains subobjects for its base classes is key
	//	to how inheritance works.
	mechanical_car car1;
	electrical_car car2;
	mechanical_car* pcar = &car1;
	//derived - to - base conversion
	pcar = &car2; //point to the mechanical_car part from electrical_car.
	//derived - to - base conversion
	mechanical_car& Rcar = car2; //bound to the mechanical_car part from electrical_car.
	return 0;
}