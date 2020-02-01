#include "../src/cycle.h"

void test_cycle0()
{
  Graph *graph_undirected = read_graph("../test/graphs/graph12.txt", false);
  Graph *graph_directed = read_graph("../test/graphs/graph12.txt", true);
  assert(cycle(graph_undirected) && "test_cycle0: undirected failed");
  assert(cycle(graph_directed) && "test_cycle0: directed failed");
}

void test_cycle1()
{
  Graph *graph_undirected = read_graph("../test/graphs/graph13.txt", false);
  Graph *graph_directed = read_graph("../test/graphs/graph13.txt", true);
  assert(cycle(graph_undirected) && "test_cycle1: undirected failed");
  assert(cycle(graph_directed) && "test_cycle1: directed failed");
}

void test_cycle2()
{
  Graph *graph_undirected = read_graph("../test/graphs/graph14.txt", false);
  Graph *graph_directed = read_graph("../test/graphs/graph14.txt", true);
  assert(!cycle(graph_undirected) && "test_cycle2: undirected failed");
  assert(!cycle(graph_directed) && "test_cycle2: directed failed");
}

void test_cycle3()
{
  Graph *graph_undirected = read_graph("../test/graphs/graph15.txt", false);
  Graph *graph_directed = read_graph("../test/graphs/graph15.txt", true);
  assert(cycle(graph_undirected) && "test_cycle3: undirected failed");
  assert(!cycle(graph_directed) && "test_cycle3: directed failed");
}

int main()
{
  test_cycle0();
  test_cycle1();
  test_cycle2();
  test_cycle3();
  return 0;
}
