#include <iostream>

int main()
{
	//rdstate return the current state value, so we can exploit this like this:

	auto old_state = std::cin.rdstate();
	std::cin.clear();

	//do anything on the stream

	std::cin.setstate(old_state);



}