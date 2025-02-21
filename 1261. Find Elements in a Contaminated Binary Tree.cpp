class FindElements {
public:
    unordered_set<int> st;
    FindElements(TreeNode* root) {
        if(!root) return;
        queue<TreeNode*> q;
        root->val = 0;
        q.push(root);
        while(!q.empty()){
            TreeNode *curr = q.front();
            q.pop();
            int data = curr->val;
            st.insert(data);
            if(curr->left){
                curr->left->val = 2*data+1;
                q.push(curr->left);
            }
            if(curr->right){
                curr->right->val = 2*data+2;
                q.push(curr->right);
            }
        }
    }
    
    bool find(int target) {
        return st.find(target) != st.end();
    }
};