#include "../src/connected_comp.cpp"
#include<bits/stdc++.h>

using namespace std;

void test_datatype()
{
  Graph *graph = read_graph("../test/graphs/graph0.txt");
  assert(graph->n_nodes == 1 && graph->n_edges == 0 && graph->nodes.size() == 1 && "test_datatype");
}

void test_unconnected_graph()
{
  Graph *graph = read_graph("../test/graphs/graph2.txt");
  vector<vector<datatype>> comps = connected_comp(graph);
  for(auto v : comps)
  {
    for(auto x : v)
    {
      cout << x << ", ";
    }
    cout << endl;
  }
}

int main()
{
  test_datatype();
  test_unconnected_graph();
}
