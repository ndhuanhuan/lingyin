// Leetcode.cpp : Defines the entry point for the console application.
//
/** Suppose you are given a class that implements a k-dimensional array
* interface and you want to perform an operation that requires you to . 
* iterate over all elements of the array using its indices. To be
* specific, let's assume we want to calculate the sum of all elements in
* the array. The interface only provides you a get(int[]) method which
* allows one to fetch the element at that location given the indices along
* each dimension.
*
* For e.g, suppose we are dealing with 4D arrays, given [2, 1, 3, 0], the
* class will provide you array[2][1][3][0].
*
* Write a function that given an instance of the k-D array class and size
* of its dimensions, calculates the sum of all elements.
*
* @param instance of MultiDimArray class that implements a k-D array of
*        ints which provides a method x.get(int[]) to get the element
*        located at the indices in the array. 
* @param array of ints stating the size of each dimension of the k-D array
* @return an int which is the sum of all elements in the k-D array. visit 1point3acres.com for more.
*
* example: Given object m that holds a 2x2x3 array
* a=[[[3, 2, 2], [1, 5, 0]], [[2, 0, 1], [1, 1, -2]]] (Only for illustration
* purposes. This need not be the internal implementation of our k-D array)
* the function call arraySum(m, [2, 2, 3]) should return 16
* (=3+2+2+1+5+2+1+1+1-2) .
*/

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <unordered_map>
#include <queue>
using namespace std;

int sum = 0;
void helper(MultiDimArray &m, vector<int> path, const vector<int> &dimensions, int curDim) {
	if (curDim == dimensions.size()) {
		sum += m.get(path);
		return;
	}
	for (int i = 0; i<dimensions[curDim]; i++) {
		path[curDim] = i;
		helper(m, path, dimensions, curDim + 1);
	}
}
int arraySum(MuitiDimArray m, vector<int> dimensions) {
	vector<int> path(dimensions.size(), 0);
	helper(m, path, dimensions, 0);
	return sum;
}
