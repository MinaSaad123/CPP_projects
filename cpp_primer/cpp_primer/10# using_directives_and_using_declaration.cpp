#include <iostream>
int main() {

	//[using directives]
	using namespace std; //introduce problem when we use, for instance:)
	//count = 0; //cannot determinate what is the instance of count you mean.

	/*One place where using directives are useful is in the implementation
		files of the namespace itself*/

	//[using declaration]
	//but this problem is solve when we use a using declaration
	using std::count;
	return 0;
}