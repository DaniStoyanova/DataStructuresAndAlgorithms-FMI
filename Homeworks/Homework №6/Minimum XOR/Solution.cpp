#include <iostream>
#include <set>
#include <iterator>
#include <cmath>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    int num;

    set<int> numbers;
    numbers.insert(0);

    int result = pow(10, 9);

    for (int i = 0; i < N; i++)
    {
        cin >> num;

        auto pair1 = numbers.insert(num);

        set<int>::iterator iterator1 = pair1.first;

        if (next(iterator1) != numbers.end())
        {
            int smaller_XOR = min(*prev(iterator1) ^ *iterator1, *next(iterator1) ^ *iterator1);
            result = min(smaller_XOR, result);
        }
        else
            result = min(*prev(iterator1) ^ *iterator1, result);

        printf("%d\n", result);
    }
}
