#include <iostream>

class Temp
{
public:
	Temp() {}
	
	//default synthesized destructor be like that
	//~Temp() { ; }
};

int main()
{
	//[NOTE]
	//1- destructor is not run when the reference to class go out the the scope.


	return 0;
}