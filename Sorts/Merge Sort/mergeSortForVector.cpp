void Merge(vector<int>& vec, int start, int mid, int end) {
    vector<int> temp;

    int i, j;
    i = start;
    j = mid + 1;

    while (i <= mid && j <= end) 
    {
        if (vec[i] <= vec[j]) {
            temp.push_back(vec[i]);
            ++i;
        }
        else {
            temp.push_back(vec[j]);
            ++j;
        }
    }

    while (i <= mid) {
        temp.push_back(vec[i]);
        ++i;
    }

    while (j <= end) {
        temp.push_back(vec[j]);
        ++j;
    }

    for (int i = start; i <= end; ++i)
        vec[i] = temp[i - start];

}

void MergeSort(vector<int>& vec, int start, int end) {
    if (start < end) {
        int mid = (start + end) / 2;
        MergeSort(vec, start, mid);
        MergeSort(vec, mid + 1, end);
        Merge(vec, start, mid, end);
    }
}
