#include <iostream>
class Temp
{
private:
	int x;

public:
	Temp() = default;

	Temp& operator=(const Temp& temp) = default;

	Temp(const Temp& temp) = delete;

};

int main()
{
	//[very important note]
	//In essence, the copy-control members are synthesized as deleted when it is
	//impossible to copy, assign, or destroy a member of the class

	return 0;
}