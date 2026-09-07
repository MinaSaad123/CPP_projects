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
	//ensures you're actually overriding a base virtual function and catch errors early.
	int retrieve_the_motor() const override {
		return motor;
	}
};

int motorType(mechanical_car& car) {
	//dynamic binding
	return car.retrieve_the_motor();
}

int main()
{
	mechanical_car car1;
	electrical_car car2;
	//In C++, dynamic binding happens when a virtual function is called through a
	//	reference(or a pointer) to a base class.
	std::cout << motorType(car1) << std::endl;
	std::cout << motorType(car2) << std::endl;

	return 0;
}