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

void test_bfs1()
{
  Graph *graph = read_graph("../test/graphs/graph1.txt");
  vector<datatype> path = bfs(0, graph),
                   expected_path = {0, 1, 2, 3, 4, 5, 6};
  assert(path.size() == expected_path.size() && "test_bfs1: bfs path number of nodes incorrect");
  for(size_t i = 0; i < path.size(); ++i)
  {
    assert(path[i] == expected_path[i] && "test_bfs1: bfs path incorrect");
  }
}

int main()
{
  test_datatype();
  test_simplebinarytree();
  test_bfs1();
  return 0;
}
