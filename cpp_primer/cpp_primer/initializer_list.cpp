#include <iostream>
#include <initializer_list>

//We can write a function that takes an unknown number of arguments of a single type
//by using an initializer_list parameter
void fcn(std::initializer_list<std::string> s)
{
	for (auto str : s)
	{
		std::cout << str;
	}
}

int main()
{
	fcn({ "hallo", "ya", "sa7by" });

	return 0;
}