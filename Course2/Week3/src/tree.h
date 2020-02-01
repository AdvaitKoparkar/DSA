#ifndef TREE_H
#define TREE_H

#include <bits/stdc++.h>
#include "../../Week1/src/graph.h"

using namespace std;

class Tree : public Graph {};

Tree* read_tree(string filename, bool directed=false)
{
  // create file handle
  ifstream fh(filename);
  assert(fh.is_open() && "file could not be opened");
  // create tree obj
  Tree *tree = new Tree;
  assert(tree != nullptr && "out of memory");
  // set directed
  tree->directed = directed;

  size_t n_nodes, n_edges;

  // read number of nodes and adges
  fh >> n_nodes >> n_edges;
  // update tree obj
  tree->n_nodes = n_nodes;
  tree->n_edges = n_edges;
  // read and update node names
  for(size_t line_no = 0; line_no < tree->n_nodes; ++line_no)
  {
    datatype node;
    // read node from file
    fh >> node;
    tree->nodes[node] = new Node(node);
    // create entry in adjecency list
    tree->edges[node] = unordered_set<datatype>();
  }
  // read and update edges
  for(size_t line_no = 0; line_no < tree->n_edges; ++line_no)
  {
    datatype a, b;
    // read from file
    fh >> a >> b;
    assert(tree->nodes.count(a) && tree->nodes.count(b) && "adding undeclared nodes");
    tree->edges[a].insert(b);
    if(!tree->directed) tree->edges[b].insert(a);
  }
  return tree;
}

#endif
