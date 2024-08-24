#include "DynamicArray.h"
#include <iostream>

int main()
{
  DynamicArray d;
  d.push(1);
  d.push(2);
  d.push(4);
  d.push(5);
  d.push(6);
  d.push(7);

  d.insertAt(2, 3);

  // d = [1, 2, 3, 4, 5, 6 , 7]
  std::cout << d.toString() << '\n';

  std::cout << d.find(9) << '\n';
  return 0;
}
