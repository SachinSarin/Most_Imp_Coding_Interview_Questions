/*
Problem Description

Given an integer array A  of size N.

You are also given an integer B, you need to find whether their exist a subset in A whose sum equal B.

If there exist a subset then return 1 else return 0.



Problem Constraints
1 <= N <= 100

1 <= A[i] <= 100

1 <= B <= 105



Input Format
First argument is an integer array A.

Second argument is an integer B.



Output Format
Return 1 if there exist a subset with sum B else return 0.



Example Input
Input 1:

 A = [3, 34, 4, 12, 5, 2]
 B = 9
Input 2:

 A = [3, 34, 4, 12, 5, 2]
 B = 30


Example Output
Output 1:

 1
Output 2:

 0


Example Explanation
Explanation 1:

 There is a subset (4, 5) with sum 9.
Explanation 2:

 There is no subset that add up to 30.
*/
int Solution::solve(vector<int> &A, int sum) {

   int n = A.size();
   int** dp = new int*[n+1];
   for(int i = 0; i <=n; i++)
   {
       dp[i] = new int[sum+1];
       
   }

   for(int i = 0; i <=n; i++)
   {
       for(int j = 0; j <=sum; j++)
       {
           if(i==0&&j==0)
           {
               dp[i][j] = true;
           }
           else if(i==0)
           {
               dp[i][j] = false;
           }
           else if(j==0)
           {
               dp[i][j] = true;
           }    
           else
           {    
               if(dp[i-1][j-1]==true)
               {
                   dp[i][j] = true;
               }
               else
               {
                   int val = A[i-1];
                   if(j>=val)
                   {
                       if(dp[i-1][j-val]==true)
                       {
                           dp[i][j] = true;
                       }
                   }
               }
           }
       }
   }
    return dp[n][sum];
}
