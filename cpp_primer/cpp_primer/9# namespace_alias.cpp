#include <iostream>

namespace first {
	int x;
	namespace second {
		int y;
	}
	inline namespace third {
		int z;
	}
}
namespace the_innerMost = first::third; //namespace alias.

int main() {


	return 0;
}