#include <stdio.h>

int partition(int arr[], int lb, int ub){

    int pivot = arr[lb]; 
    int start = lb;
    int end = ub;

    while(start < end){

        // Increment start until you find an element greater than the pivot or reach the boundary
        while(arr[start] <= pivot && start < ub){ 
            start++;
        }

        // Decrement end until you find an element smaller than or equal to the pivot or reach lb
        while(arr[end] > pivot && end > lb){
            end--;
        }

        // Swap elements at start and end
        if(start < end){
            int temp = arr[start];
            arr[start] = arr[end];
            arr[end] = temp;
        }
    }

    // Swapping the pivot element with the element at 'end'
    int temp = arr[lb];
    arr[lb] = arr[end];
    arr[end] = temp;

    return end; // Return the pivot position
}

void quickSort(int arr[], int lb, int ub) {
    if (lb < ub) {
        int pivot = partition(arr, lb, ub);
        quickSort(arr, lb, pivot-1); // Sort the left part
        quickSort(arr, pivot+1, ub); // Sort the right part
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
