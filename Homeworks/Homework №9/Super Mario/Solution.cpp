#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<int> in_room;
    vector<int> needed;
    unordered_map<int, int> keys;

    int counter = 0; 
    int num;
    for (int i = 0; i < N ; i++)
    {
        cin >> num; 
        in_room.push_back(num); 
    }

    for (int i = 0; i < N; i++)
    {
        cin >> num;
        needed.push_back(num);
    }

    for (int i = 0; i < N ; i++)
    {
        keys[in_room[i]]++;

        if (keys.count(needed[i]) == 1)
        {
            if (keys[needed[i]] == 0)
                counter++;
            else
                keys[needed[i]]--;
        }
        else
            counter++;
    }

    cout << counter;
}
