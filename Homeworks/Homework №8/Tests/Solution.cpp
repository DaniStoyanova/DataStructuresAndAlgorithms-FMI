#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<pair<int,int>> my_vec(N);

    for (auto& i : my_vec) 
        cin >> i.first >> i.second;

    sort(my_vec.begin(), my_vec.end());

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> Heap;
    Heap.push(make_pair(my_vec[0].second, my_vec[0].first));

    long long current = my_vec[0].first;
    long long avg = 0;

    int i = 1; 
    while (Heap.empty() == false || i < N) 
    {
        while (i < N && my_vec[i].first <= current)
        {
            Heap.push(make_pair(my_vec[i].second, my_vec[i].first));
            i++; 
        }

        if (Heap.empty() && i < N) {
            current = my_vec[i].first;
            Heap.push(make_pair(my_vec[i].second, my_vec[i].first));
            i++;
        }

        pair<int, int> p = Heap.top();
        Heap.pop();
        current += p.first;
        avg += current - p.second;
    }

    cout << avg / N << "\n";

    return 0;
}
