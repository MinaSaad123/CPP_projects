#include <iostream>
class mini1
{
	int i;
};


int main()
{
	//there is a synthesized default constructor.
	mini1 small_class; //invok synthesized default constructor.
	//[NOTE] The compiler generates a default constructor automatically only if a class declares no constructors.

	return 0;
}