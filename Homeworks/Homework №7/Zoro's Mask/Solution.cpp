#include <iostream>
#include <set>

using namespace std; 

int Zoro_masks(int Q)
{
    set<int> output;

    for (int i = 0; i < Q; i++)
    {
        int input;
        cin >> input;

        output.insert(input);

        int copy_num = input;
        while (copy_num > 0) {
            copy_num = (copy_num - 1) & input;
            output.insert(copy_num);
        }
    }

    return output.size(); 
}

int main()
{
    int Q; 
    cin >> Q;

    cout << Zoro_masks(Q); 
}
