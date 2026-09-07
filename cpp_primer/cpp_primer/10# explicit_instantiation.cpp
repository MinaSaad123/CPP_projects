#include <iostream>
using namespace std;

//header  file
template <typename T>
class Car {
	Car() = default;
	Car(std::string);
};
template<typename T>
Car<T>::Car(std::string s) {
	std::cout << s; //print the content of s.
}
//Application.cpp
//include the header file.
//use extern keyword to indicate it is a template
extern template class Car<std::string>; //will be instantiated in another file not here.

//buildTemplate.cpp
//template class Car<std::string>; //this means the instantiated template will be exist here.

//[note] the compiler has no idea which members will be used in other files.
//Therefore:
//Explicit instantiation forces all members of the class template to be instantiated even if it is inline.
//This is the opposite of the normal rule (“only instantiate used members”).
int main() {


	return 0;
}