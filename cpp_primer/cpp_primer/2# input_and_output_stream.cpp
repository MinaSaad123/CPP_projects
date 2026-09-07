#include <iostream>
using namespace std;

class car
{
	friend std::ostream& operator<<(std::ostream& is, const car& LHS);
	friend std::istream& operator>>(std::istream& os, car& LHS);
public:
	int x;
	car() {};

};

std::ostream& operator<<(std::ostream& os, const car& LHS) {
	os <<  LHS.x;
	return os;
}

std::istream& operator>>(std::istream& is, car& LHS) 
{
	is >> LHS.x;

	if (!is) //checks the status of input stream.
	{
		LHS = car();
	}

	return is;
}

int main()
{
	car c;
	c.x = 10;
	cout << c << endl; // prints 10


	return 0;
}