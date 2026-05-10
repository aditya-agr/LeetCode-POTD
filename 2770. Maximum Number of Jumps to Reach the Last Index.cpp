class Solution {
public:
    int solve(int i, vector<int>& nums, int &target, vector<int> &dp){
        int n = nums.size();
        if(i == n-1)
            return 0;
        if(dp[i] != -2)
            return dp[i];
        int res = -1;
        for(int j=i+1; j<n; j++){
            if(abs(nums[i]-nums[j]) <= target){
                int cur = solve(j, nums, target, dp);
                if(cur != -1)
                    res = max(res, 1+cur);
            }
        }
        return dp[i] = res;
    }
    int maximumJumps(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> dp(n, -2);
        return solve(0, nums, target, dp);
    }
};