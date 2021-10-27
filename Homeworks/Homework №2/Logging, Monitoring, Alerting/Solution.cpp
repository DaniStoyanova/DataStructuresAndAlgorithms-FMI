#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int N;
    cin >> N; 

    vector<vector<int>> vec;
    for (int i = 0; i < N; i++)
    {
        int HH, MIN, SS, DD, MM, YYYY; 
        char a; 

        cin >> HH >> a >> MIN >> a >> SS >> DD >> a >> MM >> a >> YYYY; 
        vector<int> my_vec; 
        my_vec.push_back(HH); 
        my_vec.push_back(MIN);
        my_vec.push_back(SS);
        my_vec.push_back(DD);
        my_vec.push_back(MM);
        my_vec.push_back(YYYY);
        my_vec.push_back(i+1);

        vec.push_back(my_vec); 
    }

    std::sort(vec.begin(), vec.end(), [](auto& left, auto& right) {
        if (left[5] != right[5])
            return left[5] < right[5];
        if (left[4] != right[4])
            return left[4] < right[4]; 
        if (left[3] != right[3])
            return left[3] < right[3];
        if (left[0] != right[0])
            return left[0] < right[0];
        if (left[1] != right[1])
            return left[1] < right[1];
        if (left[2] != right[2])
            return left[2] < right[2];
        return left[6] < right[6];
        });

    for (int i = 0; i < N; i++)
    {
        cout << vec[i][6] << endl;
    }
    return 0;
}
