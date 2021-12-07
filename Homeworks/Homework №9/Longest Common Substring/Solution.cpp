#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int output(string s1, string s2, int s1_size, int s2_size)
{
    auto arr = new int[s2_size + 1][2];
    int counter = 0;

    for (int i = 0; i < s1_size; i++) {
        for (int j = 0; j < s2_size; j++) {
            if (s1[i] == s2[j]) {
                arr[j + 1][(i+1) % 2] = arr[j][(i) % 2] + 1;
                counter = max(arr[j + 1][(i + 1) % 2], counter);
            }
            else
                arr[j + 1][(i + 1) % 2] = 0;
        }
    }
    return counter;
}

int main()
{
    string s1, s2;
    cin >> s1 >> s2;

    int s1_size = s1.length();
    int s2_size = s2.length();

    cout << output(s1, s2, s1_size, s2_size);
    return 0;
}
