#include <iostream>	

int main()
{
	//multidimensions array
	int arr[3][4] = { 1, 2, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13 };

	//how to bind to row
	int (&row1)[4] = arr[1];

	//To use a multidimensional array in a range for, the loop control variable for all but the innermost array must be references.	//first case
	for (auto& row2 : arr) //take a reference of the row (&row1)[4]
	{
		for (auto& col2 : row2) //take a reference of the element in the row.
		{
			col2 = col2 + 1;
		}
	}

	//second case
	for (const auto& row2 : arr) //take const a reference of the row (&row1)[4]
	{
		for (auto col2 : row2) //take a copy of the element in the row.
		{
			col2 = col2 + 1;
		}
	}

	//third case
	//for (auto row2 : arr) //take a pointer to first element of array
	//{
	//	for (auto col2 : row2) //the inner loop is illegal cuz we cannot iterate over a int*.
	//	{
	//		col2 = col2 + 1;
	//	}
	//}
	return 0;
}