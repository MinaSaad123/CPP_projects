#include <iostream>
#include <functional>
#include <fstream>
using namespace std;


template <typename T>
bool compare1(T LHS, T RHS) {

	if (less{}(LHS, RHS)) return 1;
	if (less{}(RHS, LHS)) return -1
	
	return 0;
}

template <typename T, typename X>
bool compare2(T LHS, X RHS) {

	return less{}(LHS, RHS);
}

template <typename T> ostream& print(ostream& os, const T& obj)
{
	return os << obj;
}
int main() {

	long lng;

	//compare1(lng, 40); //error cuz conversion in templates is limited.
	compare2(lng, 40); 

	print(cout, 42); // instantiates print(ostream&, int)

	ofstream  f("output.txt");
	print(f, 10); // uses print(ostream&, int); converts f to ostream&
	//Normal conversions are applied to arguments whose type is not a templateparameter.

	return 0;
}