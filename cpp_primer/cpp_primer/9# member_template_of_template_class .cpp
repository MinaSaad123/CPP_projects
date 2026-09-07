#include <iostream>
using namespace std;

template <typename T>
class Car {
	template <typename X> Car(std::string, const X);
};

template <typename T>
template <typename X>
Car<T>::Car(std::string s, const X x) {
	T name(s);
}

int main() {

	return 0;
}