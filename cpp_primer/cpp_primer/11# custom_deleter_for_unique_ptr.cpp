#include <iostream>
using namespace std;

void deleter(int* p)
{
	delete p;
}

int main()
{
	std::unique_ptr<int, decltype(deleter)*> ptr(new int(), deleter);

	return 0;
}