#include "heap.h"
#include "iostream"
using namespace std;

int main()
{
  Heap<int> myHeap;

  myHeap.push(20);
  myHeap.push(15);
  myHeap.push(30);
  myHeap.push(5);

  cout << "Checking element order and insertion" << endl;
  while(!myHeap.empty())
  {
    cout << "Top: " << myHeap.top() << endl;
    myHeap.pop();
  }

  cout << endl;

  myHeap.push(20);
  myHeap.push(15);
  myHeap.push(30);
  myHeap.push(5);

  myHeap.pop();
  cout << "After removing the top element: " << endl;
  while (!myHeap.empty()) {
    cout << "Top: " << myHeap.top() << endl;
    myHeap.pop();
  }

  return 0;
}