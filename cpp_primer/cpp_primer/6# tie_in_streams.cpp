#include <iostream>
using namespace std;

int main()
{
	cin.tie(&cout); // illustration only: the library ties cin and cout for us
	// old_tie points to the stream (if any) currently tied to cin

	ostream* old_tie = cin.tie(nullptr); // cin is no longer tied
	// ties cin and cerr; not a good idea because cin should be tied to cout

	cin.tie(&cerr); // reading cin flushes cerr, not cout
	cin.tie(old_tie); // reestablish normal tie between cin and cout

	return 0;
}