/*
You are given an n x n 2D matrix representing an image.

Rotate the image by 90 degrees (clockwise).

You need to do this in place.

Note that if you end up using an additional array, you will only receive partial score.

Example:

If the array is

[
    [1, 2],
    [3, 4]
]
Then the rotated array becomes:

[
    [3, 1],
    [4, 2]
]
Note:You only need to implement the given function. Do not read input, instead use the arguments to the function. Do not print the output, instead return values as specified. Still have a doubt? Checkout Sample Codes for more details.
*/

void Solution::rotate(vector<vector<int> > &A) {
    

    int n = A.size();
    //Finding the transpose of the matrix
    for(int i =0; i < n; i++)
    {
        for(int j = i; j < n; j++)
        {
            swap(A[i][j], A[j][i]);
        }
    }

    for(int i = 0;i <n; i++)
    {
        for(int j = 0; j < n/2; j++){
            swap(A[i][j],A[i][n-j-1]);
        }
    }
}
