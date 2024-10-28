#include "tree.h"

#include <iostream>
#include <limits>
#include <utility>

using std::cout, std::swap, std::numeric_limits;

int Heap::insert(int val) {
  // Return error if value is already in the heap
  for (int i = 0; i < size; ++i)
    if (data[i] == val)
      return 1;

  // Insert value at the end of the heap
  data[size++] = val;

  int current = size - 1;
  int parent = (current - 1) / 2;

  while (parent >= 0 && data[current] < data[parent]) {
    swap(data[current], data[parent]);
    current = parent;
    parent = (current - 1) / 2;
  }

  return 0;
}

int Heap::deleteTop() {
  // Return error if the heap is empty
  if (!size)
    return 1;

  int current = 0;
  int left = 1;
  int right = 2;

  // Swap and delete min
  swap(data[0], data[--size]);

  // Heapify down
  while ((left < size && data[current] > data[left]) ||
         (right < size && data[current] > data[right])) {

    if (right >= size) {
      swap(data[current], data[left]);
      break;
    }

    if (left >= size) {
      swap(data[current], data[right]);
      break;
    }

    if (data[left] <= data[right]) {
      swap(data[current], data[left]);
      current = left;
    } else {
      swap(data[current], data[right]);
      current = right;
    }

    left = current * 2 + 1;
    right = current * 2 + 2;
  }

  return 0;
}

int Heap::extractTop() { return size ? data[0] : numeric_limits<int>::min(); }

unsigned int Heap::heapSize() { return size; }

void Heap::heapDisplay() {
  for (int lvl = 1; lvl <= size; lvl *= 2) {
    for (int i = 0; i < lvl; ++i) {
      if (lvl - 1 + i >= size)
        break;
      cout << data[lvl - 1 + i] << ' ';
    }
    cout << '\n';
  }
}
