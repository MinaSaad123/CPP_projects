#include <iostream>

//constexpr function should have one return and the return should be literal
constexpr int new_sz() { return 42; }
constexpr int foo = new_sz(); // ok: foo is a constant expression
constexpr size_t scale(size_t cnt) { return new_sz() * cnt; }
//[NOTE] constexpr should is implicity inline.
//[NOTE] inline and constexpr functions may be defined multiple times in the program
int main()
{

	return 0;
}