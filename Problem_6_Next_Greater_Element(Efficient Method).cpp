/*
Given an array, print the Next Greater Element (NGE) for every element. The Next greater Element for an element x is the first greater element on the right side of x in the array. Elements for which no greater element exist, consider the next greater element as -1. 

Examples: 

For an array, the rightmost element always has the next greater element as -1.
For an array that is sorted in decreasing order, all elements have the next greater element as -1.
For the input array [4, 5, 2, 25], the next greater elements for each element are as follows.
Element       NGE
   4      -->   5
   5      -->   25
   2      -->   25
   25     -->   -1
d) For the input array [13, 7, 6, 12}, the next greater elements for each element are as follows.  

  Element        NGE
   13      -->    -1
   7       -->     12
   6       -->     12
   12      -->     -1
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin>>n;
	int arr[n];
	for(int i = 0; i<n; i++)
	{
	    cin>>arr[i];
	}
	stack<int> s;
	s.push(arr[n-1]);
	vector<int> v;
	v.push_back(-1);
	for(int i = n-2; i>=0; i--)
	{
	    while(s.empty()==false && arr[i]>=s.top())
	    {
	        s.pop();
	    }
	    int pg = (s.empty())?-1:s.top();
	   v.push_back(pg);
	    s.push(arr[i]);
	}
	for(int i = n-1; i>=0; i--)
	{
	    cout<<v[i]<<" ";
	}
	cout<<endl;
	return 0;
}
