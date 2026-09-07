#include <iostream>


// functions taking const and nonconst references or pointers have different parameters
// declarations for four independent, overloaded functions
void lookup(const int&)
{
	//code
}

void lookup(const int& i)
{
	//code
}

void lookup(int* i)
{
	//code
}

void lookup(const int* i)
{
	//code
}

// these function func are the same.
void func(int* ptr)
{
	//code
}

//void func(int* const ptr)
//{
//
//}

// these function fcn are the same.
int fcn(int i)
{
	//do something
}

//int fcn(const int i)
//{
//	//do something
//}


// bad design: the first parameter should be a const string&
std::string::size_type find_char(std::string& s, char c, std::string::size_type& occurs)
{
	//do something
}
bool is_sentence(const std::string& s)
{
	// if there's a single period at the end of s, then s is a sentence
	std::string::size_type ctr = 0;
	//return find_char(s, '.', ctr) == (s.size() - 1) && ctr == 1; /*you are trying to pass const ref to plain ref*/
}
int main()
{
	//const top-level is the same like plain.
	fcn(5); /*overloading doesn't works with top-level const*/

	//it is a bad practice to add parameter should be const to be plain.
	is_sentence(std::string("ERROR")); 
	return 0;

}