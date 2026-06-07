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
        unordered_set<int> st;
        int n = descriptions.size();
        for(int i=0; i<n; i++){
            TreeNode* p;
            if(mp.count(descriptions[i][0]))
                p = mp[descriptions[i][0]];
            else{
                p = new TreeNode(descriptions[i][0]);
                mp[descriptions[i][0]] = p;
            } 
            
            TreeNode* c;
            if(mp.count(descriptions[i][1]))
                c = mp[descriptions[i][1]];
            else{
                c = new TreeNode(descriptions[i][1]);
                mp[descriptions[i][1]] = c;
            }

            int left = descriptions[i][2];
            if(left)
                p->left = c;
            else
                p->right = c;
            
            st.insert(descriptions[i][1]);
        }
        for(auto &it : mp){
            if(st.find(it.first) == st.end())
                return it.second;
        }
        return NULL;
    }
};