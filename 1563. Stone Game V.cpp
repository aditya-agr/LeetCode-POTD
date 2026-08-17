class Solution {
public:
    int solve(int st, int ed, vector<int> &stones, vector<vector<int>> &dp, vector<int> &prefix){
        if(st == ed)
            return 0;
        if(dp[st][ed] != -1)
            return dp[st][ed];

        int tot = prefix[ed+1]-prefix[st];
        
        int res = 0, cur = 0;
        for(int i=st; i<ed; i++){
            cur += stones[i];
            if(cur <= tot-cur)
                res = max(res, cur+solve(st, i, stones, dp, prefix));
            if(cur >= tot-cur)
                res = max(res, (tot-cur)+solve(i+1, ed, stones, dp, prefix));
        }
        return dp[st][ed] = res;
    }
    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<int> prefix(n+1);
        for(int i=1; i<=n; i++)
            prefix[i] = prefix[i-1] + stoneValue[i-1];
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return solve(0, n-1, stoneValue, dp, prefix);
    }
};