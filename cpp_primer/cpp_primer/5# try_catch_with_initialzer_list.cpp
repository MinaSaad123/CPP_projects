#include <iostream>
using namespace std;

class A {
    string x;
public:
    /*The only way for a constructor to handle an exception from a constructor
        initializer is to write the constructor as a function try block.*/
    A() try : x(std::string()) {
        // body
    }
    catch (...) {
        std::cout << "Caught initializer exception!\n";
    }
};

int main() {
	return 0;
}