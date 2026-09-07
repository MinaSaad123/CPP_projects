#include <iostream>
using namespace std;

template <typename T> class Foo {
public:
	static std::size_t count() { return ctr; }
	// other interface members
private:
	static std::size_t ctr;
	// other implementation members
};
int main()
{
	// instantiates static members Foo<string>::ctr and Foo<string>::count
	Foo<std::string> fs;
	// all three objects share the same Foo<int>::ctr and Foo<int>::count members
	Foo<int> fi, fi2, fi3;

	// and the static data member ctr
	auto ct = Foo<int>::count(); // instantiates Foo<int>::count
	ct = fi.count(); // uses Foo<int>::count
	//ct = Foo::count(); // CE: which template instantiation?

	return 0;
}