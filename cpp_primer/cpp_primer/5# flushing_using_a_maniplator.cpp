#include <iostream>
using namespace std;

int main()
{
	std::cout << std::unitbuf; //makes the buffer is unit

	std::cout << std::nounitbuf; //return the buffer as it was.

	std::cerr << "error"; //cerr is by default unitbuf.


}