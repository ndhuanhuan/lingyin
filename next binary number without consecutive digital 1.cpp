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

int next(int x) {              /* Look for a number bigger than x. */
	x += 1;
	int mask = 3,                /* Use the mask to look for 11.     */
		pos = 2;                 /* Track our location in the bits.  */
	while (mask <= x) {
		if ((mask & x) == mask) {  /* If we find 11, shift right to    */
			x >>= pos;               /*  zero it out.                    */
			x += 1;                  /* Add 1, shift back to the left,   */
			x <<= pos;               /*  and continue the search.        */
		}
		mask <<= 1;                /* Advance the mask (could advance  */
		pos += 1;                  /*  another bit in the above case). */
	}
	return x;
}

// Driver program to test above function
int main()
{
	cout << next(18);
	return 0;
}
