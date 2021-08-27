/*
Problem Description

Given a string A, find length of the longest repeating sub-sequence such that the two subsequence don’t have same string character at same position,

i.e., any i’th character in the two subsequences shouldn’t have the same index in the original string.

NOTE: Sub-sequence length should be greater than or equal to 2.



Problem Constraints
 1 <= |A| <= 100



Input Format
The first and the only argument of input contains a string A.



Output Format
Return an integer, 0 or 1:

    => 0 : False
    => 1 : True


Example Input
Input 1:

 A = "abab"
Input 2:

 A = "abba"


Example Output
Output 1:

 1
Output 2:

 0


Example Explanation
Explanation 1:

 "ab" is repeated.
Explanation 2:

 There is no repeating subsequence.
*/
int Solution::anytwo(string str) {
     int n = str.length();
  
    // Create and initialize DP table
    int dp[n+1][n+1];
  //initializing first row and column in dp table
    for(int i=0;i<=n;i++){
      dp[i][0] =0;
      dp[0][i] =0;
    }
   
  
    // Fill dp table (similar to LCS loops)
    for (int i=1; i<=n; i++)
    {
        for (int j=1; j<=n; j++)
        {
            // If characters match and indexes are
            // not same
            if (str[i-1] == str[j-1] && i != j)
                dp[i][j] =  1 + dp[i-1][j-1];         
                       
            // If characters do not match
            else
                dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
        }
    }
    if(dp[n][n]>1)
    {
        return 1;
    }
    return 0;
}
