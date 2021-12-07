#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


void merge(vector<int>& vec, int start, int mid, int end) {
    vector<int> new_vec;

    int i = start;
    int j = mid + 1;

    while (i <= mid && j <= end)
    {
        if (vec[i] <= vec[j]) {
            new_vec.push_back(vec[i]);
            i++;
        }
        else {
            new_vec.push_back(vec[j]);
            j++;
        }
    }

    while (i <= mid) {
        new_vec.push_back(vec[i]);
        i++;
    }

    while (j <= end) {
        new_vec.push_back(vec[j]);
        j++;
    }

    for (int i = start; i <= end; i++)
        vec[i] = new_vec[i - start];

}

void MergeSort(vector<int>& vec, int start, int end) {
    if (start < end) {
        int mid = (start + end) / 2;
        MergeSort(vec, start, mid);
        MergeSort(vec, mid + 1, end);
        merge(vec, start, mid, end);
    }
}

int main()
{
    int N;
    cin >> N;

    vector<int> vec;

    for (int i = 0; i < N; i++)
    {
        int num;
        cin >> num;
        vec.push_back(num);
    }

    MergeSort(vec, 0, N - 1);

    for (int i = 0; i < N; i++)
    {
        if (vec[i] == vec[i + 1])
            continue;
        else
            cout << vec[i] << " "; 
    }

    return 0;
}
