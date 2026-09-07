#include <iostream>

class car
{
public:
	car() { ; }
	car(const car&) = default;
	car& operator=(const car& BMW)
	{
		delete ptr; //it is a serious problem cuz what if we pass the same object.
		ptr = BMW.ptr;
		x = BMW.x;
		
		return *this;
	}

private:
	int* ptr;
	int x;

};

int main()
{
	

	return 0;
}