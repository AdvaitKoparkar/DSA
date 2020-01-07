#ifndef GRAPH_H
#define GRAPH_H

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
  unordered_map<datatype, unordered_set<datatype>> edges;

  // returns transpose of directed graph
  Graph* transpose()
  {
    assert(this->directed && "cannot transpose undirected graph");
    // create new directed graph
    Graph* graph_tr = new Graph();
    graph_tr->n_nodes = this->n_nodes;
    graph_tr->n_edges = this->n_edges;
    graph_tr->directed = this->directed;

    // copy nodes and transpose edges
    for(pair<datatype, Node*> node : this->nodes)
    {
      graph_tr->nodes[node.first] = new Node(*(node.second));
      for(datatype neigh : this->edges[node.first])
      {
        graph_tr->edges[neigh].insert(node.first);
      }
    }

    return graph_tr;
  }
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
    graph->edges[node] = unordered_set<datatype>();
  }
  // read and update edges
  for(size_t line_no = 0; line_no < graph->n_edges; ++line_no)
  {
    datatype a, b;
    // read from file
    fh >> a >> b;
    assert(graph->nodes.count(a) && graph->nodes.count(b) && "adding undeclared nodes");
    graph->edges[a].insert(b);
    if(!graph->directed) graph->edges[b].insert(a);
  }
  return graph;
}

#endif
