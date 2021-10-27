#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iterator>
using namespace std;

vector<int> find_num(vector<int>& my_vec, int ind, int m)
{
    int num = lower_bound(my_vec.begin(), my_vec.end(), ind) - my_vec.begin();
    int second_part; 
    int first_part;

    first_part = num - 1; 
    second_part = num; 
    
    int size = my_vec.size(); 
    
    while(m > 0)
    {
        if (!((abs(my_vec[first_part] - ind) > abs(my_vec[second_part] - ind) && second_part < size) || first_part < 0))
            first_part--; 
        else
            second_part++; 
        
        m--;
    }
    
    return vector<int>(my_vec.begin() + 1 + first_part, second_part + my_vec.begin()); 
}

int main() {
    int N;
    cin >> N;

    int M;
    cin >> M;

    vector<int> themes;
    for (int i = 0; i < N; i++)
    {
        int num;
        cin >> num;
        themes.push_back(num);
    }

    vector<int> teams;
    for (int i = 0; i < M; i++)
    {
        int knowledge;
        cin >> knowledge;
        teams.push_back(knowledge);
    }


    vector<int> output; 
    for (int i = 0; i < M; i++)
    {
        output = find_num(themes, teams[i], 1); 

        for (size_t i = 0; i < output.size(); i++)
            cout << output[i] << endl;
    }

    return 0;
}
