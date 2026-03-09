class Solution {
public:
    int mod = 1e9+7;
    int dp[201][201][2];
    int solve(int zero, int one, bool flag, int limit){
        if(zero==0 && one==0)
            return 1;
        if(dp[zero][one][flag] != -1)
            return dp[zero][one][flag];
        int res = 0;
        if(flag){
            for(int len=1; len<=min(zero,limit); len++)
                res = (res+solve(zero-len, one, false, limit))%mod;
        }
        else{
            for(int len=1; len<=min(one,limit); len++)
                res = (res+solve(zero, one-len, true, limit))%mod;
        }
        return dp[zero][one][flag] = res;
    }
    int numberOfStableArrays(int zero, int one, int limit) {
        memset(dp, -1, sizeof(dp));
        int res = 0;
        res += solve(zero, one, true, limit);
        res %= mod;
        res += solve(zero, one, false, limit);
        res %= mod;
        return res;
    }
};