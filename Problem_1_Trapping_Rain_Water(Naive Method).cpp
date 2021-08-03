/*
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.

 

Example 1:


Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.
Example 2:

Input: height = [4,2,0,3,2,5]
Output: 9
 

Constraints:

n == height.length
0 <= n <= 2 * 104
0 <= height[i] <= 105

TIME COMPLEXITY = O(N2)
*/
#include <iostream>
using namespace std;

int main() {
	//Trapping rain waiter problem naive solution
	int n;
	cin>>n;
	int arr[n];
	for(int i = 0; i < n; i++)
	{
	    cin>>arr[i];
	}
	int res = 0;
	for(int i = 1 ; i< n-1 ; i++)
	{
	    int lmax = arr[i];
	    for(int j = 0; j < i; j++)
	    {
	        lmax = max(lmax,arr[j]);
	    }
	    int rmax = arr[i];
	    for(int j = i+1; j < n; j++)
	    {
	        rmax = max(rmax , arr[j]);
	    }
	    res = res + (min(lmax,rmax)-arr[i]);
	}
	cout<<res<<endl;
	return 0;
}
