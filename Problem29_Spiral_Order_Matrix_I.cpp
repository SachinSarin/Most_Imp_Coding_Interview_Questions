/*
Given a matrix of m * n elements (m rows, n columns), return all elements of the matrix in spiral order.

Example:

Given the following matrix:

[
    [ 1, 2, 3 ],
    [ 4, 5, 6 ],
    [ 7, 8, 9 ]
]
You should return

[1, 2, 3, 6, 9, 8, 7, 4, 5]
Problem Approach :

Complete solution in the hints.
*/

void printorder(const vector<vector<int>>&matrix , int R , int C,vector<int>&temp)
    {
        int top = 0;
        int left = 0;
        int right = C-1;
        int bottom = R-1;
        while(top<=bottom&&left<=right)
        {   
            
            //forward direction
            for(int i = left; i <=right; i++)
            {
                temp.push_back(matrix[top][i]);
            }
            top++;
            //for downward direction
            for(int i = top; i<=bottom; i++)
            {
                temp.push_back(matrix[i][right]);
            }
            right--;
            
            //for reverse direction
            if(top<=bottom)
            {
                for(int i = right; i>=left; i--)
                {
                    temp.push_back(matrix[bottom][i]);
                }
                bottom--;
            }
            //for upward
            if(left<=right)
            {
                for(int i = bottom; i>=top; i--)
                {
                    temp.push_back(matrix[i][left]);
                }
                left++;
            }
        }
    }
vector<int> Solution::spiralOrder(const vector<vector<int> > &nums) {
    vector<int> temp;
    int m = nums.size();
    int n = nums[0].size();
    printorder(nums,m,n,temp);
    return temp;
}
