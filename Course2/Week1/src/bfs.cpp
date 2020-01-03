#ifndef BFS_H
#define BFS_H
#include<bits/stdc++.h>

using namespace std;

typedef int datatype;

typedef struct Node
{
  datatype data;
  Node(datatype d) : data(d) {}
} Node;

class Graph
{
public:
  size_t n_nodes, n_edges;
  bool directed;
  unordered_map<datatype, Node*> nodes;
  unordered_map<datatype, vector<datatype>> edges;
};

Graph* read_graph(string filename, bool directed=false)
{
  // create file handle
  ifstream fh(filename);
  assert(fh.is_open() && "file could not be opened");
  // create graph obj
  Graph *graph = new Graph;
  assert(graph != nullptr && "out of memory");
  // set directed
  graph->directed = directed;

  size_t n_nodes, n_edges;

  // read number of nodes and adges
  fh >> n_nodes >> n_edges;
  // update graph obj
  graph->n_nodes = n_nodes;
  graph->n_edges = n_edges;
  // read and update node names
  for(size_t line_no = 0; line_no < graph->n_nodes; ++line_no)
  {
    datatype node;
    // read node from file
    fh >> node;
    graph->nodes[node] = new Node(node);
    // create entry in adjecency list
    graph->edges[node] = vector<datatype>();
  }
  // read and update edges
  for(size_t line_no = 0; line_no < graph->n_edges; ++line_no)
  {
    datatype a, b;
    // read from file
    fh >> a >> b;
    assert(graph->nodes.count(a) && graph->nodes.count(b) && "adding undeclared nodes");
    graph->edges[a].push_back(b);
    if(!graph->directed) graph->edges[b].push_back(a);
  }
  return graph;
}

#endif
