#include <iostream>
#include <stdexcept>

int main()
{
	int i = 0, c = 0;

	try
	{
		if (i == c)
			throw std::runtime_error("they are equal");

	}
	catch (std::runtime_error err)
	{
		std::cout << err.what(); 
	}


	return 0;
}