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
    void makeg(TreeNode* root, TreeNode* prev, unordered_map<TreeNode*, vector<TreeNode*>> &adj, unordered_set<TreeNode*> &st){
        if(!root)
            return;
        if(!root->left && !root->right)
            st.insert(root);
        if(prev != NULL){
            adj[prev].push_back(root);
            adj[root].push_back(prev);
        }
        makeg(root->left, root, adj, st);
        makeg(root->right, root, adj, st);
    }
    int countPairs(TreeNode* root, int distance) {
        unordered_map<TreeNode*, vector<TreeNode*>> adj;
        unordered_set<TreeNode*> st;
        makeg(root, NULL, adj, st);

        int cnt=0;
        for(auto &leaf : st){
            unordered_set<TreeNode*> visited;
            queue<TreeNode*> q;
            q.push(leaf);
            visited.insert(leaf);

            for(int lvl=0; lvl<=distance; lvl++){
                int sze = q.size();
                while(sze--){
                    TreeNode* node = q.front();
                    q.pop();
                    if(node!=leaf && st.count(node))
                        cnt++;
                    for(auto &negb : adj[node]){
                        if(!visited.count(negb)){
                            q.push(negb);
                            visited.insert(negb);
                        }
                    }
                }
            }
        }
        return cnt/2;
    }
};