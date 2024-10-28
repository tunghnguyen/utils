#include "buffer.h"

#include <limits>

using std::numeric_limits;

int CircularBuffer::peekFront() {
  if (size <= 0)
    return numeric_limits<int>::min();
  return data[front];
}

int CircularBuffer::peekRear() {
  if (size >= cap)
    return numeric_limits<int>::min();
  return data[(rear - 1) % cap];
}

int CircularBuffer::popFront() {
  if (size <= 0)
    return numeric_limits<int>::min();
  --size;
  int temp = data[front];
  front = (front + 1) % cap;
  return temp;
}

int CircularBuffer::pushBack(int val) {
  if (size <= 0)
    return 1;
  ++size;
  data[rear] = val;
  rear = (rear + cap + 1) % cap;
  return 0;
}

bool CircularBuffer::isEmpty() { return size <= 0; }

bool CircularBuffer::isFull() { return size >= cap; }
