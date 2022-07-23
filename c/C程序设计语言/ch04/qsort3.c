

void qsort3(int v[], int srt, int end){
    int i, j;
    void swap(int [], int, int);
    if (srt >= end){
        return;
    }
    for (i = j = srt + 1; i <= end; i++){
        if (v[i] < v[srt]){
            swap(v, i, j++);
        }
    }
    swap(v, srt, j-1);
    qsort3(v, srt, j-2);
    qsort3(v, j, end);
}