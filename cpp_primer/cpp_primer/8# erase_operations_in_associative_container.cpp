#include <iostream>
#include <set>
#include <map>
#include <vector>
using namespace std;


int main()
{

	map<string, int> word_count;
	string word;
	while (cin >> word)
		++word_count[word];

	string removal_word{ "hi" };
	
	//the return is the count of the word's number.
	if (word_count.erase(removal_word))
	{
		//do something
	}



	return 0;
}