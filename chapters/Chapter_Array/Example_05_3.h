#include "CommonHeader.h"


vector<int> solution(vector<int>& arr);

void Run_Example_05_3()
{
	// input - vector<int>
	vector<int> arr_input = { 1, -5, 2, 4 ,3 };
	vector<int> arr_input2 = { 2, 1, 1, 3 ,5, 4 };
	vector<int> arr_input3 = { 6, 1, 7 };

	vector<int> temp;

	temp = solution(arr_input);

	temp = solution(arr_input2);
	temp = solution(arr_input3);

}

vector<int> solution(vector<int>& arr)
{
	// sort the array in descending order
	sort(arr.begin(), arr.end() );
	// return the sorted array

	for (int value : arr)
	{
		cout << value << ' ';
	}

	cout << '\n';
	return arr;
}