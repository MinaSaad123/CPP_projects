#include <iostream>
using namespace std;

class Foo {
public:
	Foo& operator=(const Foo&) &; // may assign only to modifiable lvalues
		// other members of Foo
};

Foo& Foo::operator=(const Foo& rhs)  & //reference qualifier.
{
	// do whatever is needed to assign rhs to this object
	return *this;
}

int main()
{
	Foo& retFoo(); // returns a reference; a call to retFoo is an lvalue
	Foo retVal(); // returns by value; a call to retVal is an rvalue
	Foo i, j; // i and j are lvalues
	i = j; // ok: i is an lvalue
	retFoo() = j; // ok: retFoo() returns an lvalue
	//retVal() = j; // error: retVal() returns an rvalue
	i = retVal(); // ok: we can pass an rvalue as the right-hand operand to

	//[NOTE]
	//there is another type from reference specifier is rvalue reference (&&).
	//const comes first before the referencr specifier.
	return 0;
}