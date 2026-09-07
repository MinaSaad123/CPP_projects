#include <iostream>

int main()
{
	//Classes that define both an arithmetic operator and the related compound
	//	assignment ordinarily ought to implement the arithmetic operator by using
	//	the compound assignment.

	//If a class defines operator==, it should also define operator!=.Users will
	//	expect that if they can use == then they can also use != , and vice versa

	//[important]
	//Consistency with ==
	//	If your class also has == defined, you must ensure that < and == agree :
	//Rule: If a == b is true, then neither a < b nor b < a should be true.
	//	Rule : If a != b, then at least one of a < b or b < a should be true.

	//Assignment operators must, and ordinarily compound - assignment operators
	//	should, be defined as members.These operators should return a reference to
	//	the left - hand operand.
	return 0;
}