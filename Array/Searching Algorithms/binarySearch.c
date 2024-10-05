#include<stdio.h>

int binarySearch(int x, int n, int arr[]){

    int start = 0, mid, end = n - 1;

    while(start <= end){
        mid = (start + end) / 2;

        if(x == arr[mid]){
            return mid;
        }
        else if(x < arr[mid]){
            end = mid - 1;
        }
        else{
            start = mid + 1;
        }
    }
    return -1;
}

int main(){

    int i, n, x, result;
    int arr[10];

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the sorted elements of the list:\n");
    for(i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }

    printf("Enter the number you want to search: ");
    scanf("%d", &x);

    result = binarySearch(x, n, arr);
    if(result != -1){
        printf("%d is found at index %d", x, result);
    }
    else{
        printf("%d is NOT found", x);
    }

    return 0;
}
