class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int mx=0;
        for(int x : nums)
            mx |= x;
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int>(4*mx+1));
        dp[n][mx] = 1;
        for(int i=n-1; i>=0; i--){
            for(int curr=mx; curr>=0; curr--){
                dp[i][curr] = dp[i+1][curr] + dp[i+1][curr|nums[i]];
            }
        }
        return dp[0][0];
    }
};