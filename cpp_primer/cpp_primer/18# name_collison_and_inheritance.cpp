#include <iostream>
using namespace std;

struct Base {
	Base() : mem(0) {}
protected:
	int mem;
};
struct Derived : Base {
	Derived(int i) : mem(i) {} // initializes Derived::mem to i
	// Base::mem is default initialized
	int get_base_mem() { return Base::mem; }
	int get_Derived_mem() { return mem; } // returns Derived::mem
protected:
	int mem; // hides mem in the base
};

int main() {
	//[note] overloading the function and variables with same name in inner scope hides the the outer scope not overloading it.
	Derived d(42);
	cout << d.get_Derived_mem() << endl; // prints 42
	cout << d.get_base_mem() << endl;

	return 0;
}