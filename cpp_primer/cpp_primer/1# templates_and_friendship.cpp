#include <iostream>
//forward declaration
template <typename T>
class c2;

//when class is non-template.
class c1 {
	//[specific friend]
	friend class c2<c1>; //c2 instantiated from c1 is a friend to the class
	//[general friend]
	template <typename T> friend class c3; //no need for prior forward declaration we all instantiations are friend.
public:
	int x1;
};

template <typename T>
class c2 {
	friend class c3<c2>; //c3 instantiated from c3 is a friend.
	//every instantiation from c2 has the same instance form of c3 as a friend.
	friend class c3<T>;
	template <typename X> friend class c4;
public:
	int x2;
};

template <typename T>
class c3 {
public:
	int x3;
};

template <typename T>
class c4 {
public:
	int x4;
};
int main() {


	return 0;
}