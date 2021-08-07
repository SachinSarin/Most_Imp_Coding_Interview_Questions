/*
Given a binary tree T, find the maximum path sum.

The path may start and end at any node in the tree.

Input Format:

The first and the only argument contains a pointer to the root of T, A.
Output Format:

Return an integer representing the maximum sum path.
Constraints:

1 <= Number of Nodes <= 7e4
-1000 <= Value of Node in T <= 1000
Example :

Input 1:

       1
      / \
     2   3

Output 1:
     6

Explanation 1:
    The path with maximum sum is: 2 -> 1 -> 3

Input 2:
    
       -10
       /  \
     -20  -30

Output 2:
    -10

Explanation 2
    The path with maximum sum is: -10
*/
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int findMaxUtil(TreeNode * root , int &res)
{
    if(root==NULL)
    {
        return NULL;
    }
    int l = findMaxUtil(root->left,res);
    int r = findMaxUtil(root->right,res);

    int max_single = max(max(l,r)+root->val,root->val);
    int max_top = max(max_single, l + r + root->val);
 
    res = max(res, max_top); // Store the Maxiu
 
    return max_single;
} 
int Solution::maxPathSum(TreeNode* root) {
    
    // Initialize result
    int res = INT_MIN;
 
    // Compute and return result
    findMaxUtil(root, res);
    return res;
}
