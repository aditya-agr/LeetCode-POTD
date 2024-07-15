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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> mp;
        vector<int> parnt;
        set<int> chld;
        for(auto &i : descriptions){
            parnt.push_back(i[0]);
            chld.insert(i[1]);
            TreeNode *parent, *child;
            if(mp.find(i[0]) != mp.end())
                parent = mp[i[0]];
            else{
                parent = new TreeNode(i[0]);
                mp[i[0]] = parent;
            }
            if(mp.find(i[1]) != mp.end())
                child = mp[i[1]];
            else{
                child = new TreeNode(i[1]);
                mp[i[1]] = child;
            }
            if(i[2])
                parent->left = child;
            else
                parent->right = child;
        }
        for(auto &i : parnt)
            if(chld.find(i) == chld.end())
                return mp[i];
        return NULL;
    }
};