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
    TreeNode* replaceValueInTree(TreeNode* root) {
        if(root==NULL)
            return root;
        vector<int> lvlsum;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int curr=0;
            int n = q.size();
            while(n--){
                TreeNode* node = q.front();
                q.pop();
                curr += node->val;
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            lvlsum.push_back(curr);
        }
        cout<<lvlsum.size();
        q.push(root);
        root->val = 0;
        int lvl=0;
        while(!q.empty()){
            int n = q.size();
            while(n--){
                TreeNode* node = q.front();
                q.pop();
                int sib = (node->left) ? node->left->val : 0;
                sib += (node->right) ? node->right->val : 0;
                if(node->left){
                    node->left->val = lvlsum[lvl+1] - sib;
                    q.push(node->left);
                }
                if(node->right){
                    node->right->val = lvlsum[lvl+1] - sib;
                    q.push(node->right);
                }
            }
            lvl++;
        }
        return root;
    }
};