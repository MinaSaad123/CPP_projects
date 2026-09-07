#include <iostream>
#include <fstream>
#include <iterator>
#include <algorithm>	
#include <vector>
#include <list>
using namespace std;

int main()
{
	//there are three types of iterators
	//insert iterator
	//reverse iterators
	//stream iterator
	//move iterator

	//[stream iterator]
	//ostream_iterator
	//iostream_iterator

	istream_iterator<int> in_iter(cin);
	istream_iterator<int> eof; //it is used as sentinel to indicate the eof.
	ifstream in("file.txt");
	istream_iterator<string> str_it(in); // reads strings from "afile"

	while (in_iter != eof)
	{
		//do something.
	}
		// while there's valid input to read
		// postfix increment reads the stream and returns the old value of the iterator
		// we dereference that iterator to get the previous value read from the stream
	
	vector<string> svec{ "mina", "saad", "nazeer" };
	//ostream iterator can take second argument denoting that after every print print this string
	ostream_iterator<string> out_iter(cout);
	for (auto e : svec)
	{
		*out_iter++ = e; //increment do nothing on the stream so omitting them will not do nothing
	}
	cout << endl;

	return 0;
}