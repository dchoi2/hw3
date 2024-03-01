#include "stack.h"
#include <iostream>
using namespace std;

int main()
{
  Stack<int> newStack;

  cout << "Empty: " << newStack.empty() << " " << "Size: " << newStack.size() << endl;

  newStack.push(3); newStack.push(5);
  cout << "Top: " << newStack.top() << endl;
  cout << "Popping..." << endl;
  newStack.pop();

  cout << "Top: " << newStack.top() << endl; 

  return 0;
}