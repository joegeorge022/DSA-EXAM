#include <stdio.h>

int array[100];

void merge(int l, int m, int r) {
    int temp[100];
    int i = l, j = m+1, k = 0;

    while(i <= m && j <= r){
        if(array[i] < array[j])
            temp[k++] = array[i++];
        else
            temp[k++] = array[j++];
    }
    while(i <= m) temp[k++] = array[i++];
    while(j <= r) temp[k++] = array[j++];

    for(i = l, k = 0; i <= r; i++, k++)
        array[i] = temp[k];
}

void mergeSort(int l, int r){
    if(l < r){
        int m = (l + r) / 2;
        mergeSort(l, m);
        mergeSort(m+1, r);
        merge(l, m, r);
    }
}

int main() {
    int n, i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for(i = 0; i < n; i++){
        scanf("%d", &array[i]);
    }

    // MERGE SORT
    mergeSort(0, n-1);

    printf("Sorted array: ");
    for(i = 0; i < n; i++)
        printf("%d ", array[i]);

    return 0;
}
