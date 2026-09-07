#include <iostream>
using namespace std;

class base {
public:
	int x;
protected:
	int y;
private:
	int z;
};

class derived1 : public base {
};
class derived2 : protected base {
};
class derived2 : private base {
public:
	//exempting the x from being private.
	using base::x;
};

int main() {
	base* p = new derived1();
	//base* p = new derived2();
	//base* p = new derived3();

	return 0;
}