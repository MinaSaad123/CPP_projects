#include <iostream>
using namespace std;

template <typename T>
//we use typename not class to indicate to the compiler it is valueType not variable.
typename T::value_type top(const T& c)
{
	if (!c.empty())
		return c.back();
	else
		return typename T::value_type();
}

int main() {

	return 0;
}