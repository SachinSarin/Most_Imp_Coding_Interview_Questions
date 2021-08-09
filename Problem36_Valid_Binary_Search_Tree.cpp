/*
Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node’s key.
The right subtree of a node contains only nodes with keys greater than the node’s key.
Both the left and right subtrees must also be binary search trees.
Example :

Input : 
   1
  /  \
 2    3

Output : 0 or False


Input : 
  2
 / \
1   3

Output : 1 or True 
Return 0 / 1 ( 0 for false, 1 for true ) for this problem

SOLUTION APPROACH :

Complete solution in the hints.

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
 void solve(TreeNode* root , TreeNode* &prev , int &f)
 {
     if(!root)
     {
         return;

     }
     solve(root->left,prev,f);
     if(prev!=NULL&&root->val<=prev->val)
    {
            f = 0;
            return;
    }
    prev = root;
    solve(root->right,prev,f);
 }
int Solution::isValidBST(TreeNode* root) {


    int f = 1;
    TreeNode* prev = NULL;
    solve(root, prev , f);
    return f;
}
