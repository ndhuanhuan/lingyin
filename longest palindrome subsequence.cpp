// Leetcode.cpp : Defines the entry point for the console application.
//http://wxx5433.github.io/longest-palindromic-subsequence.html


#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <unordered_map>
#include <queue>
using namespace std;

int longestPalindromeSubseq(vector<int> nums) 
{
	if (nums.size() == 0) 
	{
		return 0;
	}

	const int n = nums.size();
	vector<vector<int>> dp(n, vector<int>(n,INT_MAX));
	for (int i = 0; i < n; ++i) 
	{
		dp[i][i] = 1;
	}
	for (int l = 2; l <= n; l++) 
	{
		for (int i = 0; i + l <= n; ++i) 
		{
			int j = i + l - 1;
			if (nums[i] == nums[j]) 
			{
				dp[i][j] = dp[i + 1][j - 1] + 2;
			}
			else 
			{
				dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
			}
		}
	}
	return dp[0][n-1];
}


// Driver program to test above function
int main()
{
	vector<int> test({ 4, 1, 2, 3, 4, 5, 6, 5, 4, 3, 4, 4, 4, 4, 4, 4, 4 });
	cout << longestPalindromeSubseq(test);
	//cout << next(18);
	return 0;
}
