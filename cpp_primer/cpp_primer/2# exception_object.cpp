#include <iostream>
using namespace std;

struct temp1 {
	int x;
};

struct temp2 : temp1 {
	int y;
};

int main()
{
	/*The exception object resides in space, managed by the compiler, that is guaranteed
		to be accessible to whatever catch is invoked.The exception object is destroyed
		after the exception is completely handled.*/

	//it is always better to not use exception object as:-
		//1- pointer to local variable
		//2- reference to local variable
		//3- local variable in general
		//4- polymorphism, that is because using it make object slicing.

	//the correct way is 
	try {
		throw std::string("error"); // rvalue, even if it is a derived class it will works "not slicing".

	}
	catch (const std::string& e) {
		std::cout << e;
	}

	/*if the catch parameter has a
		nonreference type, then the parameter in the catch is a copy of the exception
		object; changes made to the parameter inside the catch are made to a local copy,
		not to the exception object itself.*/
	try {
		throw std::string("error"); 
	}
	catch (std::string e) {
		e + "2"; 
		std::cout << e;
	}

	/*Best Practices
		Ordinarily, a catch that takes an exception of a type related by inheritance
		ought to define its parameter as a reference.*/

	try {
		throw temp2();
	}
	catch (temp2& e) /*no slicing is exist*/ {
		//do anything.
	}
	return 0;
}