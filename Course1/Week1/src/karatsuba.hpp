#ifndef KARATSUBA_H
#define KARATSUBA_H
#include<bits/stdc++.h>

using namespace std;

// utility to print vector
void print_vector(const vector<int> &m)
{
  for(int i = 0; i < m.size(); ++i) cout << m[i];
  cout << endl;
}

// utility to check if vectors are equal
bool check_equal(const vector<int> &m1, const vector<int> &m2)
{
  if(m1.size() != m2.size()) return false;
  for(int i = 0; i < m1.size(); ++i)
  {
    if(m1[i] != m2[i]) return false;
  }
  return true;
}

// function to pad vectors with 0 if necessary
void pad(vector<int> &m1, vector<int> &m2)
{
  bool flip = false;
  vector<int> tmp;
  // make m1 the smaller of m1 and m2
  if(m1.size() > m2.size())
  {
    tmp = m1;
    m1 = m2;
    m2 = tmp;
    flip = true;
  }
  // make m1 and m2 of the same size
  for(int i = m1.size(); i < m2.size(); ++i)
  {
    m1.insert(m1.begin(), 0);
  }
  if(flip)
  {
    tmp = m1;
    m1 = m2;
    m2 = tmp;
  }
}

// adding two vectors to get new vector
vector<int> add(const vector<int> &m1c, const vector<int> &m2c)
{
  // result of addition
  vector<int> m, m1(m1c), m2(m2c);
  // pad appropriately
  pad(m1, m2);
  int carry = 0;
  for(int i = m1.size()-1; i >= 0; --i)
  {
    int res = m1[i] + m2[i] + carry;
    // push units place
    m.push_back(res%10);
    // update carry
    carry = res / 10;
  }
  // add remaining carry
  if(carry) m.push_back(carry);
  // reverse to get in right order
  reverse(m.begin(), m.end());
  return m;
}

// function to remove preceding zeros
void remove_zeros(vector<int> &m)
{
  if(m.size() <= 1) return;
  int zero_count = 0;
  for(auto mi : m)
  {
    if(mi) break;
    ++zero_count;
  }
  if(zero_count)
  {
    m.erase(m.begin(), m.begin()+zero_count);
  }
}

// subtracting two vectors to get new vector
vector<int> subtract(const vector<int> &m1c, const vector<int> &m2c)
{
  vector<int> m, m1(m1c), m2(m2c);
  // pad appropriately
  pad(m1, m2);
  // result of addition
  int borrow = 0;
  for(int i = m1.size()-1; i >= 0; --i)
  {
    int res = m1[i] - m2[i] - borrow;
    // push units place
    if(res < 0)
    {
      m.push_back(res+10);
      borrow = 1;
    }
    else
    {
      m.push_back(res);
      borrow = 0;
    }
  }
  // reverse to get in right order
  reverse(m.begin(), m.end());
  remove_zeros(m);
  return m;
}

// multiply by power of ten
vector<int> concat(const vector<int> &m, int n)
{
  vector<int> res(m);
  while(n--)
  {
    res.push_back(0);
  }
  return res;
}


// split m into two parts a and b
void split_number(const vector<int> &m, vector<int> &a, vector<int> &b)
{
  int n = m.size();
  a = vector<int>(m.begin(), m.begin() + (m.size()/2));
  b = vector<int>(m.begin() + (m.size()/2), m.end());
}

vector<int> karatsuba(const vector<int> &m1c, const vector<int> &m2c)
{
  vector<int> m, a, b, c, d, ac, bd, t, x, m1(m1c), m2(m2c);
  cout << "---ENTER---\n";
  print_vector(m1);
  print_vector(m2);
  cout << "-----------\n";
  // pad vectors
  pad(m1, m2);
  int n = m1.size();
  // if one digit multiplication
  if(m1.size() == 1)
  {
    int res = m1[0]*m2[0];
    m.push_back(res%10);
    if(res >= 10) m.push_back(res/10);
    reverse(m.begin(), m.end());
    cout << "---EXIT---\n";
    print_vector(m1);
    print_vector(m2);
    cout << "----------\n";
    return m;
  }
  // split numbers
  split_number(m1,a,b);
  split_number(m2,c,d);
  ac = karatsuba(a,c);
  bd = karatsuba(b,d);
  t  = karatsuba(add(a,b),add(c,d));
  x = subtract(t, add(ac,bd));
  cout << "---EXIT---\n";
  print_vector(m1);
  print_vector(m2);
  print_vector(x);
  cout << "----------\n";
  if(n%2) m = add(add(concat(ac,n),concat(x,n/2 + 1)),bd);
  else m = add(add(concat(ac,n),concat(x,n/2)),bd);
  remove_zeros(m);
  return m;
}

#endif
