#include <iostream>

struct mini
{
	mini() = default;

	//we can change access_ctr even it is const
	mutable int access_ctr = 0;

	void fcn() const
	{
		access_ctr++;
	}

	void print()
	{
		std::cout << access_ctr;
	}
};

int main()
{
	mini c;
	c.fcn();
	c.fcn();
	c.fcn();
	c.fcn();

	c.print();
	return 0;
}