#pragma once

#include <stdexcept>
#include <string.h>

class DynamicArray {
  public:
    DynamicArray();
    ~DynamicArray();
    const void push(const int value);
    int pop();
    int operator[] (const int index) const;
    int size() const;
    int capacity() const;
    int removeAt(const int index);
    void insertAt(const int index, const int value);
    std::string toString() const;
    int find(const int value) const;
  private:
    int m_Size;
    int m_CurrentSize;
    int* m_Arr;
};
