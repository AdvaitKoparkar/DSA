#include "../src/dfs.cpp"
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

void test_dfs1()
{
  Graph *graph = read_graph("../test/graphs/graph1.txt");
  vector<datatype> path = dfs(0, graph),
                   expected_path = {0, 2, 6, 5, 1, 4, 3};
  assert(path.size() == expected_path.size() && "test_bfs1: bfs path number of nodes incorrect");
  for(size_t i = 0; i < path.size(); ++i)
  {
    assert(find(expected_path.begin(), expected_path.end(), path[i]) != expected_path.end() && "test_dfs1: dfs path incorrect");
  }
}

int main()
{
  test_datatype();
  test_simplebinarytree();
  test_dfs1();
  return 0;
}
