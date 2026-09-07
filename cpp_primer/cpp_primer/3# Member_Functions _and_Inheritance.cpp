#include <iostream>

int main()
{
	//[note]
	//Any nonstatic member function, other than a constructor, may be virtual
	
	//The virtual keyword appears only on the declaration inside the class and may not be used on a
	//	function definition that appears outside the class body

	//A function that is declared as
	//	virtual in the base class is implicitly virtual in the derived classes as well

	//Virtuals are resolved at run time only if the call is made through a
	//reference or pointer.Only in these cases is it possible for an object’s
	//	dynamic type to differ from its static type.


	return 0;
}