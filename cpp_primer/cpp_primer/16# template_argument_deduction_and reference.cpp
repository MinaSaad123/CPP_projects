#include <iostream>

template <typename T>
void mirror(T&& x) {
	return x;
}
int main() {

	int x;
	int& y = x;
	//[note] rvalue reference template parameter can take rvalue or lvalue.
	mirror(y); //pass lvalue
	mirror(50); //pass rvalue
	//Reference collapsing applies only when a reference to a reference is created
	//	indirectly, such as in a type alias or a template paramete

	//X&&, X&&&, and X&&& all collapse to type X&
	//The type X&&&& collapses to X&&
	return 0;
}