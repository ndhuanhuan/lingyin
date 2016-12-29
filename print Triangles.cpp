// Leetcode.cpp : Defines the entry point for the console application.
//http://www.geeksforgeeks.org/find-number-of-triangles-possible/


#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <unordered_map>
#include <queue>
using namespace std;

vector<vector<int>> printTriangles(vector<int> nums) 
{
	vector<vector<int>> res;
	int n = nums.size();
	sort(nums.begin(), nums.end());
	for (int i = 0; i < n - 2; i++) 
	{
		int k = i + 2;
		for (int j = i + 1; j < n; j++) 
		{
			while (k<n && (nums[i] + nums[j])>nums[k]) 
			{
				res.push_back({ nums[i],nums[j],nums[k] });
				cout << nums[i] << "," << nums[j] << "," << nums[k] << endl;
				k++;
			}
		}
	}
	return res;
}

// Driver program to test above function
int main()
{
	vector<int> nums({ 10,21,22,100,101,200,300 });
	printTriangles(nums);
	return 0;
}
