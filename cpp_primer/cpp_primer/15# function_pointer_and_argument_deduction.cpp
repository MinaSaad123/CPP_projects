#include <iostream>
using namespace std;

template <typename T>
auto compare(T arg1, T arg2) -> bool {
	if (arg1 < arg2) return 1;
	if (arg2 < arg1) return -1;
	return 0;
}
template <typename T>
int sum(const T& arg1, const T& arg2) {
	return arg1 + arg2;
}
void func(int(*ptr)(const string&, const string&)) {
	ptr("Mina", " Saad");

}
void func(int(*ptr)(const int&, const int&)) {
	ptr(1,3);
}
int main() {

	//type of argument 1,2 specify the deduce type from the template.
	bool (*ptr)(int, int) = compare;

	//func(compare); // error: which instantiation of compare?
	func(sum<int>);
	return 0;
}