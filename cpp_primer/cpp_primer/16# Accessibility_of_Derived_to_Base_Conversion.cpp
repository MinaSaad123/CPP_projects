#include <iostream>
using namespace std;

class base {
public:
	int x;
protected:
	int y;
private:
	int z;
};

class derived1 : public base {
	//[note] the friendship is not transitive which means it's not inherited.
	friend void print();
};
class derived2 : protected base {
	friend void print();
};
class derived2 : private base {
	friend void print();
};
void print() { 
	//derived to base conversion cannot happens when the inheritance is public or protected.
	base* p = new derived1(); 
	base* p = new derived2(); 
	//base* p = new derived3(); //error. derived to base conversion cannot happen if it's inherited protectedly.
}

int main() {
	base* p = new derived1();
	//base* p = new derived2();
	//base* p = new derived3();

	return 0;
}