#include <iostream>
using namespace std;

int main() {
	//noexcept preceds override and final and follow by references qualifier or const
	//noexcept can be with pointer to function but not with type alias.
	int (*ptr1)(int) noexcept = nullptr;
	int (*ptr2)(int) = nullptr;
	int (*ptr3)(int) = nullptr;
	 
	//ptr1 = ptr2; //it is problem cuz we pass noexcept function to might except function

	//specifing noexcept promise this function will not throw an exception.
	
	/*The compiler in general cannot, and does not, verify exception specifications
		at compile time*/

	//noexcept can act like an operator.
	void f() noexcept(noexcept(main())); // f has same exception specifier as main

	/*If a virtual function includes a promise not to throw, the inherited virtuals must also
		promise not to throw.On the other hand, if the base allows exceptions, it is okay for
		the derived functions to be more restrictive and promise not to throw*/
	
	/*When the compiler synthesizes the copy - control members, it generates an exception
		specification for the synthesized member.If all the corresponding operation for all the
		members and base classes promise not to throw, then the synthesized member is
		noexcept*/

	return 0;
}