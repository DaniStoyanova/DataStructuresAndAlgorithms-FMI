#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    string S;
    cin >> S;
    vector<pair<char, int>> lectures;
    for (size_t i = 0; i < S.length(); i++)
    {
        bool hasDuplicate = false;
        for (size_t j = 0; j < lectures.size(); j++)
        {
            if (S[i] == lectures[j].first)
            {
                lectures[j].second = -1;
                hasDuplicate = true;
                break;
            }
        }
        if (!hasDuplicate)
        {
            pair<char, int> pair1;
            pair1.first = S[i];
            pair1.second = i;
            lectures.push_back(pair1);
        }
    }

    for (size_t i = 0; i < lectures.size(); i++)
    {
        if(lectures[i].second != -1)
            cout << lectures[i].second << " ";
    }
    return 0;
}
