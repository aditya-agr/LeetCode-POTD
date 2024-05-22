class Solution {
public:
    void solve(vector<vector<int>> &res, vector<int> &curr, vector<int> &nums, int idx, int n){
        if(idx==n){
            res.push_back(curr);
            return;
        }
        curr.push_back(nums[idx]);
        solve(res, curr, nums, idx+1, n);
        curr.pop_back();
        solve(res, curr, nums, idx+1, n);
        
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> curr;
        int n=nums.size();
        solve(res, curr, nums, 0, n);
        return res;
    }
};