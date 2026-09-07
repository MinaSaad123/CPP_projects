//#include <iostream>
//
//int main()
//{
//	//It is not uncommon to want to store the value of an expression in a variable. To declare the variable, we have to know the type of that expression.When we write a program, it can be surprisingly difficult.
//	//so c++ provide auto.
//
//	double x, y;
//	auto Aval = x + y; //auto will be double.
//
//	//the initializers for all the variables in the declaration must have types that are consistent with each other.
//	auto i = 0, * p = &i; // ok: i is int and p is a pointer to int
//	//auto sz = 0, pi = 3.14; // error: inconsistent types for sz and pi
//
//	int i = 0, & r = i;
//	auto a = r; // a is an int (r is an alias for i, which has type int)
//
//	//auto ignore top-level const and keep the low-level.
//	const int ci = i, & cr = ci;
//	auto b = ci; // b is an int (top-level const in ci is dropped)
//	auto c = cr; // c is an int (cr is an alias for ci whose const is top-level)
//	auto d = &i; // d is an int*(& of an int object is int*)
//	auto e = &ci; // e is const int*(& of a const object is low-level const)
//	
//	//If we want the deduced type to have a top-level const or reference we must say so explicitly
//	const auto f = ci; // deduced type of ci is int; f has type const int
//	auto& g = ci; // g is a const int& that is bound to ci
//	//auto& h = 42; // error: we can't bind a plain reference to a literal
//	const auto& j = 42; // ok: we can bind a const reference to a literal
//	
//	// error: type deduced from i is int; type deduced from &ci is const int
//	//auto& n = i, * p2 = &ci;
//	return 0;
//}