// C program to read and print elements in an array using recursion

#include <stdio.h>

void readArray(int arr[], int index, int n) {
    if (index == n) {
        return;
    }
    printf("Enter element %d: ", index + 1);
    scanf("%d", &arr[index]);
    readArray(arr, index + 1, n);
}

void printArray(int arr[], int index, int n) {
    if (index == n) {
        return;
    }
    printf("%d ", arr[index]);
    printArray(arr, index + 1, n);
}

int main() {
    int n;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter %d elements:\n", n);
    readArray(arr, 0, n);
    printf("The elements in the array are:\n");
    printArray(arr, 0, n);
    return 0;
}
