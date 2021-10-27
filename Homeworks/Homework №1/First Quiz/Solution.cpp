#include <iostream>
#include <vector>
#include <string>

using namespace std; 

int main()
{
	std::string str;
	std::cin >> str;

	int size = str.size(); 

	if (size < 1 || size > pow(10, 6))
		return -1; 

	char letter; 
	cin >> letter; 

	vector<int> vec;
	bool first_letter_passed = false; 
 
	for (int i = 0; i < size; i++)
	{
		if (str[i] == letter && first_letter_passed == false)
		{
			for (int j = 0; j < size; j++)
			{
				vec.push_back(abs(i - j));
			}
			first_letter_passed = true;
		}
		if (str[i] == letter && first_letter_passed == true)
		{
			for (int j = 0; j < size; j++)
			{
				if (vec[j] > abs(i - j))
				{
					vec[j] = abs(i - j); 
				}
			}
		}
	}

	for (int j = 0; j < size; j++)
	{
		cout << vec[j] << " ";
	}
}
