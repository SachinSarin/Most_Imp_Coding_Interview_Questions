/*
Given a grid of size m * n, lets assume you are starting at (1,1) and your goal is to reach (m,n). At any instance, if you are on (x,y), you can either go to (x, y + 1) or (x + 1, y).

Now consider if some obstacles are added to the grids. How many unique paths would there be?

An obstacle and empty space is marked as 1 and 0 respectively in the grid.

Example :

There is one obstacle in the middle of a 3x3 grid as illustrated below.

[
  [0,0,0],
  [0,1,0],
  [0,0,0]
]
The total number of unique paths is 2.

Note: m and n will be at most 100.
*/  
int solve(vector<vector<int>>& grid , int** dp , int m , int n , int row , int col)
    {
        //margin conditions
        
        if(row < 0 || col < 0 || row >=m || col >=n || grid[row][col] ==1 )
        {
            return 0;
        }
        //final conditions;
        if(row==m-1&&col==n-1)
        {
            dp[row][col] = 1;
            return 1;
        }
        if(dp[row][col]!=-1)
        {
            return dp[row][col];
        }
        dp[row][col] = solve(grid,dp,m,n,row,col+1) + solve(grid,dp,m,n,row+1,col);
        return dp[row][col];
        
        //recusive conditions
    }
int Solution::uniquePathsWithObstacles(vector<vector<int> > &grid) {
    int m = grid.size();
        int n = grid[0].size();
        
        int** dp = new int*[m];
        for(int i = 0; i < m ; i++)
        {
            dp[i] = new int[n];
            for(int j = 0; j < n; j++)
            {
                dp[i][j] = -1;
            }
        }
        
        int result = solve(grid,dp,m,n,0,0);
        return result;
}
