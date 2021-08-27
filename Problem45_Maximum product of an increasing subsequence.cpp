#include <iostream>
using namespace std;
int maximum_product(int arr[] , int n)
{
    int* dp = new int[n];
    for(int i = 0; i < n; i++)
    {
        dp[i] = arr[i];
    }
    
    for(int i = 1; i < n; i++)
    {
        for(int j = i-1; j >=0; j--)
        {
            if(arr[j]>=arr[i])
            {
                continue;
            }
            int possibleoutput = arr[i]*dp[j];
            if(dp[i] < possibleoutput)
            {
                dp[i] = possibleoutput;
            }
        }
    }
    
    int max = 0;
    for(int i = 0; i < n; i++)
    {
        if(max < dp[i])
        {
            max = dp[i];
        }
    }
    return max;
}
int main() {
	int n ;
	cin>>n;
	int arr[n];
	for(int i = 0; i < n; i++)
	{
	    cin>>arr[i];
	}
	cout<<maximum_product(arr,n)<<endl;
	return 0;
}
