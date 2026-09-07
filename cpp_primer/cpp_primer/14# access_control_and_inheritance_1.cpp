#include <iostream>

class Base {
protected:
	int prot_mem; // protected member
};
class Sneaky : public Base {
	friend void clobber(Sneaky&); // can access Sneaky::prot_mem
	friend void clobber(Base&); // can't access Base::prot_mem
	int j; // j is private by default
};
// ok: clobber can access the private and protected members in Sneaky objects
void clobber(Sneaky& s) { s.j = s.prot_mem = 0; }
// error: clobber can't access the protected members in Base
void clobber(Base& b) { 
	//b.prot_mem = 0; 
}

int main() {

	//can not access the protected member from base object even if we are within a derived class 
}