class Solution {
public:
    int minimumOperations(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int cnt=0;
        while(!q.empty()){
            int n= q.size();
            vector<int> curr;
            unordered_map<int, int> mp;
            for(int i=0; i<n; i++){
                TreeNode* node = q.front();
                q.pop();
                curr.push_back(node->val);
                mp[node->val] = i;
                if(node->left)
                    q.push(node->left);
                if(node->right)
                    q.push(node->right);
            }
            vector<int> scurr = curr;
            sort(scurr.begin(), scurr.end());
            for(int i=0; i<n; i++){
                if(scurr[i] != curr[i]){
                    cnt++;
                    int idx = mp[scurr[i]];
                    mp[curr[i]] = idx;
                    mp[scurr[i]] = i;
                    swap(curr[i], curr[idx]);
                }
            }
        }
        return cnt;
    }
};