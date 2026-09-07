#include <iostream>
#include <vector>
using namespace std;

class Temp
{
	using SV = std::shared_ptr<std::vector<int>>;
public:
	Temp() { ; }
	Temp(int x = 0, SV sv = make_shared<std::vector<int>>())
	{ 
		this->x = x;
		ptr = sv;
	}
	Temp(const Temp& rhs) : x(rhs.x), ptr(rhs.ptr) { ; }

	Temp& operator=(const Temp& temp)
	{
		//the problem is here
		//deleting the the ptr member before assign to it
		ptr.reset();
		ptr = temp.ptr;
		x = temp.x;

		return *this;
	}

private:
	int x;
	SV ptr;
};

int main()
{


	return 0;
}