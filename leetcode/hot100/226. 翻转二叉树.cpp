/*
 * @Author: dsaDadas11
 * @Date: 2026-04-22 15:20:35
 * @LastEditTime: 2026-04-22 15:20:40
 * @Description: go for it!
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
    TreeNode* invertTree(TreeNode* root) {
        if(root==NULL) return NULL;
        dfs(root);
        return root;
    }

    void dfs(TreeNode* u)
    {
        swap(u->left,u->right);
        if(u->left!=NULL) dfs(u->left);
        if(u->right!=NULL) dfs(u->right);
    }
};