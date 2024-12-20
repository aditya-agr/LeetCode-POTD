class Solution {
public:
    TreeNode* reverseOddLevels(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int lvl = 0;
        while(!q.empty()){
            int n = q.size();
            vector<TreeNode*> vec;
            for(int i=0; i<n; i++){
                TreeNode* curr = q.front();
                q.pop();
                vec.push_back(curr);
                if(curr->left)
                    q.push(curr->left);
                if(curr->right)
                    q.push(curr->right);
            }
            if(lvl%2){
                for(int i=0; i<n/2; i++){
                    int temp = vec[i]->val;
                    vec[i]->val = vec[n-i-1]->val;
                    vec[n-i-1]->val = temp;
                }
            }
            lvl++;
        }
        return root;
    }
};