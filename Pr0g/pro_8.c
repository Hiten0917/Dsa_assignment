#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int c = 0, s = 0; // Comparisons and Swaps

void reset_stats() { c = 0; s = 0; }

void swap(int *a, int *b) {
    int t = *a; *a = *b; *b = t;
    s++;
}

void bubble(int a[], int n) {
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++) {
            c++;
            if (a[j] > a[j+1]) swap(&a[j], &a[j+1]);
        }
}

void selection(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++) {
            c++;
            if (a[j] < a[min]) min = j;
        }
        if (min != i) swap(&a[i], &a[min]);
    }
}

void merge(int a[], int l, int m, int r) {
    int n1 = m - l + 1, n2 = r - m, i, j, k;
    int L[n1], R[n2];
    for (i = 0; i < n1; i++) L[i] = a[l + i];
    for (j = 0; j < n2; j++) R[j] = a[m + 1 + j];
    
    for (i = 0, j = 0, k = l; i < n1 && j < n2; k++, s++) {
        c++;
        if (L[i] <= R[j]) a[k] = L[i++];
        else a[k] = R[j++];
    }
    while (i < n1) { a[k++] = L[i++]; s++; }
    while (j < n2) { a[k++] = R[j++]; s++; }
}

void merge_sort(int a[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        merge_sort(a, l, m);
        merge_sort(a, m + 1, r);
        merge(a, l, m, r);
    }
}

void print_and_reset(char* name, int n) {
    printf("%-15s | Comparisons: %-4d | Swaps/Moves: %d\n", name, c, s);
    reset_stats();
}

int main() {
    int n = 10, orig[10], temp[10];
    srand(time(NULL));

    printf("Generating random array of size %d...\n\n", n);
    for (int i = 0; i < n; i++) orig[i] = rand() % 100;

    // Test Bubble Sort
    for(int i=0; i<n; i++) temp[i] = orig[i];
    bubble(temp, n);
    print_and_reset("Bubble Sort", n);

    // Test Selection Sort
    for(int i=0; i<n; i++) temp[i] = orig[i];
    selection(temp, n);
    print_and_reset("Selection Sort", n);

    // Test Merge Sort
    for(int i=0; i<n; i++) temp[i] = orig[i];
    merge_sort(temp, 0, n - 1);
    print_and_reset("Merge Sort", n);

    return 0;
}