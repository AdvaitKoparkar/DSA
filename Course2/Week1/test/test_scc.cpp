#include "../src/scc.cpp"
#include <bits/stdc++.h>

using namespace std;

void test_transpose()
{
  Graph *graph = read_graph("../test/graphs/graph3.txt", true);
  Graph *graph_tr = graph->transpose();
  // check if number of nodes and edges is same
  assert(graph_tr->n_nodes == graph->n_nodes && graph->n_edges == graph_tr->n_edges && "test_transpose: error in transpose number of nodes/edges");
  // check if node data is copied
  for(pair<datatype, Node*> node : graph->nodes)
  {
    // check if node exists and data in node matches
    assert(graph_tr->nodes.count(node.first) && graph_tr->nodes[node.first]->data == node.second->data && "test_transpose: incorrect data copied");
  }
  // check if all edges are reversed
  for(pair<datatype, unordered_set<datatype>> edge : graph->edges)
  {
    for(datatype dest : edge.second)
    {
      assert(graph_tr->edges[dest].count(edge.first) &&
             "test_transpose: incorrect transpose operation");
    }
  }
}

void test_scc1()
{
  Graph *graph = read_graph("../test/graphs/graph5.txt", true);
  unordered_map<datatype, unordered_set<datatype>> ret, exp;
  exp[7] = unordered_set<datatype> ({7,1,4});
  exp[3] = unordered_set<datatype> ({0,3,6});
  exp[5] = unordered_set<datatype> ({2,5,8});
  ret = scc(graph);
  assert(ret == exp && "test_scc1: incorrect grouping");
}

void test_scc2()
{
  Graph *graph = read_graph("../test/graphs/graph6.txt", true);
  unordered_map<datatype, unordered_set<datatype>> ret, exp;
  exp[8] = unordered_set<datatype> ({8,2,5});
  exp[4] = unordered_set<datatype> ({1,4,7});
  exp[6] = unordered_set<datatype> ({3,6,9});
  ret = scc(graph);
  assert(ret == exp && "test_scc2: incorrect grouping");
}

void test_scc3()
{
  Graph *graph = read_graph("../test/graphs/graph7.txt", true);
  unordered_map<datatype, unordered_set<datatype>> ret, exp;
  exp[3] = unordered_set<datatype> ({3,2,1});
  exp[6] = unordered_set<datatype> ({4,6,7,5});
  exp[8] = unordered_set<datatype> ({8,9,10});
  exp[11] = unordered_set<datatype> ({11});
  ret = scc(graph);
  assert(ret == exp && "test_scc3: incorrect grouping");
}

int main()
{
  test_transpose();
  test_scc1();
  test_scc2();
  test_scc3();
  return 0;
}
