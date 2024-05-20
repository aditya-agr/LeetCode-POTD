class Solution {
public:
    int solve(vector<int>& nums, int n, int idx, int curr){
        if(idx==n)
            return curr;
        int take = solve(nums, n, idx+1, nums[idx]^curr);
        int notake = solve(nums, n, idx+1, curr);
        return take+notake;
    }
    int subsetXORSum(vector<int>& nums) {
        int n = nums.size();
        return solve(nums, n, 0, 0);
    }
};