#include <cmath>
#include <cstdio>
#include <vector>
#include <stack>
#include <iostream>
#include <algorithm>
using namespace std;


int main()
{
    int N;
    cin >> N;

    vector<int> all_players;
    vector<int> period;
    for (int i = 0; i < N; i++)
    {
        int num;
        cin >> num;
        all_players.push_back(num);
        period.push_back(0);
    }

    int minimum = all_players[0];
    int result = 0;
    deque<int> my_stack;

    my_stack.push_back(0);

    for (size_t i = 1; i < all_players.size(); i++)
    {
        if (all_players[i] > all_players[i - 1])
            period[i] = 1;

        minimum = min(minimum, all_players[i]);

        while (my_stack.size() != 0 && !(all_players[my_stack.back()] < all_players[i]))
        {
            if (all_players[i] > minimum)
                period[i] = max(period[i], period[my_stack.back()] + 1);

            my_stack.pop_back();
        }

        result = max(result, period[i]);

        my_stack.push_back(i);
    }

    printf("%d", result);

    return 0;
}
