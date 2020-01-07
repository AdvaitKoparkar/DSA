#include "../src/topological.cpp"
#include <bits/stdc++.h>

using namespace std;

void test_topological_sort()
{
  Graph *graph = read_graph("../test/graphs/graph3.txt", true);
  vector<datatype> expected = {0, 1, 2, 3, 4, 5}, ret;
  ret = topological_sort(graph);
  assert(ret.size() == expected.size() && "test_topological_sort: size unequal");
  for(size_t i = 0; i < ret.size(); ++i)
  {
    assert(ret[i] == expected[i] && "test_topological_sort: wrong op");
  }
}

void test_topological_nonDAG()
{
  Graph *graph = read_graph("../test/graphs/graph4.txt", true);
  vector<datatype> expected = {}, ret;
  ret = topological_sort(graph);
  assert(ret.size() == expected.size() && "test_topological_sort: size unequal");
  for(size_t i = 0; i < ret.size(); ++i)
  {
    assert(ret[i] == expected[i] && "test_topological_sort: wrong op");
  }
}


int main()
{
  test_topological_sort();
  test_topological_nonDAG();
  return 0;
}
