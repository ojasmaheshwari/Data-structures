#pragma once

#include <iostream>


class Node
{
public:
  Node();
  Node(const int data);
  ~Node() = default;
  int data;
  Node* next;
};

class SinglyLinkedList
{
public:
  SinglyLinkedList();
  ~SinglyLinkedList();
  Node* getHead() const;
  Node* getTail() const;
  std::string toString() const;
  void insertAtEnd(const int value);
  void deleteAtEnd();
  void insertAt(const int index, const int value);
  void deleteAt(const int index);
  int operator[] (const int index) const;

private:
  Node* m_Head;
  Node* m_Tail;
};
