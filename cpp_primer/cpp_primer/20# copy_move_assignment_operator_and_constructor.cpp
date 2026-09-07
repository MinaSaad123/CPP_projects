#include <iostream>

class Base {
	//Executing delete on a pointer to base that points to a derived object has
	//	undefined behavior if the base’s destructor is not virtual.
protected:
	std::string name;
public:
	explicit
	Base(std::string str = "") : name(str) { ; }
	//copy constructor
	Base(const Base& RHS) noexcept {
		name = RHS.name;
	}
	//move constructor
	Base(Base&& RHS) noexcept = default;
	//copy assignment operator			
	Base& operator=(const Base& RHS) & noexcept  {
		if (this != &RHS) {
			name = RHS.name;
		}
		return *this;
	}
	Base& operator=(const Base& RHS) && = delete; //delete the assignment capability for rvalue reference.
	Base& operator=(Base&& RHS) /*move assignment operator*/ {
		if (this != &RHS) {
			name = RHS.name;
			RHS.name = "";
		}
		return *this;
	}
	 virtual void print() {
		std::cout << name << std::endl;
	}
	 virtual
		 ~Base() = default;
};
class Derived : public Base {
public:
	//default constructor
	Derived() = default;
	//copy constructor
	Derived(const Derived& D) : Base(D), pval(D.pval) { ; }
	//move constructor
	Derived(Derived&& D) : Base(std::move(D)), pval(D.pval) { ; }
	//copy assignment operator
	Derived& operator=(const Derived& D) & noexcept  {
		if (this != &D) {
			Base::operator=(D);
			this->pval = D.pval;
		}
		return *this;
	}
	Derived& operator=(const Derived& D) && = delete;
	Derived& operator=(Derived&& D) noexcept {
		if (this != &D) 
		{
			Base::operator=(std::move(D));
			this->pval = D.pval;
		}
		return *this;
	}
	virtual ~Derived() override = default;

private:
	int pval = 10;
};
int main()
{

	return 0;
}