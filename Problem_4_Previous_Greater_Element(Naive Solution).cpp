/*
Given an array of distinct elements, find previous greater element for every element. If previous greater element does not exist, print -1.
Examples: 
 

Input : arr[] = {10, 4, 2, 20, 40, 12, 30}
Output :         -1, 10, 4, -1, -1, 40, 40

Input : arr[] = {10, 20, 30, 40}
Output :        -1, -1, -1, -1

Input : arr[] = {40, 30, 20, 10}
Output :        -1, 40, 30, 20
*/
#include <iostream>
using namespace std;

int main() {
	//PREVIOUS GREATER ELEMENT NAIVE SOLUTION
	int n;
	cin>>n;
	int arr[n];
	for(int i = 0; i < n; i++)
	{
	    cin>>arr[i];
	}
	for(int i = 0; i < n; i++)
	{
	   int j;
	    for( j = i-1; j >=0; j--)
	    {
	        if(arr[j]>arr[i])
	        {
	            cout<<arr[j]<<" ";
	            break;
	        }
	    }
	    if(j==-1)
	    {
	        cout<<-1<<" ";
	    }
	}
	return 0;
}
