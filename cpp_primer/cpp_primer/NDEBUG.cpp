#include <iostream>
#define NDEBUG
int main()
{
#ifndef NDEBUG
	std::cerr << "Error: " << __FILE__
		<< " : in function " << __func__
		<< " at line " << __LINE__ << std::endl
		<< " Compiled on " << __DATE__
		<< " at " << __TIME__ << std::endl
		<< "\: Length too short" << std::endl;
#endif
	return 0;
}