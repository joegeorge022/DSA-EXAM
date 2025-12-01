#include <stdio.h>

int array[100];

int partition(int low, int high) {
    int pivot = array[high];
    int i = low - 1, temp;

    for(int j = low; j < high; j++){
        if(array[j] < pivot){
            i++;
            temp = array[i];
            array[i] = array[j];
            array[j] = temp;
        }
    }

    temp = array[i+1];
    array[i+1] = array[high];
    array[high] = temp;

    return i + 1;
}

void quickSort(int low, int high){
    if(low < high){
        int pi = partition(low, high);
        quickSort(low, pi-1);
        quickSort(pi+1, high);
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

    // QUICK SORT
    quickSort(0, n-1);

    printf("Sorted array: ");
    for(i = 0; i < n; i++)
        printf("%d ", array[i]);

    return 0;
}
