class Solution {
public:
    int distinctSubseqII(string s) {
        long long res = 0, prev = 0;
        long long mod = 1e9+7;
        vector<long long> dp(26);
        for(char c : s){
            long long newc = (res + 1 - dp[c-'a'] + mod)%mod;
            res = (res + newc)%mod;
            dp[c-'a'] = (dp[c-'a'] + newc)%mod;
        }
        return res;
    }
};