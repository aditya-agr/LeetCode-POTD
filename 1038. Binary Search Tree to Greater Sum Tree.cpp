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
    void solve(TreeNode* root, int &cnt){
        if(root==NULL)
            return;
        solve(root->right, cnt);
        cnt += root->val;
        root->val = cnt;
        solve(root->left, cnt);
    }
    TreeNode* bstToGst(TreeNode* root) {
        int sum=0;
        solve(root, sum);
        return root;
    }
};