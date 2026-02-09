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
    void inorder(TreeNode* root, vector<int> &nums){
        if(!root)
            return;
        inorder(root->left, nums);
        nums.push_back(root->val);
        inorder(root->right, nums);
    }
    TreeNode* build(TreeNode* node, int st, int ed, vector<int> &nums){
        if(st>ed)
            return NULL;
        if(st == ed)
            return new TreeNode(nums[st]);
        int mid = st+(ed-st)/2;
        node = new TreeNode(nums[mid]);
        node->left = build(node->left, st, mid-1, nums);
        node->right = build(node->right, mid+1, ed, nums);
        return node;
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> nums;
        inorder(root, nums);
        int n = nums.size();
        TreeNode* node;
        return build(node, 0, n-1, nums);
    }
};