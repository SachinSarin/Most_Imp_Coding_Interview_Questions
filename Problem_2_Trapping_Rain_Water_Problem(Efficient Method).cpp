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

*/
#include <iostream>
using namespace std;

int main() {
    //Trapping rain water problem efficient method O(N)
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0; i < n; i++)
    {
        cin>>arr[i];
        
    }
    
    //pre-compute the leftmax and rightmax value
    int lmax[n];
    int rmax[n];
    lmax[0] = arr[0];
    for(int i = 1; i < n; i++)
    {
        lmax[i] = max(lmax[i-1],arr[i]);
    }
    
    rmax[n-1] = arr[n-1];
    for(int j = n-2; j>=0; j--)
    {
        rmax[j] = max(arr[j],rmax[j+1]);
    }
    int res = 0;
    for(int i = 1; i < n-1; i++)
    {
        res = res + (min(lmax[i],rmax[i])-arr[i]);
    }
    
    cout<<res<<endl;
	return 0;
}
