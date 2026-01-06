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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int mx = INT_MIN, l = 1, res = 1;
        while(!q.empty()){
            int n = q.size();
            int curr = 0;
            for(int i=0; i<n; i++){
                TreeNode* node = q.front();
                curr += node->val;
                q.pop();
                if(node->left)
                    q.push(node->left);
                if(node->right)
                    q.push(node->right);
            }
            if(curr > mx){
                mx = curr;
                res = l;
            }
            l++;
        }
        return res;
    }
};