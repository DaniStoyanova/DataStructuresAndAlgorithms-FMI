#include <iostream>
#include <vector>
#include <math.h>   
#include <algorithm>

using namespace std; 

int main()
{
	int N; 
	cin >> N; 
	vector<int> arr;
	int input;

	if (N < 1 || N > pow(10, 6))
		return -1; 

	for (int i = 0; i < N; i++)
	{
		cin >> input; 
		if (input < -pow(2, 31) || input > pow(2, 31) - 1)
			return -1; 
		else
			arr.push_back(input);
	}

	sort(arr.begin(), arr.end()); 

	auto one = find(arr.begin(), arr.end(), 1);

	int index; 
	if (one != arr.end())
	{
		index = one - arr.begin();
	}
	else {
		cout << 1;
	}

	for (int i = index + 1; i < N; i++)
	{
		if (arr[i] != arr[i - 1] && arr[i] != arr[i - 1] + 1)
		{
			cout << arr[i - 1] + 1; 
			break; 
		}
		else if (i == N - 1)
		{
			cout << arr[i] + 1; 
		}
	}
}
