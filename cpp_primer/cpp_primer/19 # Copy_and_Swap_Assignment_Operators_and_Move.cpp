#include <iostream>

class car
{
	friend void swap(car& RHS, car& LHS);
	int x;
public:
	car(int y) : x(y) {};

	car(car&&)  noexcept = default;

	//When an assignment operator takes its parameter BY VALUE
	//(car), the compiler prefers it over ANY reference version.
	// it doesn't choose depends on the speed, number of moves, efficiency and number of temporary objects
	car& operator=(car&&)  noexcept = default;
	
	car(const car&) = default;

	car& operator=(car RHS)
	{
		using std::swap;
		swap(*this, RHS);

		return *this;
	}
};

void swap(car& RHS, car& LHS)
{
	using std::swap;
	swap(RHS.x, LHS.x);
}


int main()
{
	car BMW(0), Mercedas(0);

	BMW = Mercedas;

	return 0;
}