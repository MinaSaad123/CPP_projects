#include <iostream>
int main() {
	//ADL is applied only to function calling in case you pass a class which is inside namespace
	std::string str;
	std::cin >> str; 
	/*it is equalivant to operator>>(istream cin, std::string str) calls.
		but this is  memeber function which is inside an namespace so we have to use before calling a namespace directive or declaration*/
	
	//but because ADL  we don't need to use a using keyword
	
	return 0;
}