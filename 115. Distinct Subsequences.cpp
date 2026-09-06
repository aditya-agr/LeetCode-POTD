class Solution {
public:
    int n, m;
    int solve(int i, int j, string &s, string &t, vector<vector<int>> &dp){
        if(j == m)
            return 1;
        if(i == n)
            return 0;
        if(dp[i][j] != -1)
            return dp[i][j];
        int res = 0;
        if(s[i] == t[j])
            res += solve(i+1, j+1, s, t, dp);
        res += solve(i+1, j, s, t, dp);
        
        return dp[i][j] = res;
    }
    int numDistinct(string s, string t) {
        n = s.size();
        m = t.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return solve(0, 0, s, t, dp);
    }
};