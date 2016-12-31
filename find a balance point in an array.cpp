// Leetcode.cpp : Defines the entry point for the console application.
//


#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <unordered_map>
#include <queue>
using namespace std;

int equilibrium(vector<int> nums)
{
	int n = nums.size();
	int sum = 0;
	int leftSum = 0, i;
	for (i = 0; i < n; ++i) 
	{
		sum += nums[i];
	}
	for (i = 0; i < n; ++i) 
	{
		sum -= nums[i];
		if (leftSum == sum)
			return i;
		leftSum += nums[i];
	}
	return -1;
}


// Driver program to test above function
int main()
{
	vector<int> test({ -7, 1, 5, 2, -4, 3, 0 });
	cout << equilibrium(test);
	//cout << next(18);
	return 0;
}
