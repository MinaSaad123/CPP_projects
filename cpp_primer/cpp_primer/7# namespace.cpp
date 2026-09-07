#include <iostream>

//we can put seperated namespace with same name in multiple files.
//for example std we will extend it.
namespace std {
	//put a specialized template inside the namespace std
}

namespace first {
	int x;
	namespace second {
		int y;
	}
	inline namespace third {
		int z;
	}
}
int main() {
	first::x = 0;
	first::second::y = 0;
	first::z = 0; //or first::third::z = 0; --> we was able to do that through namespace is inline

	return 0;
}