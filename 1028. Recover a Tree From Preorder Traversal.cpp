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
    TreeNode* solve(string &s, int &i, int d){
        int n = s.length();
        if(i>=n) return NULL;
        int j = i;
        while(j<n && s[j]=='-')
            j++;
        int dashes = j-i;
        if(d != dashes) return NULL;
        i = j;
        int num = 0;
        while(i<n && s[i]>='0' && s[i]<='9'){
            num = num*10 + (s[i]-'0');
            i++;
        }
        TreeNode* root = new TreeNode(num);
        root->left = solve(s, i, d+1);
        root->right = solve(s, i, d+1);
        return root;
    }
    TreeNode* recoverFromPreorder(string traversal) {
        int i=0;
        return solve(traversal, i, 0);
    }
};