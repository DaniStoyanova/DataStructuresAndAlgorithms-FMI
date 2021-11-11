#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int new_smallest(const vector<int>& numbers, int start, int end, int& index)
{
    int new_index = 0;
    int smallest_num = pow(10, 9) + 1;
    for (int i = start; i <= end; i++)
    {
        if (numbers[i] < smallest_num)
        {
            new_index = i;
            smallest_num = numbers[i];
        }
    }
    index = new_index;

    return smallest_num;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> numbers;

    int N, d;
    cin >> N >> d;

    int smallest_num = pow(10, 9) + 1;
    int index_smallest = 0;
    long long result = 0;

    for (int i = 0; i < N; i++)
    {
        int num;
        cin >> num;
        numbers.push_back(num);
    }

    for (int i = 0; i < d; i++)
    {
        if (numbers[i] < smallest_num)
        {
            smallest_num = numbers[i];
            index_smallest = i;
        }
    }
    result += smallest_num;

    for (int i = d; i < N; i++)
    {
        if (numbers[i] < smallest_num)
        {
            smallest_num = numbers[i];
            index_smallest = i;
        }
        else if (i - d + 1 > index_smallest)
        {
            smallest_num = new_smallest(numbers, i - d + 1, i, index_smallest);
        }
        result += smallest_num;
    }
    printf("%lld", result);

    return 0;
}
