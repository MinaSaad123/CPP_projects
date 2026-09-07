#include <iostream>

struct cmini
{
	//friend std::istream& read(std::istream&, cmini&); 
public:
	int x = 3; //in-class initializer.
	int y; //garbage value.

	cmini() = default;

	cmini(int x, int y) : x(x), y(y)
	{

	}
};

//friend std::istream& read(std::istream&, cmini&); 
//[NOTE] we declare friend function inside the class time and another time outside the class to make it visability to user of the class in header file.
//=====================================================================================================================================================

struct X 
{
	friend void f() 
	{ /* friend function can be defined in the class
	body */
	}

	X() { f(); } // error: no declaration for f
	void g();
	void h();
};


void X::g() { return f(); } // error: f hasn't been declared
void f(); // declares the function defined inside X
void X::h() { return f(); } // ok: declaration for f is now in scope


int main()
{

	cmini mini1; //trigger default constructor.
	cmini mini2{ 1, 3 }; //trigger initializer list constructor.

	return 0;
}


