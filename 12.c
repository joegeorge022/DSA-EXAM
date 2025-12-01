#include <stdio.h>

void printArray(int arr[], int n) {
    for(int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// ---------------- Bubble Sort ----------------
void bubbleSort(int arr[], int n) {
    for(int i = 0; i < n-1; i++) {
        for(int j = 0; j < n-i-1; j++) {
            if(arr[j] > arr[j+1]) {
                int t = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = t;
            }
        }
    }
}

// ---------------- Insertion Sort ----------------
void insertionSort(int arr[], int n) {
    for(int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while(j >= 0 && arr[j] > key) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

// ---------------- Quick Sort ----------------
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for(int j = low; j < high; j++) {
        if(arr[j] < pivot) {
            i++;
            int t = arr[i];
            arr[i] = arr[j];
            arr[j] = t;
        }
    }

    int t = arr[i+1];
    arr[i+1] = arr[high];
    arr[high] = t;

    return i + 1;
}

void quickSort(int arr[], int low, int high) {
    if(low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi-1);
        quickSort(arr, pi+1, high);
    }
}

// ---------------- Merge Sort ----------------
void merge(int arr[], int l, int m, int r) {
    int temp[100];
    int i = l, j = m + 1, k = 0;

    while(i <= m && j <= r) {
        if(arr[i] < arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }
    while(i <= m) temp[k++] = arr[i++];
    while(j <= r) temp[k++] = arr[j++];

    for(i = l, k = 0; i <= r; i++, k++)
        arr[i] = temp[k];
}

void mergeSort(int arr[], int l, int r) {
    if(l < r) {
        int m = (l + r) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

// ---------------- Main Program ----------------
int main() {
    int n;
    int arr[100], b1[100], b2[100], b3[100], b4[100];

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    // Copy original array for each sorting algorithm
    for(int i = 0; i < n; i++) {
        b1[i] = b2[i] = b3[i] = b4[i] = arr[i];
    }

    bubbleSort(b1, n);
    printf("\nBubble Sort: ");
    printArray(b1, n);

    insertionSort(b2, n);
    printf("Insertion Sort: ");
    printArray(b2, n);

    quickSort(b3, 0, n-1);
    printf("Quick Sort: ");
    printArray(b3, n);

    mergeSort(b4, 0, n-1);
    printf("Merge Sort: ");
    printArray(b4, n);

    return 0;
}

