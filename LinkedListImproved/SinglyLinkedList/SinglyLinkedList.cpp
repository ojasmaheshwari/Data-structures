
#include "SinglyLinkedList.h"
#include <stdexcept>
#include <string>

Node::Node()
  : next(nullptr)
{
  data = 0;
}

Node::Node(const int data)
  : next(nullptr)
{
  this->data = data;
}

SinglyLinkedList::SinglyLinkedList()
  : m_Head(nullptr), m_Tail(nullptr)
{
}

SinglyLinkedList::~SinglyLinkedList()
{
  // Free the linked list
}

Node* SinglyLinkedList::getHead() const
{
  return m_Head;
}

Node* SinglyLinkedList::getTail() const
{
  return m_Tail;
}

void SinglyLinkedList::insertAtEnd(const int value)
{
  Node* node = new Node(value);

  if (m_Head == nullptr)
  {
    m_Head = node;
    m_Tail = node;
    return;
  }

  m_Tail->next = node;
  m_Tail = m_Tail->next;
}

std::string SinglyLinkedList::toString() const
{
  std::string stringForm;

  Node* trav = m_Head;
  if (trav->next == nullptr) {
    return "empty";
  }

  while (trav->next != nullptr) {
    stringForm += std::to_string(trav->data) + " -> ";
    trav = trav->next;
  }

  stringForm += std::to_string(trav->data);

  return stringForm;
}

void SinglyLinkedList::deleteAtEnd()
{
  Node* trav1 = m_Head;
  Node* trav2 = m_Tail;
  
  while(trav1->next != m_Tail) {
    trav1 = trav1->next;
  }

  // trav1 points to second last node
  // trav2 points to last node
  delete trav2;
  m_Tail = trav1;
  m_Tail->next = nullptr;
}

void SinglyLinkedList::insertAt(const int index, const int value)
{
  int i = 0;
  Node* node = new Node(value);
  Node* trav = m_Head;

  while ( i != index )
  {
    if (trav->next == nullptr)
    {
      throw std::runtime_error("Index out-of-bounds");
    }
    i++;
    trav = trav->next;
  }

  if (trav->next == nullptr) {
    // trav points to last element
    trav->next = node;
  }
  else {
    // There exists some element after trav for sure
    node->next = trav->next;    
    trav->next = node;
  }
}

void SinglyLinkedList::deleteAt(const int index)
{
  Node* trav1 = m_Head;
  if (trav1 == nullptr) throw std::runtime_error("Cannot delete in an empty list");

  Node* trav2;
  if (trav1->next != nullptr) {
    trav2 = trav1->next;
  }
  else {
    // Linked list has only 1 element
    if (index != 0) {
      throw std::runtime_error("Index out-of-bounds");
    }
    delete trav1;
    m_Head = nullptr;
  }

  int i = 0;
  while ( i != index - 1) {
    if (trav2==nullptr) {
      throw std::runtime_error("Index out-of-bounds");
    }
    i++;
    trav1 = trav1->next;
    trav2 = trav2->next;
  }

  // trav1 points at node before index
  // trav2 points to node at index
  trav1->next = trav2->next;
  delete trav2;
}

int SinglyLinkedList::operator[] (const int index) const
{
  Node* trav = m_Head;

  int i = 0;
  while ( i != index )
  {
    if (trav == nullptr) throw std::runtime_error("Index out-of-bounds");
    i++;
    trav = trav->next;
  }

  return trav->data;
}
