#pragma once

/// Iterate the array and insert the current item into the appropriate position
/// in the array
void insertionSort(int arr[], int n);

/// Iterate the array and swap the current item with the smallest item from the
/// sorted portion of the array
void selectionSort(int arr[], int n);

/// Divide the array into two halves, sort each half, and merge the two sorted
/// halves together
void mergeSort(int arr[], int p, int r);
