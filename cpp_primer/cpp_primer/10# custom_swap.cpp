#include <iostream>

class car
{
	friend void swap(car& lhs, car& rhs);
	friend void swap(int*& ptr1, int*& ptr2);
	friend void swap(int& val1, int& val2);
public:
	car() { ; }
	car(const car&) = default;
	car& operator=(car BMW)
	{
		swap(*this, BMW);
		return *this;
	}

private:
	int* ptr;
	int x;
};

void swap(car& lhs, car& rhs)
{
	using std::swap;
	swap(lhs.ptr, rhs.ptr);
	swap(lhs.x, rhs.x);
}
void swap(int*& ptr1, int*& ptr2)
{
	auto temp = ptr1;
	ptr1 = ptr2;
	ptr2 = temp;
}
void swap(int& val1, int& val2)
{
	auto temp = val1;
	val1 = val2;
	val2 = temp;
}

int main()
{
	car BMW, MERCEDAS;
	swap(BMW, MERCEDAS);

	return 0;
}