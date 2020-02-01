#ifndef CYCLE_H
#define CYCLE_H
#include "graph.h"
#include <bits/stdc++.h>

using namespace std;

bool cycle(Graph *graph);

bool visit_undirected(Graph *g, datatype src, datatype parent, unordered_set<datatype> &vis)
{
  // if already visisted, there is a cycle => return true
  if(vis.count(src)) return true;
  // mark as visited
  vis.insert(src);
  // for each neighbour of src
  for(datatype neigh : g->edges[src])
  {
    // visit neighbour but not parent
    if(neigh != parent && visit_undirected(g, neigh, src, vis)) return true;
  }
  // no cycle return false
  return false;
}

// helper function to detect cycle in undirected graph
// returns true if cycle present in undirected graph
bool undirectedcycle(Graph *g)
{
  // keep track of visited nodes
  unordered_set<datatype> vis;
  // for each node (required for disconnected graph)
  for(pair<datatype, Node*> node : g->nodes)
  {
    // visit node
    if(!vis.count(node.first))
    {
      if(visit_undirected(g, node.first, g->null_node, vis)) return true;
    }
  }
  // no cycle return false
  return false;
}

bool visit_directed(Graph *g, datatype src, unordered_set<datatype> &complete, unordered_set<datatype> &partial)
{
  // if node is partially visited => there is a back edge (cycle)
  // return true
  if(partial.count(src)) return true;
  // if node is completely visited, no need to visit it's neighbours
  // return false
  if(complete.count(src)) return false;
  // make it partially visited
  partial.insert(src);
  // visit neighbours recursively
  for(datatype neigh : g->edges[src])
  {
    if(visit_directed(g, neigh, complete, partial)) return true;
  }
  // move to completely visited
  partial.erase(src);
  complete.insert(src);
  // no cycle containing node src
  return false;
}

// helper function to detect cycle in directed graph
// returns true if cycle present in directed graph
bool directedcycle(Graph *g)
{
  // create arrays for completely
  // and partially visited nodes
  // required for detected cycles (back edges)
  // in directed graphs
  unordered_set<datatype> complete, partial;
  // iterate over all nodes of the graph
  for(pair<datatype, Node*> p : g->nodes)
  {
    // visit node
    if(visit_directed(g, p.first, complete, partial)) return true;
  }
  return false;
}

bool cycle(Graph *graph)
{
  // if empty graph, cannot contain cycle
  if(!graph) return false;
  // if undirected
  if(!graph->directed) return undirectedcycle(graph);
  // if directed
  else return directedcycle(graph);
}

#endif
