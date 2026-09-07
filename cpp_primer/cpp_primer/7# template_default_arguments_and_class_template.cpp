#include <iostream>
using namespace std;

//if a class template provides default arguments for all of its template
//parameters, and we want to use those defaults, we must put an empty bracket pair
//following the template’s name
template <class T = int> class Numbers { // by default T is int
public:
	Numbers(T v = 0) : val(v) {}
	// various operations on numbers
private:
	T val;
};
Numbers<long double> lots_of_precision;
Numbers<> average_precision; // empty <> says we want the default type

int main() {

	return 0;
}