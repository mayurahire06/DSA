#include<stdio.h>

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main(){
    int n;
    int arr[10];

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements of the list:\n");
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }

    // Call the bubbleSort function
    bubbleSort(arr, n);

    printf("Sorted list:\n");
    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }

    return 0;
}

