#ifndef HEAP_H
#define HEAP_H
#include<bits/stdc++.h>

using namespace std;

template<class T>
class Heap
{
private:
  vector<T> heap_arr;
  size_t size;

  int get_parent_idx(int x)
  {
    if(x%2) return (x-1)/2;
    else return (x-2)/2;
  }

  int left_child_idx(int x)
  {
    return 2*x+1;
  }

  int right_child_idx(int x)
  {
    return 2*x+2;
  }

public:
  Heap() : size(0) {}
  void insert(T element)
  {
    int element_ptr = heap_arr.size(), compare_ptr = heap_arr.size();
    heap_arr.push_back(element);
    // percolate
    while(element_ptr > 0)
    {
      compare_ptr = get_parent_idx(compare_ptr);
      if(compare_ptr < 0) break;
      if(heap_arr[compare_ptr] > heap_arr[element_ptr])
      {
        T tmp = heap_arr[compare_ptr];
        heap_arr[compare_ptr] = heap_arr[element_ptr];
        heap_arr[element_ptr] = tmp;

        element_ptr = compare_ptr;
      }
    }
  }

  void pop()
  {
    if(heap_arr.size() == 0) return;
    heap_arr[0] = heap_arr[heap_arr.size()-1];
    heap_arr.pop_back();
    int element_ptr = 0;
    while(element_ptr < heap_arr.size())
    {
      int swp_idx = -1, left_idx, right_idx;
      left_idx = left_child_idx(element_ptr);
      right_idx = right_child_idx(element_ptr);

      if(left_idx >= heap_arr.size() || right_idx >= heap_arr.size()) return;

      if(heap_arr[element_ptr] <= heap_arr[left_idx] && heap_arr[element_ptr] <= heap_arr[right_idx])
      {
        return;
      }

      if(heap_arr[left_idx] < heap_arr[right_idx])
      {
        swp_idx = left_child_idx(element_ptr);
      }
      else
      {
        swp_idx = right_child_idx(element_ptr);
      }

      T tmp = heap_arr[element_ptr];
      heap_arr[element_ptr] = heap_arr[swp_idx];
      heap_arr[swp_idx] = tmp;

      element_ptr = swp_idx;
    }
  }

  T top()
  {
    return heap_arr[0];
  }

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
