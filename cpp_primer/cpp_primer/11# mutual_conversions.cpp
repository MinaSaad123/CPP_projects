#include <iostream>
using namespace std;
 
struct B;

struct A {

    A() = default;
    A(const B&);          // A can be created from B
};

struct B {
    B() = default;

    operator A() const;   // B can convert to A
};

int main()
{
    A a;
    B b;

   //a = b;   // ← ambiguity 
   //to solve it we can call conversion operator directly or calling the constructor.
    a = b.operator A();
    a = (A(b));
    //Note that we can’t resolve the ambiguity by using a cast—the cast itself would have
    //    the same ambiguity.

    //[best practise]
    //Never allow more than one numeric conversion.
    //    Never define arithmetic operators if you already have a numeric conversion.
    //    Prefer explicit constructors unless the implicit one is obviously correct.
    //    Only explicit operator bool() is safe and common.

	return 0;
}