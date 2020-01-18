#include "../src/dijkstra.cpp"

void test_weighted_graph()
{
  WeightedGraph *graph = read_weighted_graph("../test/graphs/weightedgraph0.txt", true);
  assert(graph->n_nodes == 4 && graph->n_edges == 4 && "test_weighted_graph: incorrect number of edges or nodes");
  unordered_map<datatype, unordered_map<datatype,weighttype> > exp_edges;
  exp_edges[2].insert({6,1});
  exp_edges[2].insert({5,6});
  exp_edges[5].insert({8,2});
  exp_edges[6].insert({8,7});
  for(auto p : graph->edges)
  {
    assert(p.second == exp_edges[p.first] && "test_weighted_graph: incorrect edges or weights");
  }
}

void test_dijkstra0()
{
  WeightedGraph *graph = read_weighted_graph("../test/graphs/weightedgraph0.txt", true);
  unordered_map<datatype, weighttype> distances = dijkstra(graph, 2);
  unordered_map<datatype, weighttype> exp;
  exp[2] = 0;
  exp[6] = 1;
  exp[5] = 6;
  exp[8] = 8;
  assert(graph->n_nodes == distances.size() && "test_dijkstra0: number of vertices don't match");
  for(pair<datatype, weighttype> p : distances)
  {
    assert(p.second == exp[p.first] && "test_dijkstra0: incorrect shortest length");
  }
}

void test_dijkstra1()
{
  WeightedGraph *graph = read_weighted_graph("../test/graphs/weightedgraph1.txt", true);
  unordered_map<datatype, weighttype> distances = dijkstra(graph, 1);
  unordered_map<datatype, weighttype> exp;
  exp[1] = 0;
  exp[2] = 14;
  exp[8] = 7;
  exp[4] = 2;
  exp[5] = 6;
  exp[9] = 5;
  assert(graph->n_nodes == distances.size() && "test_dijkstra1: number of vertices don't match");
  for(pair<datatype, weighttype> p : distances)
  {
    assert(p.second == exp[p.first] && "test_dijkstra1: incorrect shortest length");
  }
}

void test_dijkstra2()
{
  WeightedGraph *graph = read_weighted_graph("../test/graphs/weightedgraph1.txt", true);
  unordered_map<datatype, weighttype> distances = dijkstra(graph, 1);
  unordered_map<datatype, weighttype> exp;
  exp[1] = 0;
  exp[2] = 14;
  exp[8] = 7;
  exp[4] = 2;
  exp[5] = 6;
  exp[9] = 5;
  assert(graph->n_nodes == distances.size() && "test_dijkstra1: number of vertices don't match");
  for(pair<datatype, weighttype> p : distances)
  {
    assert(p.second == exp[p.first] && "test_dijkstra1: incorrect shortest length");
  }
}

void test_dijkstra3()
{
  WeightedGraph *graph = read_weighted_graph("../test/graphs/weightedgraph2.txt", true);
  unordered_map<datatype, weighttype> distances = dijkstra(graph, 1);
  unordered_map<datatype, weighttype> exp;
  exp[1] = 0;
  exp[2] = numeric_limits<weighttype>::infinity();
  exp[3] = numeric_limits<weighttype>::infinity();
  exp[4] = numeric_limits<weighttype>::infinity();
  exp[5] = numeric_limits<weighttype>::infinity();
  assert(graph->n_nodes == distances.size() && "test_dijkstra3: number of vertices don't match");
  for(pair<datatype, weighttype> p : distances)
  {
    assert(p.second == exp[p.first] && "test_dijkstra3: incorrect shortest length");
  }
}

int main()
{
  test_weighted_graph();
  test_dijkstra0();
  test_dijkstra1();
  test_dijkstra2();
  test_dijkstra3();
  return 0;
}
