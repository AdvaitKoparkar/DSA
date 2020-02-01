#ifndef CONNECTED_GRAPH_H
#define CONNECTED_GRAPH_H

#include "graph.h"
#include <bits/stdc++.h>

using namespace std;

// utility dfs routine to start
// search from node src on
// graph. returns true if
// all nodes were explored
// by dfs starting from src
// else returns false
bool dfs(Graph *graph, datatype src)
{
  stack<datatype> s;
  unordered_set<datatype> vis;
  s.push(src);
  vis.insert(src);
  while(!s.empty())
  {
    datatype node = s.top();
    s.pop();
    for(datatype neigh : graph->edges[node])
    {
      if(!vis.count(neigh))
      {
        vis.insert(neigh);
        s.push(neigh);
      }
    }
  }
  return vis.size() == graph->n_nodes;
}

// Definition of Connected:
// if all nodes can be reached from
// any (at least one) node in the
// graph => connected graph
bool isconnectedgraph(Graph *graph)
{
  // if no graph exists return false
  if(!graph) return false;
  // zero node graph is connected
  if(!graph->n_nodes) return true;
  // loop through all nodes
  for(pair<datatype, Node*> p : graph->nodes)
  {
    // check if all nodes can be reached
    // starting from node p.first
    if(dfs(graph, p.first)) return true;
    if(!graph->directed) break;
  }
  return false;
}
#endif
