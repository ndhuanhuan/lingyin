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

struct DLLNode 
{
	DLLNode* prev;
	DLLNode* next;
	int val;
	DLLNode(int v) :val(v), prev(this), next(this) {};
};

class myStack 
{
private:
		int count;
		DLLNode* head;
		DLLNode* tail;
		DLLNode* mid;
		DLLNode* cur;
		int x;
public:
		myStack() 
		{
			count = 0;
			head = NULL;
			tail = NULL;
			mid = NULL;
			cur = NULL;
			x = 0;
		}

	void push(int n) {
		DLLNode* v = new DLLNode(n);
		if (tail) 
		{
			tail->next = v;
			v->prev = tail;
			head->prev = v;
			v->next =head;
			tail = v;
			count++;
			while ((count+1 )/ 2 > x) 
			{
				mid = mid->next;
				x++;
			}
		}
		else {
			head = v;
			tail = v;
			mid = v;
			x = 1;
			count = 1;
		}
	}

	int pop() {
		if (!head) {
			return INT_MIN;
		}
		if (head == tail) {
			int ret = head->val;
			delete head;
			head = tail = NULL;
			mid = NULL;
			x = 0;
			return ret;
		}
		else {
			
			count -= 1;
			while (x > (count + 1) / 2) 
			{
				mid = mid->prev;
				x -= 1;
			}
			DLLNode* temp_n = tail;
			int ret = temp_n->val;
			tail = tail->prev;
			tail->next = head;
			head->prev = tail;
			delete temp_n;
			return ret;
		}
	}

	int findMiddle() {
		if (mid)
			return mid->val;
		else
			return INT_MIN;
	}
};

// Driver program to test above function
int main()
{
	myStack stk;
	stk.push(0);
	cout << stk.findMiddle() << endl;
	stk.push(1);
	cout << stk.findMiddle() << endl;
	stk.push(2);
	cout << stk.findMiddle() << endl;
	stk.push(3);
	cout << stk.findMiddle() << endl;
	stk.push(4);
	cout << stk.findMiddle() << endl;
	stk.push(5);
	cout << stk.findMiddle() << endl<<endl;
	stk.pop();
	cout << stk.findMiddle() << endl;
	stk.pop();
	cout << stk.findMiddle() << endl;
	stk.pop();
	cout << stk.findMiddle() << endl;
	stk.pop();
	cout << stk.findMiddle() << endl;
	stk.pop();
	cout << stk.findMiddle() << endl;
	stk.pop();
	cout << stk.findMiddle() << endl;
	return 0;
}
