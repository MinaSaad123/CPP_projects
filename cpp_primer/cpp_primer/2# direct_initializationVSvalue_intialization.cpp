#include <iostream>

int main()
{
	int x1 = 1; //copy initialization
	int x2{ 1 }; //direct initialization
	int x3(1); //direct initialization
	int x4{}; //value initialization
	//int x5(int()); //still function type
	
	//[NOTE] assign operator trigger copy constructor.
	return 0;
}