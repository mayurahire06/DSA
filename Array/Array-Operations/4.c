// C program to delete an element from array at specified position

#include <stdio.h>

int main() {
    int n, position;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Array must have at least one element.\n");
        return 0;
    }

    int arr[n];

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the position of the element to delete: ");
    scanf("%d", &position);

    if (position < 1 || position > n) {
        printf("Invalid position! Position must be between 1 and %d.\n", n);
        return 0;
    }

    for (int i = position - 1; i < n - 1; i++) { 
        arr[i] = arr[i + 1];
    }

    printf("Array after deletion:\n");
    for (int i = 0; i < n - 1; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
