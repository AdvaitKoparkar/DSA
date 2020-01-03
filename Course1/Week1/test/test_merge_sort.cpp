#include "../src/merge_sort.hpp"
#include <bits/stdc++.h>

using namespace std;

void test1()
{
  vector<float> C = {5.6, 2.3, 8.9, 4.9, 7.2};
  vector<float> C_sorted = {2.3, 4.9, 5.6, 7.2, 8.9};
  vector<float> ret = merge_sort<float>(C);
  assert(check_arrays(C_sorted, ret) && "Merge Test Case#1 Failed");
}

void test2()
{
  vector<float> C = {5.6};
  vector<float> C_sorted = {5.6};
  vector<float> ret = merge_sort<float>(C);
  assert(check_arrays(C_sorted, ret) && "Merge Test Case#2 Failed");
}

void test3()
{
  vector<float> C = {5.6, 2.2};
  vector<float> C_sorted = {2.2, 5.6};
  vector<float> ret = merge_sort<float>(C);
  assert(check_arrays(C_sorted, ret) && "Merge Test Case#3 Failed");
}

void test4()
{
  vector<int> C = {5, 9, 6, 8};
  vector<int> C_sorted = {5, 6, 8, 9};
  vector<int> ret = merge_sort<int>(C);
  assert(check_arrays(C_sorted, ret) && "Merge Test Case#4 Failed");
}

int main()
{
  test1();
  test2();
  test3();
  test4();
  return 0;
}
