#include <iostream>
#include <queue>
#include <cmath>
#include <vector>
using namespace std;

struct CompareDur
{
    bool operator()(const pair<int, int>& a, const pair<int, int>& b)
    {
        return a.second > b.second;
    }
};

struct CompareArr
{
    bool operator()(const pair<int, int>& a, const pair<int, int>& b)
    {
        return a.first > b.first;
    }
};

int main()
{
    int N;
    cin >> N;

    vector<int> result;
    priority_queue<pair<int, int>, vector<pair<int, int>>, CompareArr> min_arrival;

    int current = 0;
    long long counter = 0;
    for (int i = 0; i < N; i++)
    {
        cin >> current;
        if (i == 0)
        {
            counter = current;
            result.push_back(current);
            continue;
        }
        min_arrival.push({ i, current });
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, CompareDur> min_duration;
    while (!min_arrival.empty())
    {
        auto curr = min_arrival.top();

        if (curr.first <= counter)
        {
            min_duration.push(curr);
            min_arrival.pop();
            continue;
        }

        if (!min_duration.empty())
        {
            long needed_time = 0;
            needed_time += counter - min_duration.top().first;
            needed_time += min_duration.top().second;
            counter += min_duration.top().second;
            result.push_back(needed_time);
            min_duration.pop();
        }
        else
        {
            counter = min_arrival.top().first;
        }
    }

    while (!min_duration.empty())
    {
        long long needed_time = 0;
        needed_time += counter - min_duration.top().first;
        needed_time += min_duration.top().second;
        counter += min_duration.top().second;
        result.push_back(needed_time);
        min_duration.pop();
    }

    int min_element = result[0], max_element = result[0];

    for (size_t i = 0; i < result.size(); i++)
    {
        if (result[i] < min_element)
        {
            min_element = result[i];
        }

        if (result[i] > max_element)
        {
            max_element = result[i];
        }
    }

    cout << min_element << " " << max_element;
    return 0;
}
