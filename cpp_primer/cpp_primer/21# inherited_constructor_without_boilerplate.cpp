#include <iostream>
#include <string>

class Base {
protected:
    std::string name;

public:
    // Use defaulted default, copy, and move constructors
    explicit Base(std::string str = "") : name(std::move(str)) {}
    Base(const Base&) noexcept = default;
    Base(Base&&) noexcept = default;

    // Copy/move assignment operators
    Base& operator=(const Base&) &noexcept = default; // lvalue copy assignment
    Base& operator=(const Base&) && = delete;          // forbid rvalue copy assignment
    Base& operator=(Base&&) &noexcept = default;      // move assignment for lvalues

    virtual void print() {
        std::cout << name << std::endl;
    }

    virtual ~Base() = default;
};

class Derived : public Base {
    int pval = 10;

public:
    // Inherit Base constructors
    //[note] using keyword with constructor doesn't change the access level of the constructor

    using Base::Base;

    // Use defaulted special member functions
    Derived() = default;
    Derived(const Derived&) noexcept = default;
    Derived(Derived&&)  noexcept = default;

    Derived& operator=(const Derived&) &noexcept = default;
    Derived& operator=(const Derived&) && = delete;  // forbid rvalue copy assignment
    Derived& operator=(Derived&&) &noexcept = default;

    ~Derived() override = default;
};

int main() {
    Base b1("Hello");
    Base b2 = b1;  // copy
    Base b3 = std::move(b1); // move

    Derived d1;
    Derived d2 = d1;          // copy
    Derived d3 = std::move(d2); // move

    return 0;
}
