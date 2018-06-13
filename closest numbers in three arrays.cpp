// Leetcode.cpp : Defines the entry point for the console application.
//https://www.geeksforgeeks.org/find-three-closest-elements-from-given-three-sorted-arrays/


#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <unordered_map>
#include <queue>
using namespace std;

void findClosest(vector<int> A, vector<int> B, vector<int> C) 
{
	int p = A.size(), q = B.size(), r = C.size();
	int res_i = 0, res_j = 0, res_k = 0;
	int i = 0, j = 0, k = 0;
	int diff = INT_MAX;
	while (i < p&&j < q, k < r) 
	{
		if (i == p || j == q || k == r) break;
		int minimum = min({ A[i],B[j],C[k] });
		int maximum = max({ A[i],B[j],C[k] });
		if (maximum - minimum < diff) 
		{
			res_i = i, res_j = j, res_k = k;
			diff = maximum - minimum;
		}
		if (diff == 0) break;

		if (A[i] == minimum)
		{
			if (i < p) 
			{
				i++;
			}
			else 
			{
				if (j < q&&k < r) 
				{
					B[j] < C[k] ? j++ : k++;
				}
				else if (j < q) 
				{
					j++;
				}
				else if (k < r) 
				{
					k++;
				}
				else 
				{
					break; //unlikely to reach this condition.
				}
			}
		}
		else if (B[j] == minimum) 
		{
			if (j < q)
			{
				j++;
			}
			else
			{
				if (i < p&&k < r)
				{
					A[i] < C[k] ? i++ : k++;
				}
				else if (i < p)
				{
					i++;
				}
				else if (k < r)
				{
					k++;
				}
				else
				{
					break; //unlikely to reach this condition.
				}
			}
		}
		else 
		{
			if (k < r)
			{
				k++;
			}
			else
			{
				if (j < q&&i < p)
				{
					B[j] < A[i] ? j++ : i++;
				}
				else if (j < q)
				{
					j++;
				}
				else if (i < p)
				{
					i++;
				}
				else
				{
					break; //unlikely to reach this condition.
				}
			}
		}

	}



	cout << A[res_i] << " " << B[res_j] << " " << C[res_k];
}

// Driver program to test above function
int main()
{
	vector<int> A({ 20,24,100 });
	vector<int> B({ 2,19,22,79,800 });
	vector<int> C({ 10,12,23,24,119 });
	findClosest(A, B, C);
	return 0;
}
