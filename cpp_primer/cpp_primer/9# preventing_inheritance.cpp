#include <iostream>
using namespace std;

class mechanical_car final {
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