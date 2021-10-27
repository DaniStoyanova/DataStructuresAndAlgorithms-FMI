#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int elements_number;
    cin >> elements_number;

    int requests_number;
    cin >> requests_number;

    vector<long> elements;
    for (int i = 0; i < elements_number; i++)
    {
        long num;
        cin >> num;
        elements.push_back(num);
    }

    vector<pair<long, long>> requests;
    for (int i = 0; i < requests_number; i++)
    {
        long num1;
        long num2;

        cin >> num1;
        cin >> num2;

        pair<long, long> pair1;
        pair1.first = num1;
        pair1.second = num2;

        requests.push_back(pair1);
    }

    sort(elements.begin(), elements.end());

    vector<long long> sums;

    sums.push_back(elements[0]);
    for (int i = 1; i < elements_number; i++)
    {
        sums.push_back(elements[i] + sums[i - 1]);
    }

    for (size_t i = 0; i < requests.size(); i++)
    {
        int last_index = 0;
        int sum = requests[i].first;
        int counter = 0;

        auto up = std::upper_bound(elements.begin(), elements.end(), requests[i].second);
        last_index = up - elements.begin() - 1;

        if (sums[last_index] <= requests[i].first)
        {
            counter = last_index + 1;
        }
        else
        {
            for (int j = last_index; j >= 0; j--)
            {
                sum -= elements[j];
                if (sum >= 0)
                    counter++;
                else
                    break;
            }
        }

        printf("%d\n", counter);
    }

    return 0;
}
