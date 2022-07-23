
void swap(int v[], int i, int j);

void qsort2(int arr[], int i, int j){
    int last, k;
    void swap(int v[], int i, int j);
    if (i >= j){
        return;
    }
    swap(arr, i, (i+j)/2);
    last = i;
    for (k = i + 1; k <= j; k++){
        if (arr[k] < arr[i]){
            swap(arr, k, ++last);
        }
    }
    swap(arr, i, last);
    qsort2(arr, i, last-1);
    qsort2(arr, last+1, j);
}

void swap(int v[], int i, int j){
    int tmp = v[i];
    v[i] = v[j];
    v[j] = tmp;
}