#include <iostream>
#include <map>
using namespace std;

struct Value {
    long long value = 0;
};

int main() {
    int N, K;
    cin >> N >> K;

    map<long long, Value> map1;
    map<long long, Value> map2;

    long long output = 0;

    for (int i = 0; i < N; i++) 
    {
        int num;
        cin >> num;

        output += map2[num].value;
        map2[num * K].value += map1[num].value;
        map1[num * K].value++;
    }

    cout << output;

    return 0;
}
