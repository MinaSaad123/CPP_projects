#include <iostream>
using namespace std;

int main()
{
	//auto deduce only the object in th parentheses
	std::string obj;
	auto ptr1 = new auto(obj); //it will works.
	//auto ptr2 = new auto{ 1,3,5,7 };
	return 0;
}