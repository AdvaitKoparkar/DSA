#ifndef BFS_H
#define BFS_H
#include "graph.h"
#include<bits/stdc++.h>

using namespace std;

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
#endif
