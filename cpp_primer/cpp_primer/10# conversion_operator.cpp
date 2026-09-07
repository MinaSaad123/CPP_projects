#include <iostream>
using namespace std;

class SmallInt {
public:
	SmallInt(int i = 0) : val(i)
	{
		if (i < 0 || i > 255)
			throw std::out_of_range("Bad SmallInt value");
	}
	operator int() const { return val; } //we cannot put a parameter in operator conversion cuz it is implicity called.
private:
	std::size_t val;
};

int main()
{
	//Conversions to
	//	an array or a function type are not permitted

	//Conversions to pointer types—both data and function pointers—and to reference types are allowed.

	//A conversion function must be a member function, may not specify a return
	//	type, and must have an empty parameter list.The function usually should be
	//	const.	

	SmallInt si;
	si = 4; // implicitly converts 4 to SmallInt then calls SmallInt::operator=
	si + 3; // implicitly converts si to int followed by integer addition

	// the double argument is converted to int using the built-in conversion
	SmallInt si = 3.14; // calls the SmallInt(int) constructor
	// the SmallInt conversion operator converts si to int;
	si + 3.14; // that int is converted to double using the built-in conversion
	
	//cin << i; 
	/*This program attempts to use the output operator on an input stream.There is no <<
		defined for istream, so the code is almost surely in error.However, this code could
		use the bool conversion operator to convert cin to bool.The resulting bool value
		would then be promoted to int and used as the left - hand operand to the built - in
		version of the left - shift operator. The promoted bool value(either 1 or 0) would be
		shifted left 42 positions.*/

	//to solve this problem the new standarad provide explicit
	SmallInt si = 3; // ok: the SmallInt constructor is not explicit
	si + 3; // error: implicit is conversion required, but operator int is explicit
	static_cast<int>(si) + 3; // ok: explicitly request the conversion

	//an explicit conversion will be used
	//	implicitly to convert an expression used as
	//	• The condition of an if, while, or do statement
	//	• The condition expression in a for statement header
	//	• An operand to the logical NOT(!), OR(|| ), or AND(&&) operators
	//	• The condition expression in a conditional(? : ) operator

	//Best Practices
	//	Conversion to bool is usually intended for use in conditions.As a result,
	//	operator bool ordinarily should be defined as explicit.
	
	return 0;
}