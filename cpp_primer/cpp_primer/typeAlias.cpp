#include <iostream>

int main()
{
	//A type alias is a type name and can appear wherever a type name can appear:
	//typedef keyword
	typedef double wages; // wages is a synonym for double
	typedef wages base, * p; // base is a synonym for double, p for double*

	typedef int* pint, arr[10];
	pint p;  // same as: int *p;
	arr a;   // same as: int a[10];

	//It can be tempting, albeit incorrect, to interpret a declaration that uses a type alias by conceptually replacing the alias with its corresponding type
	typedef char* pstring;
	const pstring cstr = 0; // cstr is a constant pointer to char
	const pstring* ps; // ps is a pointer to a constant pointer to char

	typedef int int_array[4]; // equivalent typedef declaration
	//=======================================================================================================================================================
	
	//using keyword
	using integer = int; 
	integer val1 = 0;
	//=======================================================================================================================================================

	// Using 'using' (modern)
	using Array10 = int[10];          // Type: array of 10 ints
	using FuncType = Array10*(int);   // Type: function(int) -> Array10*

	// Using 'typedef' (traditional)  
	typedef int Array10[10];           // Type: array of 10 ints
	typedef Array10* (*FuncPtr)(int);  // Type: POINTER to function(int) -> Array10*

	return 0;
}