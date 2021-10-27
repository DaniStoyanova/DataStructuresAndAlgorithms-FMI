#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void merge(int array[], int const left, int const mid, int const right)
{
    int const first_arr = mid - left + 1;
    int const second_arr = right - mid;

    int* left_arr = new int[first_arr];
    int* right_arr = new int[second_arr];

    for (int i = 0; i < first_arr; i++)
        left_arr[i] = array[left + i];
    for (int j = 0; j < second_arr; j++)
        right_arr[j] = array[mid + 1 + j];

    int index_first_arr = 0;
    int index_second_arr = 0;
    int index_merged_arr = left; 

    while (index_first_arr < first_arr && index_second_arr < second_arr) {
        if (left_arr[index_first_arr] <= right_arr[index_second_arr]) {
            array[index_merged_arr] = left_arr[index_first_arr];
            index_first_arr++;
        }
        else {
            array[index_merged_arr] = right_arr[index_second_arr];
            index_second_arr++;
        }
        index_merged_arr++;
    }
    
    while (index_first_arr < first_arr) {
        array[index_merged_arr] = left_arr[index_first_arr];
        index_first_arr++;
        index_merged_arr++;
    }
    
    while (index_second_arr < second_arr) {
        array[index_merged_arr] = right_arr[index_second_arr];
        index_second_arr++;
        index_merged_arr++;
    }
}

void mergeSort(int array[], int const begin, int const end)
{
    if (begin >= end)
        return;

    int mid = begin + (end - begin) / 2;
    mergeSort(array, begin, mid);
    mergeSort(array, mid + 1, end);
    merge(array, begin, mid, end);
}

int main()
{
    int N;
    cin >> N; 

    int* arr; 
    arr = new int[N]; 

    for (int i = 0; i < N; i++)
    {
        int num; 
        cin >> num;
        arr[i] = num; 
    }

    int K; 
    cin >> K; 

    mergeSort(arr, 0, N - 1); 

    long int sum = 0; 

    if (K <= N)
    {
        for (int i = 0; i < K; i++)
            sum += arr[i];
    }

    cout << sum << endl; 

    return 0;
}
