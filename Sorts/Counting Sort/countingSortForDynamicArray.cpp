void countSort(int array[], int size) {
    int* output;
    output = new int[size]; 
    int* count;
    count = new int[size];
    int max = array[0];

    for (int i = 1; i < size; i++) {
        if (array[i] > max)
            max = array[i];
    }

    for (int i = 0; i <= max; ++i) {
        count[i] = 0;
    }

    for (int i = 0; i < size; i++) {
        count[array[i]]++;
    }

    for (int i = 1; i <= max; i++) {
        count[i] += count[i - 1];
    }

    for (int i = size - 1; i >= 0; i--) {
        output[count[array[i]] - 1] = array[i];
        count[array[i]]--;
    }

    for (int i = 0; i < size; i++) {
        array[i] = output[i];
    }
}
