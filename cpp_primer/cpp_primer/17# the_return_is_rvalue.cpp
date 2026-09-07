#include <iostream>

class car
{
	int x;
public:
	car(int y) : x(y) {};

	car& operator=(car&&)  noexcept = default;
};

car getcar(std::istream&)
{
	return car(3);
}

int main()
{
	car BMW(0), Mercedas(0);

	BMW = getcar(std::cin); //it returns rvalue so it trigger move assignment.


	return 0;
}