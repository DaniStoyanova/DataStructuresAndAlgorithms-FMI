#include <iostream>
#include <vector>
using namespace std;

const int SIZE = 1000000;
vector<int> tree[SIZE];

void output(int i, int&sum)
{
    if (tree[i].empty())
    {
        return;
    }
    else
    {
        for (size_t j = 0; j < tree[i].size(); j++)
        {
            sum++;
            output(tree[i][j],sum);
        }
    }
}

int main()
{
    int N;
    cin >> N;

    int a, b;

    for (int i = 0; i < N - 1; i++)
    {
        cin >> a >> b;
        tree[a].push_back(b);
    }

    for (int i = 0; i < N; i++)
    {
        int sum = 0;
        output(i, sum); 
        cout << sum << " "; 
    }

    return 0;
}
