class Solution {
public:
    int mod = 1e9+7;
    int solve(int &low, int &high, int &zero, int &one, int len, vector<int> &dp){
        if(len > high)
            return 0;
        if(dp[len] != -1)
            return dp[len];
        bool addOne = false;
        if(len >= low && len <= high)
            addOne = true;
        int addzero = solve(low, high, zero, one, len+zero, dp);
        int addone = solve(low, high, zero, one, len+one, dp);
        return dp[len] = (addOne + addzero + addone)%mod;

    }
    int countGoodStrings(int low, int high, int zero, int one) {
        vector<int> dp(high+1, -1);
        return solve(low, high, zero, one, 0, dp);
    }
};