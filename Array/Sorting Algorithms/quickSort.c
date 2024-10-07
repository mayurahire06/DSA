#include <stdio.h>

int partition(int arr[], int lb, int ub){

    int pivot = arr[lb]; 
    int start = lb;
    int end = ub;

    while(start < end){

        while(arr[start] <= pivot && start < ub){ 
            start++;
        }

        while(arr[end] > pivot && end > lb){
            end--;
        }

        if(start < end){
            int temp = arr[start];
            arr[start] = arr[end];
            arr[end] = temp;
        }
    }

  
    int temp = arr[lb];
    arr[lb] = arr[end];
    arr[end] = temp;

    return end;
}

void quickSort(int arr[], int lb, int ub) {
    if (lb < ub) {
        int pivot = partition(arr, lb, ub);
        quickSort(arr, lb, pivot-1);
        quickSort(arr, pivot+1, ub);
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int n, i;
    int arr[10];

    printf("How many elements: ");
    scanf("%d", &n);

    printf("\nEnter the elements:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    quickSort(arr, 0, n - 1);

    printf("Sorted array is: ");
    printArray(arr, n);

    return 0;
}
