#include <iostream>
using namespace std;

template <typename T>
struct small {
public:
	constexpr bool operator()(const T& LHS, const T& RHS) const {
		return LHS < RHS;
	}
};

//[todo] implement small to handle pointers using forwarding.

int main() {
	static_assert(small<int>()(2, 4) == true, "it is bigger not smaller");

	return 0;
}