#include "../src/bfs.cpp"
#include<bits/stdc++.h>

void test_datatype()
{
  Graph *graph = read_graph("../test/graphs/graph0.txt");
  assert(graph->n_nodes == 1 && graph->n_edges == 0 && graph->nodes.size() == 1 && "test_datatype");
}

void test_simplebinarytree()
{
  Graph *graph = read_graph("../test/graphs/graph1.txt");
  assert(graph->n_nodes == 7 && graph->n_edges == 6 && graph->nodes.size() == 7 && "test_simplebinarytree");
}

int main()
{
  test_datatype();
  test_simplebinarytree();
  return 0;
}
