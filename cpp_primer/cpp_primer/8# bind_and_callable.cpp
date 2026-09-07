#include <iostream>
#include <functional>
#include <vector>
using namespace std::placeholders;

bool check_size(const std::string& s, std::string::size_type sz)
{
	return s.size() >= sz;
}

int main()
{
	auto check6 = bind(check_size, _1, 6);

	auto result = check6(std::string("hallo"));

	return 0;
}