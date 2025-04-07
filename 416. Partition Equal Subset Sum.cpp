class Solution {
public:
    int dp[201][20001];
    bool solve(vector<int> &nums, int i, int sum){
        if(sum == 0)
            return true;
        if(i == nums.size())
            return false;
        if(dp[i][sum] != -1)
            return dp[i][sum];
        bool take = false;
        if(sum >= nums[i])
            take = solve(nums, i+1, sum-nums[i]);
        bool notake = solve(nums, i+1, sum);
        return dp[i][sum] = take || notake;
    }
    bool canPartition(vector<int>& nums) {
        int S = accumulate(nums.begin(), nums.end(), 0);
        if(S%2)
            return false;
        
        int x = S/2;
        memset(dp, -1, sizeof(dp));
        return solve(nums, 0, x);
    }
};