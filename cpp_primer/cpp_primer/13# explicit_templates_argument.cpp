#include <iostream>
using namespace std;

template <typename T1, typename T2, typename T3>
T1 sum(T2 LHS, T3 RHS) {
	return LHS + RHS;
}
template <typename T1, typename T2, typename T3>
T3 alternative_sum(T2 LHS, T1 RHS) {
	return LHS + RHS;
}
int main() {
	long long  val1 = 3;
	float val2 = 7.54;

	//sum(val1, val2); //CE: cannot deduce the template T1 type
	sum<float>(val1, val2); //we use explicit template argument.
	alternative_sum<float>(val1, val2); //we use explicit template argument.

	//Normal Conversions Apply for Explicitly Specified Arguments
	sum<float, float, float>(val1, val2);
	return 0;
}