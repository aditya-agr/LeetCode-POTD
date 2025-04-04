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
    unordered_map<TreeNode*, int> mp;
    int maxi;
    void depth(TreeNode* root, int d){
        mp[root] = d;
        maxi = max(maxi, d);
        if(root->left) depth(root->left, d+1);
        if(root->right) depth(root->right, d+1);
    }
    TreeNode* solve(TreeNode* root){
        if(!root)
            return NULL;
        if(mp[root] == maxi)
            return root;
        TreeNode* left = solve(root->left);
        TreeNode* right = solve(root->right);
        if(left and right)
            return root;
        if(left) return left;
        if(right) return right;
        return NULL;
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        maxi = -1;
        depth(root, 0);
        return solve(root);
    }
};