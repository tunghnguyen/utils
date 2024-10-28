#pragma once

class SearchTree {};

class Heap {
private:
  unsigned int size = 0;
  int data[1000];

public:
  /// Insert an element into the heap
  int insert(int val);

  /// Delete the top element in the heap and reconstruct the heap after
  /// deletion
  int deleteTop();

  /// Return the top element in the heap
  int extractTop();

  /// Return the size of the heap
  unsigned int heapSize();

  /// Display the elements in the heap by level-order
  void heapDisplay();
};
