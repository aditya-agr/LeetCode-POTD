class Solution {
public:
    int solve(int i, int m, vector<int>& piles, vector<vector<int>>& dp){
        int n = piles.size();
        if(i+2*m >= n)
            return piles[i];

        if(dp[i][m] != -1)
            return dp[i][m];

        int best = 0;
        for(int x=1; x<=2*m && i+x<=n; x++){
            int m_ = max(m, x);
            int cur = piles[i] - solve(i+x, m_, piles, dp);
            best = max(best, cur);
        }
        return dp[i][m] = best;
    }
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        vector<vector<int>> dp(n, vector<int>(2*n, -1));
        for(int i=n-2; i>=0; i--)
            piles[i] += piles[i+1];
        return solve(0, 1, piles, dp);
    }
};