// Leetcode.cpp : Defines the entry point for the console application.
//http://wxx5433.github.io/flowerbed.html


#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <unordered_map>
#include <queue>
using namespace std;

bool canPlaceFlower(vector<int> plots, int num) 
{
	if (plots.size() == 0) return false;
	int count = 0;
	for (int i = 0; i < plots.size(); i++) 
	{
		if (plots[i] == 1) 
		{
			continue;
		}
		if (i == 0) //first plot
		{
			if (i + 1 < plots.size() && plots[i + 1] == 0) 
			{
				++count;
				plots[i] = 1;
			}
		}
		else if(plots[i-1]==0)
		{
			if (i + 1 == plots.size() || (i + 1 < plots.size() && plots[i + 1] == 0)) 
			{
				++count;
				plots[i] = 1;
			}
		}

		if (count == num) 
		{
			return true;
		}
	}
	return false;
}
// Driver program to test above function
int main()
{
	vector<int> test = {1,0,1,1,1,0};
	cout << canPlaceFlower(test, 1)<<endl;
	return 0;
}
