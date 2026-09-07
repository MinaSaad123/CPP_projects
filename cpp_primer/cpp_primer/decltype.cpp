#include <iostream>



int sum()
{
	return 0;
}

int odd[] = { 1,3,5,7,9 };
int even[] = { 0,2,4,6,8 };

// returns a pointer to an array of five int elements
decltype(odd)* arrPtr(int i) /*use decltype to deduce the datatype of pointer to array*/
{
	return (i % 2) ? &odd : &even; // returns a pointer to the array
}

int main()
{
	//Sometimes we want to define a variable with a type that the compiler deduces from an expression but do not want to use that expression to initialize the variable.
	decltype(sum()) x = 4;

	//decltype handle top-level const and reference unlike auto.
	//const
	const int y = 40;
	decltype(y) z = 30; 

	//reference
	const int& ref1 = z;
	//decltype(ref1) ref2;
	
	const int* p = &z;
	decltype(*p) c = z; // error: c is int& and must be initialized

	// decltype of a parenthesized variable is always a reference cuz parenthesizes evaluate the expression.
	int i = 0;
	//decltype((i)) d; // error: d is int& and must be initialized
	decltype(i) e; // ok: e is an (uninitialized) int

	return 0;
}