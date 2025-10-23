class Solution {
public:
    bool hasSameDigits(string s) {
        int n = s.length();
        vector<int> dp(n);
        for(int i=0; i<n; i++)
            dp[i] = s[i]-'0';
        
        for(int i=n-1; i>1; i--){
            for(int j=0; j<i; j++)
                dp[j] = (dp[j]+dp[j+1])%10;
        }
        return dp[0]==dp[1];
    }
};