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
    TreeNode* lca(TreeNode* root, int src, int dest){
        if(!root)
            return NULL;
        if(root->val==src || root->val==dest)
            return root;

        TreeNode* l = lca(root->left, src, dest);
        TreeNode* r = lca(root->right, src, dest);

        if(l && r)
            return root;

        return l ? l : r;
    }
    bool findpath(TreeNode* root, int target, string &path){
        if(!root)
            return false;

        if(root->val == target)
            return true;
        
        path.push_back('L');
        if(findpath(root->left, target, path))
            return true;
        path.pop_back();
        path.push_back('R');
        if(findpath(root->right, target, path))
            return true;
        path.pop_back();
        return false;
    }
    string getDirections(TreeNode* root, int startValue, int destValue) {
        TreeNode * LCA = lca(root, startValue, destValue);

        string lcaTosrc="", lcaTodest="";
        findpath(LCA, startValue, lcaTosrc);
        findpath(LCA, destValue, lcaTodest);

        int n = lcaTosrc.length();
        string res(n, 'U');
        res += lcaTodest;
        return res;
    }
};