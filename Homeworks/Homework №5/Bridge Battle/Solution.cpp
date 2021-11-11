#include <cmath>
#include <cstdio>
#include <vector>
#include <stack>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int N;
    cin >> N;
    stack<int> fighters;
    for (int i = 0; i < N; i++)
    {
        int num;
        cin >> num;

        bool shouldnt_push = false;
        while ((!(fighters.empty())) && fighters.top() >= 0 && num < 0)
        {
            if (fighters.top() < num * (-1))
            {
                fighters.pop();
            }
            else if (fighters.top() == num*(-1))
            {
                fighters.pop();
                shouldnt_push = true;
                break;
            }
            else
            {
                shouldnt_push = true;
                break;
            }
        }

        if (shouldnt_push == false)
            fighters.push(num);
    }
    stack<int> result;
    while(fighters.size() != 0)
    {
        result.push(fighters.top());
        fighters.pop();
    }

    while(result.size() != 0)
    {
        cout << result.top() << " "; 
        result.pop();
    }

    return 0;
}
