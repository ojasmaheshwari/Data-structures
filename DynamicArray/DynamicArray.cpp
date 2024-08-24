#include "DynamicArray.h"
#include <stdexcept>
#include <string>

DynamicArray::DynamicArray()
  : m_Size(10), m_CurrentSize(0)
{
  m_Arr = new int[m_Size];
}

DynamicArray::~DynamicArray()
{
  delete m_Arr;
}

const void DynamicArray::push(const int value)
{
  if (m_CurrentSize == m_Size) {
    // make a new array of 2 * m_CurrentSize and copy all elems from it
    int* newArr = new int[2*m_CurrentSize];
    for (int i=0; i<m_CurrentSize; i++) {
      newArr[i] = m_Arr[i];
    }
    delete m_Arr;
    m_Arr = newArr;
    m_Size = 2*m_CurrentSize;
  }
  m_Arr[m_CurrentSize] = value;
  m_CurrentSize++;
}

int DynamicArray::pop()
{
  if (m_CurrentSize == 0) {
    throw std::runtime_error("Cannot pop on empty dynamic array");
  }
  int popped = m_Arr[m_CurrentSize];
  m_Arr[m_CurrentSize] = 0;
  m_CurrentSize--;
  return popped;
}

int DynamicArray::operator[] (const int index) const
{
  if (index < 0 || index >= m_CurrentSize) {
    throw std::runtime_error("Index out-of-bounds.");
  }
  return m_Arr[index];
}

int DynamicArray::size() const
{
  return m_CurrentSize;
}

int DynamicArray::capacity() const
{
  return m_Size;
}

int DynamicArray::removeAt(const int index)
{
  if (index < 0 || index >= m_CurrentSize) {
    throw std::runtime_error("Index out-of-bounds");
  }
  int removed = m_Arr[index];
  m_Arr[index] = 0;

  m_CurrentSize--;
  for (int i = index; i < m_CurrentSize; i++)
  {
    m_Arr[i] = m_Arr[i+1];
  }

  return removed;
}

std::string DynamicArray::toString() const
{
  if (m_CurrentSize == 0) return "[]";

  std::string stringForm = "[";

  // Growth optimization
  stringForm.reserve(m_CurrentSize + m_CurrentSize*2 + 2);

  for (int i=0; i<m_CurrentSize; i++)
  {
    if (i != m_CurrentSize - 1)
      stringForm += std::to_string(m_Arr[i]) + ", ";
    else
      stringForm += std::to_string(m_Arr[i]) + "]";
  }

  return stringForm;
}

void DynamicArray::insertAt(const int index, const int value)
{
  if (index < 0 || index >= m_CurrentSize)
  {
    throw std::runtime_error("Index out-of-bounds");
  }

  if (m_CurrentSize == m_Size)
  {
    int* newArr = new int[2*m_CurrentSize];
    for (int i=0; i<m_CurrentSize; i++) {
      newArr[i] = m_Arr[i];
    }
    delete m_Arr;
    m_Arr = newArr;
    m_Size = 2*m_CurrentSize;
  }

  m_CurrentSize++;

  for(int i=m_CurrentSize-1; i>=index; i--)
  {
    m_Arr[i] = m_Arr[i-1];
  }

  m_Arr[index] = value;
}

int DynamicArray::find(const int value) const
{
  // Cannot use binary search as m_Arr is not necessarily sorted
  // Using linear search

  for (int i=0; i<m_CurrentSize; i++)
  {
    if (m_Arr[i] == value)
      return i;
  }

  return -1;
}
