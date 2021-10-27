int Partition(vector<int>& vec, int start, int end) {

    int pivot = end;
    int j = start;
    for (int i = start; i < end; ++i) {
        if (vec[i] < vec[pivot]) {
            swap(vec[i], vec[j]);
            j++;
        }
    }
    swap(vec[j], vec[pivot]);
    return j;
}

void Quicksort(vector<int>& vec, int start, int end) {

    if (start < end) {
        int p = Partition(vec, start, end);
        Quicksort(vec, start, p - 1);
        Quicksort(vec, p + 1, end);
    }
}
