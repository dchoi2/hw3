#include "llrec.h"

//*********************************************
// Provide your implementation of llpivot below
//*********************************************

void llpivot(Node *&head, Node *&smaller, Node *&larger, int pivot)
{
  if(head == NULL)
  {
    smaller = NULL;
    larger = NULL;
    return;
  }
  else
  {
    // disconnect the head from the list to not link the entire list to smaller/larger
    // but also preserve the original list with a pointer to the next item
    Node* temp = head->next;
    head->next = nullptr;

    Node* smallNext = nullptr;
    Node* largeNext = nullptr;

    // Head recurse with pivot to partition into smallNext and largeNext
    llpivot(temp, smallNext, largeNext, pivot);

    // On the way back up, if the value is less than pivot then build either 
    // or larger
    if(head->val <= pivot)
    {
      head->next = smallNext;
      smaller = head;  
      larger = largeNext;
    }
    else
    {
      head->next = largeNext;
      larger = head;  
      smaller = smallNext;
    }


    // Reset the head to NULL to process this element
    head = NULL;
  }
}
