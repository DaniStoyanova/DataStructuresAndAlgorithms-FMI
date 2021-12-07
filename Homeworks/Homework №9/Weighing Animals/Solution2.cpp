#include <iostream>
#include <map>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    map<long long, int> map1;
    map<long long, int> map2;

    long long output = 0;

    for (int i = 0; i < N; i++) 
    {
        int num;
        cin >> num;

        output += map2[num];
        map2[num * K] += map1[num];
        map1[num * K]++;
    }
    cout << output;

    return 0;
}
