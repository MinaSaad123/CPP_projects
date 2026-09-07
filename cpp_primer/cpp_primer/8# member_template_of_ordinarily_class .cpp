#include <iostream>
#include <memory>
using namespace std;

//this show to use template member for non-template class
struct deleter_class {
	template <typename T> void operator()(T* p) {
		delete p;
	}
};

int main() {
	std::unique_ptr<int, deleter_class> up(new int(), deleter_class());
	return 0;
}