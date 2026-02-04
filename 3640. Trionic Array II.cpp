class Solution {
public:
    vector<vector<long long>> dp;
    long long solve(int i, int trend, vector<int> &nums){
        int n = nums.size();
        if(i == n){
            if(trend == 3)
                return 0;
            else
                return LLONG_MIN/2;
        }
        if(dp[i][trend] != LLONG_MIN)
            return dp[i][trend];
        long long skip=LLONG_MIN/2, take=LLONG_MIN/2;
        if(trend == 0)
            skip = solve(i+1, trend, nums);
        if(trend == 3)
            take = nums[i];

        if(i+1 < n){
            if(trend == 0){ 
                if(nums[i+1] > nums[i])
                    take = max(take, nums[i] + solve(i+1, 1, nums));
            }
            else if(trend == 1){
                if(nums[i+1] > nums[i])
                    take = max(take, nums[i] + solve(i+1, 1, nums));
                else if(nums[i+1] < nums[i])
                    take = max(take, nums[i] + solve(i+1, 2, nums));
            }
            else if(trend == 2){
                if(nums[i+1] < nums[i])
                    take = max(take, nums[i] + solve(i+1, 2, nums));
                else if(nums[i+1] > nums[i])
                    take = max(take, nums[i] + solve(i+1, 3, nums));
            }
            else if(trend == 3){
                if(nums[i+1] > nums[i])
                    take = max(take, nums[i] + solve(i+1, 3, nums));
            }
        }
        return dp[i][trend] = max(skip, take);
    }
    long long maxSumTrionic(vector<int>& nums) {
        int trend = 0;
        int n = nums.size();
        dp.resize(n+1, vector<long long>(4, LLONG_MIN));
        return solve(0, trend, nums);
    }
};