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
    TreeNode* res;
    bool dfs(TreeNode* root, int &mxl, int cl){
        if(!root)
            return (cl == mxl);
        
        bool left = dfs(root->left, mxl, cl+1);
        bool right = dfs(root->right, mxl, cl+1);
        if(left && right)
            res = root;
        return left || right;
    }
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        int l=0;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            for(int i=0; i<n; i++){
                TreeNode* node = q.front();
                q.pop();
                if(node->left)
                    q.push(node->left);
                if(node->right)
                    q.push(node->right);
            }
            l++;
        }
        res = root;
        dfs(root, l, 0);
        return res;
    }
};