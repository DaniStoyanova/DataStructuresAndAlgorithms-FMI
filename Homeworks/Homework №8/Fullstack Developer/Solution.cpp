#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

void output(vector<vector<int>>& tasks) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    long time = 0, curr = 0, size = tasks.size();

    for (int i = 0; i < size; i++)
        tasks[i].push_back(i);

    sort(tasks.begin(), tasks.end());
    vector<int> output;

    while (curr < size || !pq.empty())
    {
        if (pq.empty())
            time = max(time, (long)tasks[curr][0]);

        while (curr < size && time >= tasks[curr][0])
        {
            pq.push(make_pair(tasks[curr][1], tasks[curr][2]));
            curr++;
        }
        pair<int, int> pair1 = pq.top();
        pq.pop();
        time += pair1.first;
        output.push_back(pair1.second);
    }
    
    for (size_t i = 0; i < output.size(); i++)
        cout << output[i] << " ";
}

int main()
{
    int N; 
    cin >> N; 

    vector<vector<int>> tasks; 

    for (int i = 0; i < N; i++)
    {
        vector<int> vec1(2); 

        int num1, num2; 
        cin >> num1 >> num2; 

        vec1[0] = num1; 
        vec1[1] = num2; 

        tasks.push_back(vec1);
    }

    output(tasks);
}
