#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	//files modes
	//1. out
	//2. in
	//3. trunc
	//4. app
	//5. binary
	//6. ate

	//[NOTES]
	//1. when we make the file is out. it is by default is trunc.
	ofstream out1("file1"); // out and trunc are implicit
	ofstream out2("file1", ofstream::out); // trunc is implicit
	ofstream out3("file1", ofstream::out | ofstream::trunc);

	//2. to make a file app we should specify first out/in.
	//3. we can use ate or binary with any mode.
	return 0;
}