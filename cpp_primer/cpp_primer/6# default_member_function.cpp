#include <iostream>
using namespace std;

class Temp
{
private:
	int x;

public:
	Temp() = default;

	Temp& operator=(const Temp& temp) = default;

};

Temp::Temp(const Temp& temp) = default; //not inline


int main()
{
	//[note] default in  class means it is inline but outside the class means it is not inline

	return 0;
}