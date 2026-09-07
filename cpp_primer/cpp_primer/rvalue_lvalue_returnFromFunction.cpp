#include <iostream>

char& get_val(std::string& str, std::string::size_type ix)
{
	return str[ix]; // get_val assumes the given index is valid
}
int main()
{
	//as well as the return of function is lvalue {reference i mean} then we can assign to it
	std::string s("a value");
	std::cout << s << std::endl; // prints a value
	get_val(s, 0) = 'A'; // changes s[0] to A
	std::cout << s << std::endl; // prints A value
	return 0;
}