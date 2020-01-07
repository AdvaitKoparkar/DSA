#ifndef SCC_H
#define SCC_H
#include<bits/stdc++.h>
#include "graph.h"

using namespace std;

void dfs_f(Graph *graph, datatype src, vector<datatype> &new_order, unordered_set<datatype> &vis, size_t &t)
{
  vis.insert(src);
  for(datatype neigh : graph->edges[src])
  {
    if(!vis.count(neigh))
    {
      dfs_f(graph, neigh, new_order, vis, t);
    }
  }
  new_order[t++] = src;
}

void dfs_loop_f(Graph *graph, size_t &t, vector<datatype> &order, vector<datatype> &new_order, unordered_set<datatype> &vis)
{
  for(int i = order.size()-1; i >= 0; --i)
  {
    if(!vis.count(order[i]))
    {
      dfs_f(graph, order[i], new_order, vis, t);
    }
  }
}

void dfs_s(Graph *graph, datatype src, unordered_set<datatype> &vis, datatype &l, unordered_map<datatype, unordered_set<datatype>> &ret)
{
  vis.insert(src);
  if(!ret.count(l)) ret[l] = unordered_set<datatype>();
  ret[l].insert(src);
  for(datatype neigh : graph->edges[src])
  {
    if(!vis.count(neigh))
    {
      dfs_s(graph, neigh, vis, l, ret);
    }
  }
}


void dfs_loop_s(Graph *graph, datatype &leader, vector<datatype> &order, unordered_set<datatype> &vis, unordered_map<datatype, unordered_set<datatype>> &ret)
{
  for(int i = order.size()-1; i >= 0; --i)
  {
    if(!vis.count(order[i]))
    {
      leader = order[i];
      dfs_s(graph, order[i], vis, leader, ret);
    }
  }
}

unordered_map<datatype, unordered_set<datatype>> scc(Graph *graph)
{
  // scc return data structure
  unordered_map<datatype, unordered_set<datatype>> ret;
  // visited set
  unordered_set<datatype> vis;
  // time step: number of nodes finished
  size_t t = 0;
  // current leader
  datatype leader;
  // order to traverse through nodes
  vector<datatype> order(graph->n_nodes), new_order(graph->n_nodes);
  // assign arbitrary order for traversing nodes
  size_t idx = 0;
  for(unordered_map<datatype, Node*>::iterator node_it = graph->nodes.begin(); node_it != graph->nodes.end(); ++node_it, ++idx)
  {
    order[idx] = node_it->first;
  }

  // get transpose graph
  Graph *graph_tr = graph->transpose();
  // run first dfs loop on graph_tr
  dfs_loop_f(graph_tr, t, order, new_order, vis);
  // run second dfs on graph
  vis.clear();
  dfs_loop_s(graph, leader, new_order, vis, ret);
  return ret;
}

#endif
