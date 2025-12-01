#include <stdio.h>

int main() {
    int array[100], n, i, j, key;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for(i = 0; i < n; i++){
        scanf("%d", &array[i]);
    }

    // INSERTION SORT
    for(i = 1; i < n; i++){
        key = array[i];
        j = i - 1;

        while(j >= 0 && array[j] > key){
            array[j+1] = array[j];
            j--;
        }
        array[j+1] = key;
    }

    printf("Sorted array: ");
    for(i = 0; i < n; i++)
        printf("%d ", array[i]);

    return 0;
}
