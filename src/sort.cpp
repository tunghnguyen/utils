#include "sort.h"

void insertionSort(int arr[], int n) {
  int j, key;
  for (int i = 1; i < n; ++i) {
    key = arr[i];
    j = i - 1;
    while (j >= 0 && arr[j] > key) {
      arr[j + 1] = arr[j];
      --j;
    }
    arr[j + 1] = key;
  }
}

void selectionSort(int arr[], int n) {
  int min, temp;
  for (int i = 0; i < n - 1; ++i) {
    min = i;
    for (int j = i + 1; j < n; ++j) {
      if (arr[j] < arr[min])
        min = j;
    }
    if (min != i) {
      temp = arr[i];
      arr[i] = arr[min];
      arr[min] = temp;
    }
  }
}

void merge(int arr[], int p, int q, int r) {
  int nl = q - p + 1;
  int nr = r - q;
  int arrl[nl], arrr[nr];

  for (int i = 0; i < nl; ++i) {
    arrl[i] = arr[p + i];
  }
  for (int j = 0; j < nr; ++j) {
    arrr[j] = arr[q + 1 + j];
  }

  int i = 0, j = 0;
  int k = p;

  while (i < nl && j < nr) {
    if (arrl[i] <= arrr[j]) {
      arr[k] = arrl[i];
      ++i;
    } else {
      arr[k] = arrr[j];
      ++j;
    }
    ++k;
  }

  while (i < nl) {
    arr[k] = arrl[i];
    ++i;
    ++k;
  }
  while (j < nr) {
    arr[k] = arrr[j];
    ++j;
    ++k;
  }
}

void mergeSort(int arr[], int p, int r) {
  if (p >= r) return;
  int q = (p + r) / 2;

  mergeSort(arr, p, q);
  mergeSort(arr, q + 1, r);
  merge(arr, p, q, r);
}
