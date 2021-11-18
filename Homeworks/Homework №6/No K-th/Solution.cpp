#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main()
{
    int N;
    cin >> N;
    
    vector<pair<int, int>> numbers(N);
    numbers[0].first = 0;
    numbers[0].second = 0;
    for (int i = 0; i < N; i++)
    {
        int num1, num2;
        cin >> num1 >> num2;
        if (num1 != -1)
        {
            numbers[num1].first = numbers[i].first - 1;
            numbers[num1].second = numbers[i].second - 1;
        }
        if (num2 != -1)
        {
            numbers[num2].first = numbers[i].first + 1;
            numbers[num2].second = numbers[i].second - 1;
        }
    }

    vector<pair<int, int>> new_vec;

    for (int i = 0; i < N; i++)
    {
        bool hasDuplicate = false;
        for (size_t j = 0; j < new_vec.size(); j++)
        {
            if (numbers[i].first == new_vec[j].second)
            {
                hasDuplicate = true;
                break;
            }
        }

        if (hasDuplicate == false)
        {
            pair<int, int> pair1;
            pair1.second = numbers[i].first;
            pair1.first = i;
            new_vec.push_back(pair1);
        }
    }

    std::sort(new_vec.begin(), new_vec.end(), [](auto& left, auto& right) {
            return left.second < right.second;
        });

    for (size_t i = 0; i < new_vec.size(); i++)
    {
        cout << new_vec[i].first << " ";
    }

    return 0;
}
