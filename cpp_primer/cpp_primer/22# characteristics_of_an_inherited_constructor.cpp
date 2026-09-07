#include <iostream>
using namespace std;

//Scenario 1 — Base has a constructor, Derived inherits it
class Base {
public:
    Base(int x) {}
};
class Derived : public Base {
public:
    using Base::Base;  // inherit Base(int)
};

//Scenario 2 — Derived defines a constructor with same signature
class Derived2 : public Base {
public:
    using Base::Base;  // try to inherit Base(int)
   // Derived2(int x) { ; } // user-defined constructor
};

//Scenario 3 — Default constructor(Base has none explicitly)
class Derived3 : public Base {
public:
    using Base::Base;
};

//Scenario 4 — Default, copy, and move constructors are synthesized
class Base2 {
public:
    Base2() {}
    Base2(const Base&) {}
    Base2(Base&&) {}
};

class Derived4 : public Base2 {
public:
    using Base2::Base2;
};
class Base3 {
public:
    Base3(int x, int y = 10) {}
};

class Derived : public Base3 {
public:
    using Base3::Base3;
};

int main() {
	return 0;
}