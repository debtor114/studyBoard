#include <cstdio>
#include <algorithm>

using namespace std;

void selection_sort(int * v, int N) {
  
  for (int i = 0; i < N-1; i++) {
    int min = 999999;
    for (int j = i; j < N-1; j++) {
      if (min > v[j]) min = v[j];
    }
    int temp;
    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
  }
}

int main () {
    int arr[10] = {4, 1, 3, 8, 7, 5, 2, 9, 6, 10};
    int N = sizeof(arr) / sizeof(int);

    selectSort(arr, N);
    for (int i = 0; i < N; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}