/*
Given the root of a binary search tree (BST) with duplicates, return all the mode(s) (i.e., the most frequently occurred element) in it.

If the tree has more than one mode, return them in any order.

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than or equal to the node's key.
The right subtree of a node contains only nodes with keys greater than or equal to the node's key.
Both the left and right subtrees must also be binary search trees.
 

Example 1:


Input: root = [1,null,2,2]
Output: [2]
Example 2:

Input: root = [0]
Output: [0]
 

Constraints:

The number of nodes in the tree is in the range [1, 104].
-105 <= Node.val <= 105
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void solve(TreeNode* root , unordered_map<int,int>&mp)
    {
        if(root==NULL)
        {
            return;
        }
        mp[root->val]++;
        solve(root->left,mp);
        solve(root->right,mp);
        return;
        
    }
    vector<int> findMode(TreeNode* root) {
        
        if(root&&!root->left&&!root->right)
        {
            return {root->val};
        }
       
        vector<int> result;
        unordered_map<int,int> mp;
        solve(root,mp);
        if(root==NULL)
        {
            return {};
        }
        int best = 0;
        for(auto x : mp)
        {
            if(best < x.second)
            {
                best = x.second;
            }
        }
        for(auto x : mp)
        {   
                if(x.second==best)
                {
                    result.push_back(x.first);
                }
                
            
        }
        
        return result;
    }
};
