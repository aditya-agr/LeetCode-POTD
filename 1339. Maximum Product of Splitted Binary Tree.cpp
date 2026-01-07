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
    long long res;
    int mod;
    long long dfs2(TreeNode* root, int &tot){
        if(!root)
            return 0;
        long long left = dfs2(root->left, tot);
        long long right = dfs2(root->right, tot);
        res = max(res, (left*(tot-left)));
        res = max(res, (right*(tot-right)));
        return (left+right+root->val);
    }
    void dfs(TreeNode* root, int &tot){
        if(!root)
            return;
        tot += root->val;
        dfs(root->left, tot);
        dfs(root->right, tot);
    }
    int maxProduct(TreeNode* root) {
        int tot = 0;
        dfs(root, tot);
        res = 0;
        mod = 1e9+7;
        dfs2(root, tot);
        return res%mod;
    }
};