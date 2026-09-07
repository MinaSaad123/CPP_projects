#include <iostream>
#include <functional>

// ordinary function
int add(int i, int j) { return i + j; }

// ordinary function
float add(float i, float j) { return i + j; }

int main()
{
	std::function<int(int, int)> ops; 
	//ops = add; //error cuz there is overloading for add so you means which add
	
	//to solve this problem there is two methods
	//first: is pointer to function
	int (*ptr)(int, int) = add;
	ops = ptr;

	//second: using lambda expression
	ops = [](int a, int b) -> int {return add(a, b); };


}