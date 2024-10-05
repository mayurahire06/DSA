// Write an algorithm for sequencial search.

#include<stdio.h>

int linearSearch(int n, int x, int arr[]){

    for(int i = 0; i < n; i++){
        if (x == arr[i]) {
            return i;
        }
    }
    return -1;
}

int main(){

    int i, n, x, result;
    int arr[10];

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements of the list:\n");
    for(i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }

    printf("Enter the number you want to search: ");
    scanf("%d", &x);

    result = linearSearch(n, x, arr);
    if(result!=-1){
        printf("%d is  found at %d location", x, result);
    }
    else{
        printf("%d is  NOT found", x);
    }
    return 0;
}