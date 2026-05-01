/*
 * @Author: dsaDadas11
 * @Date: 2026-04-22 14:59:54
 * @LastEditTime: 2026-04-22 15:01:00
 * @Description: go for it!
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    map<TreeNode*,TreeNode*> fa;
    map<TreeNode*,int> dep;
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        dfs(root,NULL);

        if(dep[p]<dep[q]) swap(p,q);
        
        while(dep[p]>dep[q]) p=fa[p];

        while(p!=q) p=fa[p],q=fa[q];
        return p;
    }

    void dfs(TreeNode *u,TreeNode *fax)
    {
        fa[u]=fax;
        dep[u]=dep[fax]+1;
        if(u->left!=NULL) dfs(u->left,u);
        if(u->right!=NULL) dfs(u->right,u);
    }
};