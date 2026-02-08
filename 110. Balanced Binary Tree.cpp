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
    int dfs(TreeNode* root, bool &res){
        if(!root)
            return 0;
        int l = dfs(root->left, res);
        int r = dfs(root->right, res);
        if(abs(r-l) > 1)
            res = false;
        return 1+max(l,r);
    }
    bool isBalanced(TreeNode* root) {
        if(!root)
            return true;
        bool res=true;
        dfs(root, res);
        return res;
    }
};