#include "../src/tree.h"
#include "../src/istree.h"

void test_tree0()
{
  Tree *tree = read_tree("../test/trees/tree0.txt", false);
  Tree *polytree = read_tree("../test/trees/tree0.txt", true);
  assert(istree(tree) && "test_tree0: tree test failed");
  assert(ispolytree(polytree) && "test_tree0: polytree test failed");
}

void test_tree1()
{
  Tree *tree = read_tree("../test/trees/tree1.txt", false);
  Tree *polytree = read_tree("../test/trees/tree1.txt", true);
  assert(istree(tree) && "test_tree1: tree test failed");
  assert(ispolytree(polytree) && "test_tree1: polytree test failed");
}


int main()
{
  // test_tree0();
  test_tree1();
  return 0;
}
