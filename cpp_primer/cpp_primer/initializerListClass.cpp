#include <iostream>

struct cmini
{
	int x = 3; //in-class initializer should be initialized by = or curly braces.
	int y; //garbage value.
	
	cmini() = default;

	cmini(int x, int y) : x(x), y(y)
	{

	}
};

int main()
{
	cmini mini1; //trigger default constructor.
	cmini mini2 { 1, 3 }; //trigger initializer list constructor.

	return 0;
}