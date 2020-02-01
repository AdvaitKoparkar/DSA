#ifndef ISTREE_H
#define ISTREE_H
#include "tree.h"
#include "../../Week1/src/connected_graph.cpp"
#include "../../Week1/src/cycle.h"
#include<bits/stdc++.h>

using namespace std;

bool istree(Tree *tree)
{
  assert(!tree->directed && "directed graph can't be a tree");
  cout << isconnectedgraph(tree) << " " << cycle(tree) << endl;
  return (!cycle(tree) && isconnectedgraph(tree));
}

bool ispolytree(Tree *tree)
{
  return true;
}

#endif
