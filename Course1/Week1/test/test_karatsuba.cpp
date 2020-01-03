#include "../src/karatsuba.hpp"
#include <bits/stdc++.h>

void test1()
{
  vector<int> m1 = {1,2};
  vector<int> m2 = {1,1};
  pad(m1, m2);
  assert(m1.size() == m2.size() && "Test padding Failed");
}

void test2()
{
  vector<int> m1 = {1,2};
  vector<int> m2 = {1,1};
  vector<int> m  = {2,3};
  vector<int> res = add(m1, m2);
  assert(check_equal(m, res) && "Test#1 add Failed");
}

void test3()
{
  vector<int> m1 = {9};
  vector<int> m2 = {1};
  vector<int> m  = {1,0};
  vector<int> res = add(m1, m2);
  assert(check_equal(m, res) && "Test#2 add Failed");
}

void test4()
{
  vector<int> m1 = {9,9};
  vector<int> m2 = {1,1,1};
  vector<int> m  = {2,1,0};
  vector<int> res = add(m1, m2);
  assert(check_equal(m, res) && "Test#3 add Failed");
}

void test5()
{
  vector<int> m1 = {9,9};
  vector<int> m2 = {8,9};
  vector<int> m  = {1,8,8};
  vector<int> res = add(m1, m2);
  assert(check_equal(m, res) && "Test#4 add Failed");
}

void test6()
{
  vector<int> v = {1,2,3,4}, a, b;
  split_number(v, a, b);
  vector<int> p0 = {1,2}, p1 = {3,4};
  assert(check_equal(p0, a) && check_equal(p1,b) && "Test#1 split Failed");
}

void test7()
{
  vector<int> v = {1,2,3,4,5}, a, b;
  split_number(v, a, b);
  vector<int> p0 = {1,2}, p1 = {3,4,5};
  assert(check_equal(p0,a) && check_equal(p1,b) && "Test#5 split Failed");
}

void test8()
{
  vector<int> m1={1}, m2={2}, res={2}, m;
  m = karatsuba(m1, m2);
  assert(check_equal(m,res) && "Test#1 multiply Failed");
}

void test9()
{
  vector<int> m1={8}, m2={2}, res={1,6}, m;
  m = karatsuba(m1, m2);
  assert(check_equal(m,res) && "Test#2 multiply Failed");
}

void test10()
{
  vector<int> x = {1}, res={1,0,0}, y;
  y = concat(x, 2);
  assert(check_equal(y,res) && "Test#1 concat Failed");
}

void test11()
{
  vector<int> x = {1,0,5}, res={1,0,5,0,0,0}, y;
  y = concat(x, 3);
  assert(check_equal(y,res) && "Test#2 concat Failed");
}

void test12()
{
  vector<int> m1 = {9}, m2 = {8}, res = {1}, x;
  x = subtract(m1, m2);
  assert(check_equal(x,res) && "Test#1 subtract Failed");
}

void test13()
{
  vector<int> m1 = {6}, m2 = {6}, res = {0}, x;
  x = subtract(m1, m2);
  assert(check_equal(x,res) && "Test#2 subtract Failed");
}

void test14()
{
  vector<int> m1 = {1,6}, m2 = {6}, res = {1,0}, x;
  x = subtract(m1, m2);
  assert(check_equal(x,res) && "Test#3 subtract Failed");
}

void test15()
{
  vector<int> m1 = {1,1,6}, m2 = {2,8}, res = {8,8}, x;
  x = subtract(m1, m2);
  assert(check_equal(x,res) && "Test#4 subtract Failed");
}


void test16()
{
  vector<int> m1 = {1,2}, m2 = {1,0}, res = {1,2,0}, x;
  x = karatsuba(m1, m2);
  assert(check_equal(x,res) && "Test#2 multiply Failed");
}

void test17()
{
  vector<int> m1 = {9,9}, m2 = {9,9}, res = {9,8,0,1}, x;
  x = karatsuba(m1, m2);
  assert(check_equal(x,res) && "Test#3 multiply Failed");
}

void test18()
{
  vector<int> m1 = {1,0,0}, m2 = {1,0}, res = {1,0,0,0}, x;
  x = karatsuba(m1, m2);
  print_vector(x);
  assert(check_equal(x,res) && "Test#4 multiply Failed");
}

void test19()
{
  vector<int> m1 = {1,2,3,4}, m2 = {9,8,7,6}, res = {1,2,1,8,6,9,8,4}, x;
  x = karatsuba(m1, m2);
  print_vector(x);
  assert(check_equal(x,res) && "Test#5 multiply Failed");
}

void test20()
{
  vector<int> m1 = {5,6,8,7}, m2 = {9,8,2,0}, res = {5,5,8,4,6,3,4,0}, x;
  x = karatsuba(m1, m2);
  print_vector(x);
  assert(check_equal(x,res) && "Test#6 multiply Failed");
}

int main()
{
  test1();
  test2();
  test3();
  test4();
  test5();
  test6();
  test7();
  test8();
  test9();
  test10();
  test11();
  test12();
  test13();
  test14();
  test15();
  test16();
  test17();
  test18();
  test19();
  test20();
  return 0;
}
