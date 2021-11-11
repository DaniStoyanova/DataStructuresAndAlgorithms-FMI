#include <iostream>
#include <list>
#include <algorithm>
#include <vector>
using namespace std; 

#define endl '\n'

void print(std::list<int>& list)
{
    for (auto i : list) {
        std::cout << i << " ";
    }
}

void new_current(list<int>& balls, int& counter, list<int>::iterator& current)
{
    if (balls.size() - 1 == 0)
    {
        balls.erase(current);
        counter++;
        return; 
    }
    else if (current == prev(balls.end()))
    {
        list<int>::iterator prev_curr = prev(current);
        balls.erase(current);
        current = prev_curr;
        counter++;
    }
    else
    {
        list<int>::iterator next_curr = next(current);
        balls.erase(current);
        current = next_curr;
        counter++;
    }
}

void erase_left_balls(list<int>& balls, int& counter, list<int>::iterator current)
{
    while (current != balls.begin() && *prev(current) == *current)
    {
        if (prev(current) == balls.begin())
        {
            list<int>::iterator start = prev(current);
            balls.begin() = next(balls.begin());
            balls.erase(start);
        }
        else
            balls.erase(prev(current));

        counter++;
    }
}

void erase_right_balls(list<int>& balls, int& counter, list<int>::iterator current)
{
    while (next(current) != balls.end() && *next(current) == *current)
    {
        balls.erase(next(current));
        counter++;
    }
}

void erase_the_rest(list<int>& balls, int& counter, list<int>::iterator current)
{
    if (balls.size() < 3)
        return;
    else if (current == balls.begin())
        return; 
    else if (current != balls.end() && next(current) != balls.end() && prev(current) != balls.end() && *current == *next(current) && *current == *prev(current))
    {
        erase_right_balls(balls, counter, current);
        erase_left_balls(balls, counter, current);
    }
    else if (current != balls.begin() && prev(current) != balls.begin() && *current == *prev(current) && *current == *prev(prev(current)))
    {
        erase_left_balls(balls, counter, current);
    }
    else
        return;

    if (current == prev(balls.end()))
    {
        new_current(balls, counter, current);
        return;
    }
    new_current(balls, counter, current);
    erase_the_rest(balls, counter, current);
}

void erase(list<int>& balls, int& counter, list<int>::iterator current)
{
    if (current != balls.end() && next(current) != balls.end() && prev(current) != balls.end() && *current == *next(current) && *current == *prev(current))
    {
        erase_right_balls(balls, counter, current);
        erase_left_balls(balls, counter, current);
    }
    else if (current != balls.end() && next(current) != balls.end() && next(next(current)) != balls.end() && *current == *next(current) && *current == *next(next(current)))
    {
        erase_right_balls(balls, counter, current);
    }
    else if (prev(current) != balls.begin() && *current == *prev(current) && *current == *prev(prev(current)))
    {
        erase_left_balls(balls, counter, current);
    }
    else return;

    if (current == prev(balls.end()))
    {
        new_current(balls, counter, current);
        return;
    }
    new_current(balls, counter, current);
    erase_the_rest(balls, counter, current);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; 
    cin >> N; 

    list<int> balls; 
    vector<list<int>::iterator> ptrs;

    for (int i = 0; i < N; i++)
    {
        int num;
        cin >> num;
        
        balls.push_back(num);
        ptrs.push_back(prev(balls.end())); 
    }
    
    int Q; 
    cin >> Q; 

    for (int i = 0; i < Q; i++)
    {
        int index, color;
        cin >> index >> color; 
        if (balls.size() == 0)
        {
            cout << "Game Over" << endl;
        }
        else
        {
            int counter = 0;
            balls.insert(next(ptrs[index]), color);
            ptrs.push_back(next(ptrs[index]));

            erase(balls, counter, next(ptrs[index]));
            cout << counter << endl;
        }
    }

    if (balls.size() == 0)
        cout << "-1"; 
    else
        print(balls); 

    return 0;
}
