#ifndef DIJKSTRA_H
#define DIJKSTRA_H
#include<bits/stdc++.h>
#include "../../Week1/src/graph.h"

using namespace std;

struct op
{
  bool operator () (pair<datatype, weighttype> const &l, pair<datatype, weighttype> const &r)
  {
    return l.second >= r.second;
  }
};

unordered_map<datatype, weighttype> dijkstra(WeightedGraph *graph, datatype src)
{
  // keep track of unexplored nodes (useful when graph is disconnected)
  unordered_set<datatype> unexplored;
  // put all nodes in unexplored
  for(pair<datatype, Node*> p : graph->nodes) unexplored.insert(p.first);
  // store distances to explored nodes
  unordered_map<datatype, weighttype> explored;
  // initialize pq with src node
  priority_queue<pair<datatype, weighttype>, vector<pair<datatype, weighttype>>, op> pq;
  pq.push({src,0});
  // main dijkstra loop
  while(!pq.empty())
  {
    // take node from top of pq and explore it
    pair<datatype, weighttype> cur_node = pq.top();
    pq.pop();
    if(explored.count(cur_node.first)) continue;
    explored[cur_node.first] = cur_node.second;
    unexplored.erase(cur_node.first);
    // add all it's neighbours to the pq
    for(pair<datatype, weighttype> neigh : graph->edges[cur_node.first])
    {
      pq.push({neigh.first, neigh.second+cur_node.second});
    }
  }
  // if there are any unexplored nodes, they are not reachable
  for(datatype unexplored_node : unexplored) explored[unexplored_node] = numeric_limits<weighttype>::infinity();

  return explored;
}

#endif
