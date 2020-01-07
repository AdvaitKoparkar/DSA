#ifndef DFS_H
#define DFS_H
#include "graph.h"
#include<bits/stdc++.h>

// perform dfs from src on graph
vector<datatype> dfs(datatype src, Graph *graph)
{
  vector<datatype> dfs_traversal;
  // if no graph or src not in graph, return {}
  if(!graph || !graph->nodes.count(src)) return dfs_traversal;
  // make q and vis
  stack<datatype> s;
  unordered_set<datatype> vis;
  // initialize q and vis
  s.push(src);
  vis.insert(src);
  // start bfs
  while(!s.empty())
  {
    // pop from queue
    datatype node = s.top();
    s.pop();
    // add to path
    dfs_traversal.push_back(node);
    // search neighbours of node
    for(datatype neigh : graph->edges[node])
    {
      // if unexplored neighbour, add to q
      if(!vis.count(neigh))
      {
        s.push(neigh);
        vis.insert(neigh);
      }
    }
  }
  // return path of dfs_traversal
  return dfs_traversal;
}


#endif
