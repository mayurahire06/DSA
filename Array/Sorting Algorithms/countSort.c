#include <stdio.h>

int findMax(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max)
            max = arr[i];
    }
    return max;
}

void countingSort(int arr[], int n) {
    int max = findMax(arr, n);
    int count[max+1];

    for (int i = 0; i <= max; i++)
        count[i] = 0;

    for (int i = 0; i < n; i++)
        ++count[arr[i]];
    
    for (int index = 0, i = 0; i <= max; i++) {
        while (count[i] > 0) {
            arr[index++] = i;
            count[i]--;
        }
    }

}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int n, arr[10];

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Original array: \n");
    printArray(arr, n);

    countingSort(arr, n);

    printf("Sorted array: \n");
    printArray(arr, n);

    return 0;
}