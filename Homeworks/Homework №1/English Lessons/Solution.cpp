#include <iostream>
#include <string>

using namespace std; 

int main()
{
	string word; 
	cin >> word; 
	int size = word.size();
	
	unsigned int N; 
	cin >> N; 

	char S;
	cin >> S;

	if (N < 1 || N > pow(10,9) || size < 1 || size > 100)
	{
		return -1; 
	}

	int counter_word = 0; 
	for (int i = 0; i < size; i++)
	{
		if (word[i] == S)
			counter_word++;
	}

	int counter = 0; 

	if (N % size == 0)
	{
		counter = counter_word * (N / size);
	}
	else
	{
		counter = counter_word * (N / size); 
		for (int i = 0; i < N % size; i++)
		{
			if (word[i] == S)
				counter++; 
		}
	}
	cout << counter; 

}
