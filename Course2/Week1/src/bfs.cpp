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

// perform bfs from src on graph
vector<datatype> bfs(datatype src, Graph *graph)
{
  vector<datatype> bfs_traversal;
  // if no graph or src not in graph, return {}
  if(!graph || !graph->nodes.count(src)) return bfs_traversal;
  // make q and vis
  queue<datatype> q;
  unordered_set<datatype> vis;
  // initialize q and vis
  q.push(src);
  vis.insert(src);
  // start bfs
  while(!q.empty())
  {
    // pop from queue
    datatype node = q.front();
    q.pop();
    // add to path
    bfs_traversal.push_back(node);
    // search neighbours of node
    for(datatype neigh : graph->edges[node])
    {
      // if unexplored neighbour, add to q
      if(!vis.count(neigh))
      {
        q.push(neigh);
        vis.insert(neigh);
      }
    }
  }
  // return path of bfs_traversal
  return bfs_traversal;
}

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
