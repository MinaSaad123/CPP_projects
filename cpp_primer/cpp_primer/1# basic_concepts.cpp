#include <iostream>
using namespace std;

int main()
{
	//1- operator overloading is unary and binary operator overloading.
		//if it's a binary operator the left operand is the first paramemter and the right operand are th second parameter.
			//except the call function can takes no parameters.
	//2- there is different between member functions operator overloaded and non member.
		// member function -> a.operator+(b); //always this object is the first parameter.
		// non-member function -> operator+(a, b); 

	//3- cannot redefine a new opertor overloading for built-in type.
	//4- Ordinarily, the comma, address-of, logical AND, and logical OR operators should not be overloaded
	//5- The assignment (=), subscript ([]), call (()), and member access arrow (->) operators must be defined as members.
	//6- The compound-assignment operators ordinarily ought to be members. However, unlike assignment, they are not required to be members
	//7- Symmetric operators—those that might convert either operand, such as the arithmetic, equality, relational, and bitwise operators—usually should be defined as ordinary nonmember functions.
		//it's nonmember function to allow implicity conversions  to built-in-types
			//implicit conversion is allowed throughout the exist of appropriate constructor.

	
	return 0;
}