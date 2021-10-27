#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int N; 
    cin >> N; 

    string vec; 
    cin >> vec;

    if (N < 1 || N > 10000000)
        return -1; 

    sort(vec.begin(), vec.end()); 

    int index_uppercases = 0; 
    int index_lowercase = 0;

    while (vec[index_uppercases] <= 57 && vec[index_uppercases] >= 48)
    {
        index_uppercases++;
    }

    while ((vec[index_lowercase] <= 57 && vec[index_lowercase] >= 48) || 
           (vec[index_lowercase] >= 65 && vec[index_lowercase] <= 90))
    {
        index_lowercase++;
    }

    if (index_uppercases == N || index_lowercase == N)
    {
        for (int i = 0; i < N; i++)
        {
            cout << vec[i];
        }
    }
    else
    {
        string new_vec;

        for (int i = 0; i < index_uppercases; i++)
            new_vec.push_back(vec[i]);
        for (int i = index_lowercase; i < N; i++)
            new_vec.push_back(vec[i]);
        for (int i = index_uppercases; i < index_lowercase; i++)
            new_vec.push_back(vec[i]);

        for (int i = 0; i < N; i++)
        {
            cout << new_vec[i];
        }
    }

    return 0;
}
