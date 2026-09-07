#include <iostream>

//Unlike most other contexts, however, a name used as a
//template parameter may not be reused within the template
typedef double A;
template <typename A, typename B> void f(A a, B b)
{
	A tmp = a; // tmp has same type as the template parameter A, not double
	double B; // error: redeclares template parameter B
}

int main() {

	return 0;
}