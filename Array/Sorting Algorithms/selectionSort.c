#include<stdio.h>

void selectionSort(int arr[], int n){
    int minIndex, temp;

    for(int i = 0; i < n - 1; i++){
        minIndex = i;
        for(int j = i + 1; j < n; j++){
            if(arr[j] < arr[minIndex]){
                minIndex = j;
            }
        }

        if(minIndex != i){
            temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
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

    selectionSort(arr, n);

    printf("Sorted array: ");
    printArray(arr, n);

    return 0;
}
