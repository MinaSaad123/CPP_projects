#include <iostream>
#include <algorithm>	
#include <vector>
#include <numeric>
using namespace std;

int main()
{
	//algorithms could be with one sequence or two sequences the second one denotes by one iterators or two
	
	vector<int> vec(5, 10);
	fill(vec.begin(), vec.end(), 0); // reset each element to 0
	// set a subsequence of the container to 10
	fill(vec.begin(), vec.begin() + vec.size() / 2, 10);

	//takes iterators and the size and the third elements is the value to be set
	fill_n(vec.begin(), vec.size(), 0);

	//tranform function take input range and destination and callable function whether it is predictor or a lambda expression
	//if the destination is the begin then each element in the input range the result from lambda expression will be assign to it

	
	return 0;
}