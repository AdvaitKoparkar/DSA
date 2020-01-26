#include "../src/heap.hpp"

typedef int dtype;

struct MinHeapComparator
{
  bool operator () (dtype l, dtype r) {return l > r;}
};

struct MaxHeapComparator
{
  bool operator () (dtype l, dtype r) {return l < r;}
};

void test_heap0()
{
  Heap<dtype, MinHeapComparator> h;
  vector<dtype> v = {0,2,5,4,6,3};
  priority_queue<dtype, vector<dtype>, MinHeapComparator> pq;
  for(auto vi : v)
  {
    h.push(vi);
    pq.push(vi);
  }

  while(!h.empty())
  {
    assert(h.top() == pq.top() && "test_heap0: incorrect order");
    h.pop();
    pq.pop();
  }
  assert(h.empty() && pq.empty() && "test_heap0: unequal sizes");
}

void test_heap1()
{
  Heap<dtype, MaxHeapComparator> h;
  vector<dtype> v = {0,2,5,4,6,3};
  priority_queue<dtype, vector<dtype>, MaxHeapComparator> pq;
  for(auto vi : v)
  {
    h.push(vi);
    pq.push(vi);
  }

  while(!h.empty())
  {
    assert(h.top() == pq.top() && "test_heap1: incorrect order");
    h.pop();
    pq.pop();
  }
  assert(h.empty() && pq.empty() && "test_heap1: unequal sizes");
}

void test_heap2()
{
  Heap<dtype, MinHeapComparator> h;
  vector<dtype> v = {0,2};
  priority_queue<dtype, vector<dtype>, MinHeapComparator> pq;
  for(auto vi : v)
  {
    h.push(vi);
    pq.push(vi);
  }

  while(!h.empty())
  {
    assert(h.top() == pq.top() && "test_heap2: incorrect order");
    h.pop();
    pq.pop();
  }
  assert(h.empty() && pq.empty() && "test_heap2: unequal sizes");
}

void test_heap3()
{
  Heap<dtype, MaxHeapComparator> h;
  vector<dtype> v = {0,2};
  priority_queue<dtype, vector<dtype>, MaxHeapComparator> pq;
  for(auto vi : v)
  {
    h.push(vi);
    pq.push(vi);
  }

  while(!h.empty())
  {
    assert(h.top() == pq.top() && "test_heap3: incorrect order");
    h.pop();
    pq.pop();
  }
  assert(h.empty() && pq.empty() && "test_heap3: unequal sizes");
}

void test_heap4()
{
  Heap<dtype, MinHeapComparator> h;
  vector<dtype> v = {1000,1000};
  priority_queue<dtype, vector<dtype>, MinHeapComparator> pq;
  for(auto vi : v)
  {
    h.push(vi);
    pq.push(vi);
  }

  while(!h.empty())
  {
    assert(h.top() == pq.top() && "test_heap4: incorrect order");
    h.pop();
    pq.pop();
  }
  assert(h.empty() && pq.empty() && "test_heap4: unequal sizes");
}

void test_heap5()
{
  Heap<dtype, MaxHeapComparator> h;
  vector<dtype> v = {99,99};
  priority_queue<dtype, vector<dtype>, MaxHeapComparator> pq;
  for(auto vi : v)
  {
    h.push(vi);
    pq.push(vi);
  }

  while(!h.empty())
  {
    assert(h.top() == pq.top() && "test_heap5: incorrect order");
    h.pop();
    pq.pop();
  }
  assert(h.empty() && pq.empty() && "test_heap5: unequal sizes");
}

int main()
{
  test_heap0();
  test_heap1();
  test_heap2();
  test_heap3();
  test_heap4();
  test_heap5();
  return 0;
}
