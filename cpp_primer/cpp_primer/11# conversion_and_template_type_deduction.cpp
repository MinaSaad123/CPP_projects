#include <iostream>
using namespace std;

template <typename T> T fobj(T, T); // arguments are copied
template <typename T> T fref(const T&, const T&); // references
string s1("a value");
const string s2("another value");

int main() {
	fobj(s1, s2); // calls fobj(string, string); const is ignored
	fref(s1, s2); // calls fref(const string&, const string&)
	// uses premissible conversion to const on s1
	int a[10], b[42];
	fobj(a, b); // calls f(int*, int*)

	//fref(a, b); // error: array types don't match
	//The call to fref, however, is illegal.When the parameter is a
	//	reference, the arrays are not converted to pointers.The types of a
	//	and b don’t match, so the call is in error.
	return 0;
}