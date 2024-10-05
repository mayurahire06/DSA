#include<stdio.h>

void insertionSort(int arr[], int n){
    for(int i=1; i<n; i++){
        int current = arr[i];
        int j = i-1;

        while(j>=0 && current < arr[j]){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = current;
    }
}

void printArray(int arr[], int n){
    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main(){
    int n;
    int arr[10];

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    insertionSort(arr, n);

    printf("Sorted array: ");
    printArray(arr, n);

    return 0;
}
