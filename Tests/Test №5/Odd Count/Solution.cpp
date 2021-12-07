#include <iostream>
#include <unordered_map>
#include <unordered_set>

using namespace std;

int main() {
    int N;
    cin >> N; 

    unordered_map<int, int> map1;

    int num; 
    for (int i = 0; i < N; i++)
    {
        cin >> num; 
        map1[num]++; 
    }

    int output = 0; 

    for (auto iter = map1.begin(); iter!=map1.end(); iter++)
    {
        if (iter->second % 2 != 0)
        {
            output += iter->first * iter->second;
        }
    }

    cout << output; 

    return 0;
}
