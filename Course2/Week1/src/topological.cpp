#ifndef TOPOLOGICAL_H
#define TOPOLOGICAL_H
#include<bits/stdc++.h>
#include "graph.h"

using namespace std;

bool visit(Graph *graph, datatype src, unordered_set<datatype> &complete,
           unordered_set<datatype> &partial, vector<datatype> &topo)
{
  // if node is partially explored => cycle in directed graph
  if(partial.count(src)) return false;
  // if completely explored => skip
  if(complete.count(src)) return true;
  // put node in partially explored set
  partial.insert(src);
  // dfs => explore neighbours
  for(datatype neigh : graph->edges[src])
  {
    // if visit returns false => not a DAG
    if(!visit(graph, neigh, complete, partial, topo)) return false;
  }
  // move src from partially explored to completely explored
  partial.erase(src);
  complete.insert(src);
  // push node into topo (the leaf node will appear first => hence reverse step is necessary)
  topo.push_back(src);
  return true;
}

// topologically sort directed graph and return nodes in topological order
vector<datatype> topological_sort(Graph *graph)
{
  // nodes in topological order to be returned
  vector<datatype> topo;
  // paritally explored and completely explored nodes
  unordered_set<datatype> partial, complete;
  // for each node in graph
  for(pair<datatype, Node*> node : graph->nodes)
  {
    // if visit returns false => not a DAG
    if(!visit(graph, node.first, complete, partial, topo)) return {};
  }
  // correct topo order
  reverse(topo.begin(), topo.end());
  return topo;
}

#endif
