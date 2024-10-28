#pragma once

class CircularBuffer {
private:
  unsigned int size = 0;
  unsigned int cap = 1000;
  int data[1000];
  int front = 0;
  int rear = 0;

public:
  /// Return the first item
  int peekFront();

  /// Return the last item
  int peekRear();

  /// Pop and return the first item
  int popFront();

  /// Insert new item
  int pushBack(int val);

  /// Check if the buffer is empty
  bool isEmpty();

  /// Check if the buffer is full
  bool isFull();
};
