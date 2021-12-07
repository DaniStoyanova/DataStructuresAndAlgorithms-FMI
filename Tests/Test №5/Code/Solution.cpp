#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N; 

    unordered_map<string, int> map1;
    vector<string> vec; 

    string word; 
    for (int i = 0; i < N; i++)
    {
        cin >> word; 
        vec.push_back(word);
        map1[word]++; 
    }
    
    for (size_t i = 0; i < vec.size(); i++)
    {
        cout << map1[vec[i]] << " "; 
    }
  
    return 0;
}
