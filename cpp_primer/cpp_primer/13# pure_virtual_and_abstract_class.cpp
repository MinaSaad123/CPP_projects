#include <iostream>
using namespace std;

class base_class {
public:
	virtual void print() = 0;
};
class derived_class : public base_class {
public:
	virtual void print(int x = 2) {
		std::cout << "derived class " << x;
	}
};
int main() {
	
	//base_class obj; //error cuz we cannot instantiat and object from abstract base class.
	

	return 0;
}