#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>
#include <vector>

template <typename T, typename PComparator = std::less<T> >
class Heap
{
public:
  /**
   * @brief Construct a new Heap object
   * 
   * @param m ary-ness of heap tree (default to 2)
   * @param c binary predicate function/functor that takes two items
   *          as an argument and returns a bool if the first argument has
   *          priority over the second.
   */
  Heap(int m=2, PComparator c = PComparator());

  /**
  * @brief Destroy the Heap object
  * 
  */
  ~Heap();

  /**
   * @brief Push an item to the heap
   * 
   * @param item item to heap
   */
  void push(const T& item);

  /**
   * @brief Returns the top (priority) item
   * 
   * @return T const& top priority item
   * @throw std::underflow_error if the heap is empty
   */
  T const & top() const;

  /**
   * @brief Remove the top priority item
   * 
   * @throw std::underflow_error if the heap is empty
   */
  void pop();

  /// returns true if the heap is empty

  /**
   * @brief Returns true if the heap is empty
   * 
   */
  bool empty() const;

    /**
   * @brief Returns size of the heap
   * 
   */
  size_t size() const;

private:
  /// Add whatever helper functions and data members you need below
  std::vector<T> heap_;
  size_t m_ary_;
  PComparator comp_;

  // restoring heap property after insertion (element needs to be properly placed)
  void heapifyUp(size_t idx);

  // restoring heap property after removing (last element becomes first, gotta go down)
  void heapifyDown(size_t idx);
};

// Add implementation of member functions here

template <typename T, typename PComparator>
Heap<T,PComparator>::Heap(int m, PComparator c) : m_ary_(m), comp_(c)
{
  if(m < 2) {
    throw std::invalid_argument("Cannot have less than a binary heap");
  }
}


template <typename T, typename PComparator>
Heap<T,PComparator>::~Heap() { }


template <typename T, typename PComparator>
bool Heap<T,PComparator>::empty() const
{
  return heap_.empty();
}


template <typename T, typename PComparator>
size_t Heap<T,PComparator>::size() const
{
  return heap_.size();
}


template <typename T, typename PComparator>
void Heap<T,PComparator>::push(const T& item)
{
  heap_.push_back(item);
  heapifyUp(heap_.size() - 1);
}

// We will start top() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
T const & Heap<T,PComparator>::top() const
{
  // Here we use exceptions to handle the case of trying
  // to access the top element of an empty heap
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("Empty heap!");
  }
  // If we get here we know the heap has at least 1 item
  // Add code to return the top element

  return heap_[0];
}


// We will start pop() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
void Heap<T,PComparator>::pop()
{
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("Empty heap!");
  }
  heap_[0] = heap_[heap_.size() - 1];
  heap_.pop_back();

  if(!empty())
  {
    heapifyDown(0);
  }
}

template <typename T, typename PComparator>
void Heap<T,PComparator>::heapifyUp(size_t idx)
{
  // While the index doesn't go past the first, compare the current idx to the parent
  // if it is less than, therefore returning true, swap
  //    Update idx
  while(idx > 0)
  {
    if(comp_(heap_[idx], heap_[(idx - 1) / m_ary_]))
    {
      std::swap(heap_[idx], heap_[(idx - 1) / m_ary_]);
      idx = (idx - 1) / m_ary_;
    }    
    else
    {
      break;
    }
  }
}

template <typename T, typename PComparator>
void Heap<T,PComparator>::heapifyDown(size_t idx)
{
    size_t childIndex = m_ary_ * idx + 1;

    // While the child does not exceed the size of the entire heap
    while(childIndex < heap_.size())
    {
      size_t bestChildIndex = childIndex;
      // looking through all the children of the current node, find 
      //  "best" child to swap down with (either min or max, based on comp)
      for(size_t i = 1; i < m_ary_; i++)
      {
        if(childIndex + i >= heap_.size())
        {
          break;
        }
        else if(comp_(heap_[childIndex + i], heap_[bestChildIndex]))
        {
          // Set bestChild (smallest) to the smaller child idx
          bestChildIndex = childIndex + i;
        }
      }

      // check if a swap needs to occur
      if(comp_(heap_[bestChildIndex], heap_[idx]))
      {
        std::swap(heap_[bestChildIndex], heap_[idx]);
        idx = bestChildIndex;

        childIndex = m_ary_ * idx + 1;
      }
      else
      {
        break;
      }

    }
}



#endif

