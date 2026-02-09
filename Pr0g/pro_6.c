#include <stdio.h>

void heapify(int arr[], int n, int i, int isMax) {
    int target = i, l = 2 * i + 1, r = 2 * i + 2;

    if (l < n && (isMax ? arr[l] > arr[target] : arr[l] < arr[target])) target = l;
    if (r < n && (isMax ? arr[r] > arr[target] : arr[r] < arr[target])) target = r;

    if (target != i) {
        int tmp = arr[i]; arr[i] = arr[target]; arr[target] = tmp;
        heapify(arr, n, target, isMax);
    }
}

void build(int arr[], int n, int isMax) {
    for (int i = n / 2 - 1; i >= 0; i--) heapify(arr, n, i, isMax);
}

void print(int arr[], int n) {
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int a1[] = {45, 12, 89, 33, 7, 56, 23}, n = 7;
    int a2[] = {45, 12, 89, 33, 7, 56, 23};

    printf("Original: "); print(a1, n);

    build(a1, n, 0); // 0 for Min
    printf("Min Heap: "); print(a1, n);

    build(a2, n, 1); // 1 for Max
    printf("Max Heap: "); print(a2, n);

    return 0;
}