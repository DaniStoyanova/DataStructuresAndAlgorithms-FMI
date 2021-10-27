#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    long long N; 
    cin >> N; 

    long long output = 0; 

    vector<long long> vec; 
    for (long long i = 2; i*i*i <= N; i++) {
        vec.push_back(i * i * i);
    }

    int current_element = vec.size() - 1;

    while (N > 7)
    {
        if (N >= vec[current_element])
        {
            output ++;
            N -= vec[current_element];
        }
        else if (N < vec[current_element])
        {
            current_element--;
        }
    }
    output += N; 

    cout << output << endl;

    return 0; 
}
