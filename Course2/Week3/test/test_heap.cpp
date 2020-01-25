#include "../src/heap.hpp"

typedef int dtype;

void test_heap0()
{
  Heap<dtype> h;
  vector<dtype> v = {0,2,5,4,6,3};
  for(auto vi : v)
  {
    h.insert(vi);
  }
  h.pop();
  h.pop();
  h.print_heap();
}

int main()
{
  test_heap0();
  return 0;
}
