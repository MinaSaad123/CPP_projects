#include <iostream>
namespace NS {
	void print() { ; }
}
int main() {

	/*To understand the interaction between using declarations and overloading, it is
		important to remember that a using declaration declares a name, not a specific
		function*/

	//using NS::print(int); // error: cannot specify a parameter list
	using NS::print; // ok: using declarations specify names only
	return 0;
}