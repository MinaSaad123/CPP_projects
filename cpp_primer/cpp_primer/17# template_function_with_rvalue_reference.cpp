#include <iostream>
using namespace std;

template <typename T>
int mirror(T&& x) {
	T y = x;
	y = 50;

	if (x == y) {
		//then T is deduce as int&
		return 1;
	}
	else {
		//then T deduc a int not int&.
		return 0;
	}
}

int main() {
	int val;
	std::cout << ((mirror(50) == 1) ? "it is deduce as reference" : "it is not a reference") << std::endl;
	std::cout << ((mirror(val) == 1) ? "it is deduce as reference" : "it is not a reference") << std::endl;
	return 0;
}