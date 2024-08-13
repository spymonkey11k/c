// mergeSort


#include <stdio.h>
#include <time.h>
#include <stdlib.h> 

void Merge(int a[], int low, int mid, int high) {
    int i, j, k, b[100000];
    i = low;
    j = mid + 1;
    k = low;
    while (i <= mid && j <= high) {
        if (a[i] <= a[j])
            b[k++] = a[i++];
        else
            b[k++] = a[j++];
    }

    while (i <= mid)
        b[k++] = a[i++];
    
    while (j <= high)
        b[k++] = a[j++];

    for (k = low; k <= high; k++)
        a[k] = b[k];
}

void MergeSort(int a[], int low, int high) {
    int mid;
    if (low >= high)
        return;
    mid = (low + high) / 2;
    MergeSort(a, low, mid);
    MergeSort(a, mid + 1, high);
    Merge(a, low, mid, high);
}

int main() {
    int n, k;
    clock_t st, et;
    double ts;
    printf("\nEnter How many Numbers:");
    scanf("%d", &n);
    int a[100000]; // Declare array 'a' with size 'n'
    printf("\nThe Random Numbers are:\n");
    
    for (k = 0; k < n; k++) { // Start from 0
      a[k]=rand(); 
	  printf("%d\t",a[k]);
  }
    st = clock();
    MergeSort(a, 0, n - 1);
    et = clock();
    ts = (double)(et - st) / CLOCKS_PER_SEC;
    printf("\nSorted Numbers are:\n");
    for (k = 0; k < n; k++) { // Start from 0
        printf("%d\t", a[k]);
    }
    printf("\nThe time taken is %lf", ts);
    return 0;
}

