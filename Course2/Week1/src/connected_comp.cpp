#ifndef CONNECTED_COMP_H
#define CONNECTED_COMP_H
#include "graph.h"
#include "bfs.cpp"
#include <bits/stdc++.h>

using namespace std;

vector<vector<datatype>> connected_comp(Graph *graph)
{
  vector<vector<datatype>> comps;
  unordered_set<datatype> vis;
  for(pair<datatype, Node*> p : graph->nodes)
  {
    if(!vis.count(p.first))
    {
      comps.push_back(bfs(p.first, graph));
    }
  }
  return comps;
}

#endif
