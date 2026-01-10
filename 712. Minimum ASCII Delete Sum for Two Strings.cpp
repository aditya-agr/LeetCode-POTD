class Solution {
public:
    int dp[1001][1001];
    int lcs(string &s, string &t, int i, int j){
        if(i==s.length() && j==t.length())
            return 0;
        if(i==s.length())
            return t[j] + lcs(s, t, i, j+1);
        if(j==t.length())
            return s[i] + lcs(s, t, i+1, j);
        if(dp[i][j] != -1)
            return dp[i][j];
        int take = INT_MAX;  
        if(s[i] == t[j])
            take = lcs(s, t, i+1, j+1);
        int notakei = s[i] + lcs(s, t, i+1, j);
        int notakej = t[j] + lcs(s, t, i, j+1);
        return dp[i][j] = min({take, notakei, notakej});   
    }
    int minimumDeleteSum(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        memset(dp, -1, sizeof(dp));
        return lcs(s1, s2, 0 , 0);
    }
};