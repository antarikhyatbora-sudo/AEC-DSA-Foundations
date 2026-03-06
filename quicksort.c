#include <stdio.h>
#include <string.h>

int partition(char arr[], int low, int high) {
    char pivot = arr[high];
    int i = low - 1;
    for(int j = low; j < high; j++) {
        if(arr[j] > pivot) {
            i++;
            char temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    char temp = arr[i+1];
    arr[i+1] = arr[high];
    arr[high] = temp;
    return i+1;
}

void quickSort(char arr[], int low, int high) {
    if(low < high) {
        int p = partition(arr, low, high);
        quickSort(arr, low, p-1);
        quickSort(arr, p+1, high);
    }
}

int main() {
    char str[100];
    printf("Enter string: ");
    gets(str);
    int n = strlen(str);
    quickSort(str, 0, n-1);
    printf("Sorted (Descending): %s", str);
    return 0;
}
