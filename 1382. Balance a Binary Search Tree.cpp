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
    void inorder(TreeNode* root, vector<int> &a){
        if(!root)
            return;
        inorder(root->left, a);
        a.push_back(root->val);
        inorder(root->right, a);
    }
    TreeNode* construct(int l, int r, vector<int> &a){
        if(l>r)
            return NULL;
        int mid = l + (r-l)/2;
        TreeNode* root = new TreeNode(a[mid]);
        root->left = construct(l, mid-1, a);
        root->right = construct(mid+1, r, a);
        return root;
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> a;
        inorder(root, a);
        int l=0, r=a.size()-1;
        return construct(l , r, a);
    }
};