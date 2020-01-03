#ifndef MERGE_SORT_HPP
#define MERGE_SORT_HPP
#include<bits/stdc++.h>

using namespace std;

template<class t>
void print_vector(vector<t> V)
{
  size_t n = V.size();
  for(size_t i = 0; i < n; ++i)
  {
    cout << V[i] << ", ";
  }
  cout << endl;
}

template<class t>
bool check_arrays(vector<t> &A, vector<t> B, double tol=1e-4)
{
  if(A.size() != B.size()) return false;
  for(size_t i = 0; i < A.size(); ++i)
  {
    if(abs(A[i]-B[i]) > tol)
    {
      return false;
    }
  }
  return true;
}

template<class t>
vector<t> merge_sort(vector<t> C)
{
  // create array to be returned
  size_t N = C.size();
  if(N == 1) return C;

  // create space
  vector<t> A, B;
  if(N%2) A = vector<t>(N/2 + 1);
  else A = vector<t>(N/2);
  B = vector<t>(N/2);

  // copy into A and B
  for(size_t i = 0; i < N; ++i)
  {
    if(N%2 && i <= N/2) A[i] = C[i];
    else if(N%2 == 0 && i < N/2) A[i] = C[i];
    else if(N%2 && i > N/2) B[i-(N/2)-1] = C[i];
    else B[i-(N/2)] = C[i];
  }

  // divide and conquer
  vector<t> A_sorted = merge_sort(A);
  vector<t> B_sorted = merge_sort(B);
  // combine
  size_t i = 0, j = 0;
  for(size_t k = 0; k < N; ++k)
  {
    if((j >= B_sorted.size() && i < A_sorted.size()) || (i < A_sorted.size() && j < B_sorted.size() && A_sorted[i] < B_sorted[j]))
    {
      C[k] = A_sorted[i++];
    }
    else
    {
      C[k] = B_sorted[j++];
    }
  }
  return C;
}
#endif
