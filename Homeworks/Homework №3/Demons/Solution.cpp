#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Demon {
    int demon_defense;
    int demon_attack;

    Demon(int defense, int attack): demon_defense(0), demon_attack(0)
    {
        demon_defense = defense; 
        demon_attack = attack; 
    }

    bool operator<(const Demon other) const
    {
        return (this->demon_attack < other.demon_attack && this->demon_defense < other.demon_defense);
    }
};

int lis(vector<Demon> vec){
    vector<Demon> output; 

    size_t i = 0; 
    while (i < vec.size()) {
        vector<Demon>::iterator it = lower_bound(output.begin(), output.end(), vec[i]);
        if (it == output.end()) 
            output.push_back(vec[i]);
        else 
            *it = vec[i];

        i++;
    }

    int size = output.size();
    return size;
}

int main()
{
    int N; 
    cin >> N; 

    vector<Demon> demons;

    for (int i = 0; i < N; i++)
    {
        int defense; 
        int attack; 

        cin >> defense; 
        cin >> attack; 

        Demon demon1(defense, attack);
        demons.push_back(demon1); 
    }

    std::sort(demons.begin(), demons.end(), [](auto& left, auto& right) {
        if (left.demon_defense != right.demon_defense)
            return left.demon_defense < right.demon_defense;
        return left.demon_attack > right.demon_attack;
        });

    cout << lis(demons);
}
