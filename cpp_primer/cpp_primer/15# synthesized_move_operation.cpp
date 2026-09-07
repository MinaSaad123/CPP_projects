#include <iostream>

// the compiler will synthesize the move operations for X and hasX
struct X {
	int i; // built-in types can be moved
	std::string s; // string defines its own move operations
};
struct hasX {
	X mem; // X has synthesized move operations
};

int main()
{
	X x, x2 = std::move(x); // uses the synthesized move constructor
	hasX hx, hx2 = std::move(hx); // uses the synthesized move constructor
	
	//The compiler synthesizes the move constructor and move assignment only if
	//	a class does not define any of its own copy - control members and only if all
	//	the data members can be moved constructed and move assigned, respectively.
	return 0;
}