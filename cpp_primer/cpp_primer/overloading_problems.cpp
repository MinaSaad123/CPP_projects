#include <iostream>
typedef std::string::size_type sz;

std::string read()
{
	//code
}

void print(const std::string&)
{
	//code
}

void print(double)
{
	//code
}

//if we declare a name in an inner scope, that name hides uses of that name declared in an outer scope.Names do not overload across scopes :
void fooBar(int ival)
{
	bool read = false; // new scope: hides the outer declaration of read
	//std::string s = read(); // error: read is a bool variable, not a function
	// bad practice: usually it's a bad idea to declare functions at local scope
	void print(int); // new scope: hides previous instances of print
	//print("Value: "); // error: print(const string &) is hidden
	print(ival); // ok: print(int) is visible
	print(3.14); // ok: calls print(int); print(double) is hidden
}
//============================================================================================================================================
std::string screen(sz, sz, char = ' ');
//std::string screen(sz, sz, char = '*'); // error: redeclaration
std::string screen(sz = 24, sz = 80, char); // ok: adds default
std::string screen(sz i1, sz i2, char c)
{

}
//============================================================================================================================================
//Local variables may not be used as a default argument.Excepting that restriction, a default argument can be any expression that has a type that is convertible to the type of the parameter :
int gval;
//std::string screen(sz = 24, sz = gval, char); // the default is correct but there is a problem of redeclaration.


int main()
{


	return 0;
}

