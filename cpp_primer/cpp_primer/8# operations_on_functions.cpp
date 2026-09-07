#include <iostream>
#include <functional>
#include <map>
using namespace std;

// ordinary function
int add(int i, int j) { return i + j; }

int main()
{
	
	// lambda, which generates an unnamed function-object class
	auto mod = [](int i, int j) { return i % j; };
	// function-object class
	struct div 
	{
		int operator()(int denominator, int divisor) {
			return denominator / divisor;
		}
	};

	function<int(int, int)> f1 = add; // function pointer
	function<int(int, int)> f2 = div(); // object of a function-object
	class
		function<int(int, int)> f3 = [](int i, int j) // lambda
		{ return i * j; };
	cout << f1(4, 2) << endl; // prints 6
	cout << f2(4, 2) << endl; // prints 2
	cout << f3(4, 2) << endl; // prints 8

	map<string, function<int(int, int)>> binops;
	map<string, function<int(int, int)>> binops = {
	{"+", add}, // function pointer
	{"-", std::minus<int>()}, // library function object
	{"/", div()}, // user-defined function object
	{"*", [](int i, int j) { return i * j; }}}; // unnamedlambda

	binops["+"](10, 5); // calls add(10, 5)
	binops["-"](10, 5); // uses the call operator of the minus<int> object
	binops["/"](10, 5); // uses the call operator of the div object
	binops["*"](10, 5); // calls the lambda function object

	return 0;
}