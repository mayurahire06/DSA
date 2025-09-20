// C program to insert an element in array at specified position

#include <stdio.h>

int main() {
    int n, position, element;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int arr[n + 1]; // Array size increased by 1 to accommodate the new element

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the position where you want to insert the element: ");
    scanf("%d", &position);

    if (position < 1 || position > n + 1) {
        printf("Invalid position! Position must be between 1 and %d.\n", n + 1);
        return 0;
    }

    printf("Enter the element to insert: ");
    scanf("%d", &element);

    for (int i = n; i >= position; i--) {
        arr[i] = arr[i - 1];
    }

    arr[position - 1] = element;

    printf("Array after insertion:\n");
    for (int i = 0; i <= n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
