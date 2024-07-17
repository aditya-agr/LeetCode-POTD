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
    TreeNode* solve(TreeNode* root, unordered_set<int>& del, vector<TreeNode*> &res){
        if(!root)
            return root;
        root->left = solve(root->left, del, res);
        root->right = solve(root->right, del, res);
        if(del.find(root->val) != del.end()){
            if(root->left)
                res.push_back(root->left);
            if(root->right)
                res.push_back(root->right);
            return NULL;
        }
        return root;
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*> res;
        unordered_set<int> st(to_delete.begin(), to_delete.end());
        
        if(st.find(root->val) == st.end())
            res.push_back(root);
        solve(root, st, res);
        return res;
    }
};