#include <iostream>
#include <functional>
#include <vector>
#include <algorithm>
using namespace std::placeholders;

std::ostream& print(std::ostream& os, const std::string& s, char c)
{
	os << s << c;

	return os;
}

int main()
{
	std::vector<std::string> svec{ "mina", "saad" };
	std::ostream& os(std::cout);
	//ref is soluation for we need a copy and reference in the same time.
	//The ref function returns an object that contains the given reference and that is itself copyable.
	for_each(svec.begin(), svec.end(), bind(print, std::ref(os), _1, ' '));
	//there is cref which returns an object that contains the given reference to const and itseld is copyable
	return 0;
}


