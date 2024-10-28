#pragma once

class SinglyList {
private:
  struct Node {
    int data;
    Node *next;
  };

  Node *root;
  unsigned int size;
  unsigned int cap;

public:
  SinglyList(unsigned int cap);

  unsigned int getSize();
  unsigned int getCap();
  bool isEmpty();

  int insert(int data);
  Node *search(int data);
};

class DoublyList {};
