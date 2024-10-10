#include <stdio.h>
#include <stdlib.h>

#define BUCKETS 10

void insertionSort(float arr[], int n) {
    int i, j;
    float key;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void bucketSort(float arr[], int n) {
    float buckets[BUCKETS][n];
    int bucket_count[BUCKETS];
    int i, j, k;

    for (i = 0; i < BUCKETS; i++) {
        bucket_count[i] = 0;
    }

    float max_value = arr[0];
    for (i = 1; i < n; i++) {
        if (arr[i] > max_value) {
            max_value = arr[i];
        }
    }

    for (i = 0; i < n; i++) {
        int bucket_index = (int)((arr[i] * BUCKETS) / (max_value + 1));
        buckets[bucket_index][bucket_count[bucket_index]++] = arr[i];
    }

    k = 0;
    for (i = 0; i < BUCKETS; i++) {
        if (bucket_count[i] > 0) {
            insertionSort(buckets[i], bucket_count[i]);
            for (j = 0; j < bucket_count[i]; j++) {
                arr[k++] = buckets[i][j];
            }
        }
    }
}

void printArray(float arr[], int n){
    for (int i = 0; i < n; i++) {
        printf("%.2f ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    float arr[n];

    printf("Enter the elements: \n");
    for (int i = 0; i < n; i++) {
        scanf("%f", &arr[i]);
    }

    printf("\nOriginal array: \n");
    printArray(arr, n);

    bucketSort(arr, n);

    printf("Sorted array: \n");
    printArray(arr, n);

    return 0;
}
