#include <bits/stdc++.h>
#include "../src/graph.h"
#include "../src/connected_graph.cpp"

void test_connected_graph0()
{
  Graph *graph_directed = read_graph("../test/graphs/graph8.txt", true);
  Graph *graph_undirected = read_graph("../test/graphs/graph8.txt", false);
  assert(!isconnectedgraph(graph_directed) && "test_connected_graph0: incorrect result for directed");
  assert(!isconnectedgraph(graph_undirected) && "test_connected_graph0: incorrect result for undirected");
}

void test_connected_graph1()
{
  Graph *graph_directed = read_graph("../test/graphs/graph9.txt", true);
  Graph *graph_undirected = read_graph("../test/graphs/graph9.txt", false);
  assert(isconnectedgraph(graph_directed) && "test_connected_graph9: incorrect result for directed");
  assert(isconnectedgraph(graph_undirected) && "test_connected_graph9: incorrect result for undirected");
}

void test_connected_graph2()
{
  Graph *graph_directed = read_graph("../test/graphs/graph10.txt", true);
  Graph *graph_undirected = read_graph("../test/graphs/graph10.txt", false);
  assert(!isconnectedgraph(graph_directed) && "test_connected_graph2: incorrect result for directed");
  assert(!isconnectedgraph(graph_undirected) && "test_connected_graph2: incorrect result for undirected");
}

void test_connected_graph3()
{
  Graph *graph_directed = read_graph("../test/graphs/graph11.txt", true);
  Graph *graph_undirected = read_graph("../test/graphs/graph11.txt", false);
  assert(!isconnectedgraph(graph_directed) && "test_connected_graph3: incorrect result for directed");
  assert(isconnectedgraph(graph_undirected) && "test_connected_graph3: incorrect result for undirected");
}


int main()
{
  test_connected_graph0();
  test_connected_graph1();
  test_connected_graph2();
  test_connected_graph3();
  return 0;
}
