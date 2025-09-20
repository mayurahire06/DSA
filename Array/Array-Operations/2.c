// C program to find second largest number in an array

#include <stdio.h>

int main() {
    int n;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    if (n < 2) {
        printf("Array must have at least two elements.\n");
        return 0;
    }

    int arr[n];
    printf("Enter %d elements:\n", n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int largest = arr[0];
    int secondLargest = -1;

    for (int i = 1; i < n; i++) {
        if (arr[i] > largest) {
            secondLargest = largest;
            largest = arr[i];
        } else if (arr[i] > secondLargest && arr[i] != largest) { //it means arr[i] is between largest and secondLargest
            secondLargest = arr[i];
        }
    }

    if (secondLargest == -1) {
        printf("No second largest element found.\n");
    } else {
        printf("The second largest element is: %d\n", secondLargest);
    }

    return 0;
}
