#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int N;
    cin >> N;

    vector <pair<pair<double, double>, int>> vec;
    for (int i = 0; i < N; i++)
    {
        pair<double, double> pair1;
        cin >> pair1.first;
        cin >> pair1.second;

        int a = pair1.first;
        pair1.first = pow(pair1.first / 2, 2) / pair1.second;
        pair1.second = a; 

        pair<pair<double, double>, int> boys;
        boys.first = pair1;
        boys.second = i + 1;

        vec.push_back(boys);
    }

    std::sort(vec.begin(), vec.end(), [](auto& left, auto& right) {
        if (left.first.first != right.first.first)
        {
            return left.first.first > right.first.first;
        }
        return left.first.second > right.first.second;
        });

    for (int i = 0; i < N; i++)
    {
        cout << vec[i].second << " "; 
    }

    return 0;
}
