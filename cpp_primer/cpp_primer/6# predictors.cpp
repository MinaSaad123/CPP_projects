#include <iostream>
#include <algorithm>	
#include <vector>
#include <list>
#include <numeric>
using namespace std;

bool isshorter(const string& str1, const string& str2)
{
	 return str1.length() < str2.length();
}

int main()
{
	//predictors is unary and binary 
	vector<string> svec{ "mina", "saad", "nazeer" };
	sort(svec.begin(), svec.end(), isshorter);
	
	return 0;
}