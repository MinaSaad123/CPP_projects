#include <iostream>

void deleter(int* p)
{
	delete p;
}

int main()
{
	//custom deleter
	std::shared_ptr<int> ptr(new int(), deleter);

	return 0;
}