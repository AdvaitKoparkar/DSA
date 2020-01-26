#ifndef HEAP_H
#define HEAP_H
#include<bits/stdc++.h>

using namespace std;

template<class T, class Comparator>
class Heap
{
private:
  // array to hold the data in the heap
  vector<T> heap_arr;
  // comparator struct/class for deciding priority
  Comparator op;

  // helper function to get index of parent node of x
  int get_parent_idx(int x)
  {
    if(x%2) return (x-1)/2;
    else return (x-2)/2;
  }

  // helper function to get the index of the left child of x
  int left_child_idx(int x)
  {
    return 2*x+1;
  }

  // helper function to get the index of the right child of x
  int right_child_idx(int x)
  {
    return 2*x+2;
  }

  // helper function to check if index is valid
  bool isvalid(int x)
  {
    return (x >= 0) && (x < heap_arr.size());
  }

  // helper function to swap elements in heap array
  void swap(int x, int y)
  {
    T tmp = heap_arr[x];
    heap_arr[x] = heap_arr[y];
    heap_arr[y] = tmp;
  }

public:
  // push element on the heap
  void push(T element)
  {
    // pointer for inserted element and element to compare
    int element_ptr = heap_arr.size(), compare_ptr = heap_arr.size();
    // insert element in the bottom-most, rightmost leaf of the heap
    heap_arr.push_back(element);
    // "bubble-up" the inserted node in the heap
    while(element_ptr > 0)
    {
      // get the index of the parent node
      compare_ptr = get_parent_idx(compare_ptr);
      // if there is no parent node
      // it means you have reached
      // root - no need to continue
      if(!isvalid(compare_ptr)) break;
      // if the parent element satisfies op
      // swap element and parent & update element
      if(op(heap_arr[compare_ptr], heap_arr[element_ptr]))
      {
        swap(compare_ptr, element_ptr);
        element_ptr = compare_ptr;
      }
    }
  }

  void pop()
  {
    // if heap is empty, return
    if(this->empty()) return;
    // overwrite top of the heap
    // with the bottom-most, right-most leaf
    heap_arr[0] = heap_arr[heap_arr.size()-1];
    // remove bottom-most, right-most leaf node
    heap_arr.pop_back();
    // "bubble-down" the node that
    // was copied to the root of heap
    int element_ptr = 0;
    while(element_ptr < heap_arr.size())
    {
      // indices to the left/right children
      // index of node to swap with element_ptr
      int swp_idx = -1, left_idx, right_idx;
      left_idx = left_child_idx(element_ptr);
      right_idx = right_child_idx(element_ptr);

      // if element_ptr has both children
      if(isvalid(left_idx) && isvalid(right_idx))
      {
        // element_ptr does not satisfy op wrt to both children
        // means heap property satisfied - return
        if(!op(heap_arr[element_ptr], heap_arr[left_idx]) && !op(heap_arr[element_ptr], heap_arr[right_idx]))
        {
          return;
        }
        // find the child which disagrees with the
        // priority the most and swap that with element_ptr
        else if(!op(heap_arr[left_idx], heap_arr[right_idx]))
        {
          swp_idx = left_idx;
        }
        else
        {
          swp_idx = right_idx;
        }
      }

      // if only left child present
      else if(isvalid(left_idx))
      {
        // check if heap property is not satisfied
        if(!op(heap_arr[left_idx], heap_arr[element_ptr]))
        {
          // if not satisfied,
          // choose left child for swapping
          swp_idx = left_idx;
        }
        else
        {
          // heap property satisfied - return
          return;
        }
      }

      // element_ptr has no children
      // "bubble-down" complete - return
      else
      {
        return;
      }

      // swap with chosen node
      swap(element_ptr, swp_idx);
      // update element_ptr
      element_ptr = swp_idx;
    }
  }

  // return element at the top of the heap
  T top()
  {
    return heap_arr[0];
  }

  // check if heap is empty
  bool empty()
  {
    return heap_arr.size() <= 0;
  }

  // returns current size of the heap
  size_t size()
  {
    return heap_arr.size();
  }

  // utility to print heap array
  void print_heap()
  {
    for(size_t i = 0; i < heap_arr.size(); ++i)
    {
      cout << heap_arr[i] << ", ";
    }
    cout << endl;
  }
};

#endif
