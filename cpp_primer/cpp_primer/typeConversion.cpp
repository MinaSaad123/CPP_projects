#include <iostream>

int main()
{
	//there are two types of conversion

	//implicit conversions
	//• in most expressions, values of integral types smaller than int are first
	//promoted to an appropriate larger integral type.
	
	//• In conditions, nonbool expressions are converted to bool.
	
	//• In initializations, the initializer is converted to the type of the variable; in
	//assignments, the right - hand operand is converted to the type of the left - hand.

	//• In arithmetic and relational expressions with operands of mixed types, the types
	//are converted to a common type.

	//explicit conversion
	//there are three type conversion.

	//static_cast use to convert larger size to smaller size.
	int i = 1, j = 2;
	double slope = static_cast<double>(j) / i;

	double d = 234.3;
	void* p = &d; // ok: address of any nonconst object can be stored in a void*
	// ok: converts void* back to the original pointer type
	double* dp = static_cast<double*>(p);

	//const_cast
	const char* pc;
	char* p = const_cast<char*>(pc); // ok: but writing through p is undefined behaviour.


	const char* cp;
	//char* q = static_cast<char*>(cp); // error: static_cast can't cast away const
	static_cast<std::string>(cp); // ok: converts string literal to string
	//const_cast<std::string>(cp); // error: const_cast only changes constness
	
	//reinterpret_cast
	int* ip;
	char* pc = reinterpret_cast<char*>(ip);

	return 0;
}

