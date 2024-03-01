#include "llrec.h"

//*********************************************
// Provide your implementation of llpivot below
//*********************************************

void llpivot(Node *&head, Node *&smaller, Node *&larger, int pivot)
{
  if(head == NULL)
  {
    return;
  }
  else
  {
    // disconnect the head from the list to not link the entire list to smaller/larger
    // but also preserve the original list with a pointer to the next item
    Node* temp = head->next;
    head->next = nullptr;

    if(head->val <= pivot)
    {
      smaller = head;      
      llpivot(temp, smaller->next, larger, pivot);
    }
    else
    {
      larger = head;
      llpivot(temp, smaller, larger->next, pivot);
    }
  }
}
