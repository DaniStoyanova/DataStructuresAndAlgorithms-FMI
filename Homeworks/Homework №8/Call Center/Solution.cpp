#include <set>
#include <iostream>
#include <queue>
#include <utility>
#include <unordered_map>
#include <climits>

using namespace std;

int query(const set<int>& free, int i) {
    if (free.empty())
        return -1; 

    auto later = free.lower_bound(i);

    if (later != free.end())
        return *later; 
    else 
        return *free.begin();
}

void output(int k, vector<int>& call_time, vector<int>& conversation_time) {
    set<int> available;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> num_processed(k, 0);

    for (int i = 0; i < k; i++)
    {
        available.insert(i);
    }

    for (size_t i = 0; i < call_time.size(); i++) {
        int curr_call_time = call_time[i];
        int curr_conversation_time = conversation_time[i];

        while (!pq.empty() && pq.top().first <= curr_call_time) {
            available.insert(pq.top().second);
            pq.pop();
        }

        int to_use = query(available, i % k);
        if (to_use != -1) {
            available.erase(to_use);
            num_processed[to_use] += 1;
            pq.push(make_pair(curr_call_time + curr_conversation_time, to_use));
        }
    }

    int max_val = num_processed[0];
    for (int i = 1; i < k; i++) {
        if (num_processed[i] > max_val) {
            max_val = num_processed[i];
        }
    }

    vector<int> output;
    for (int i = 0; i < k; i++) {
        if (num_processed[i] == max_val) {
            output.push_back(i);
        }
    }

    for (size_t i = 0; i < output.size(); i++)
        cout << output[i] << " ";
}
int main()
{
    int N, K;
    cin >> N >> K;

    vector<int> call_time;
    vector<int> conversation_time;
    for (int i = 0; i < N; i++)
    {
        int num1, num2;
        cin >> num1 >> num2;

        call_time.push_back(num1);
        conversation_time.push_back(num2);
    }

    output(K, call_time, conversation_time);

    return 0;
}
